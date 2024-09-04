--Mã đề: 3
--MSSV: 22127293
--Họ và tên: DƯƠNG TRUNG NGHĨA
--Lớp: 22CLC05
USE SaleManagementDB
GO
--Câu 1: Cho danh sách quản lý (mã, họ tên, tên khu vực đang quản lý hiện tại, số lượng khu vực đã từng quản lý, số năm kinh nghiệm quản lý) có số năm quản lý lâu nhất.
SELECT MH.ManagerID, E.Fullname, SLG_KHUVUC.SLG_KHUVUC_TUNGQUANLY, R.RegionName, NAMNHONHAT.NHONHAT - NAMLONNHAT.LONNHAT AS SONAMKINHNGHIEM
FROM ManagerHistory MH JOIN Employee E ON E.EmployeeID = MH.ManagerID JOIN (
	SELECT mh.ManagerID, COUNT(mh.RegionID) AS SLG_KHUVUC_TUNGQUANLY
	FROM ManagerHistory mh
	GROUP BY mh.ManagerID
) AS SLG_KHUVUC ON SLG_KHUVUC.ManagerID = MH.ManagerID JOIN Region R ON R.RegionID = MH.RegionID
JOIN (SELECT MH1.ManagerID, YEAR(MH1.EndDate) AS NHONHAT
FROM ManagerHistory MH1 
WHERE YEAR(MH1.EndDate) >= ALL(SELECT YEAR(MH2.EndDate)
FROM ManagerHistory MH2
WHERE MH1.ManagerID = MH2.ManagerID)
) AS NAMNHONHAT ON MH.ManagerID = NAMNHONHAT.ManagerID
JOIN (SELECT MH1.ManagerID, YEAR(MH1.StartDate) AS LONNHAT
FROM ManagerHistory MH1 
WHERE YEAR(MH1.StartDate) <= ALL(SELECT YEAR(MH2.StartDate)
FROM ManagerHistory MH2
WHERE MH1.ManagerID = MH2.ManagerID)) AS NAMLONNHAT ON NAMLONNHAT.ManagerID = MH.ManagerID
WHERE MH.ManagerHistoryID IN (SELECT MH1.ManagerHistoryID
FROM ManagerHistory MH1 
WHERE YEAR(MH1.StartDate) >= ALL(SELECT YEAR(MH2.StartDate)
FROM ManagerHistory MH2
WHERE MH1.ManagerID = MH2.ManagerID))
ORDER BY MH.ManagerID
GO
--Câu 2: Viết thủ tục xuất danh sách các nhân viên (mã nhân viên, họ tên, số hợp đồng đã ký với khách hàng) đã làm việc ở tất cả các khu vực do nhân viên X quản lý (không dùng group by, having).
CREATE PROCEDURE sp_Xuatdanhsachcacnhanvien_lamviectatcakhuvucXquanly @ManagerID INT
AS
BEGIN
    DECLARE @Regions TABLE (RegionID INT);
    
    INSERT INTO @Regions
    SELECT RegionID
    FROM EmployeeRegion
    WHERE EmployeeID = @ManagerID;
    
    SELECT DISTINCT e.EmployeeID, e.FullName, 
    (SELECT COUNT(*) FROM Contract c WHERE c.EmployeeID = e.EmployeeID) AS NumberOfContracts
    FROM Employee e
    WHERE e.EmployeeID != @ManagerID AND NOT EXISTS (
        SELECT 1 
        FROM @Regions r
        WHERE NOT EXISTS (
            SELECT 1
            FROM EmployeeRegion er
            WHERE er.EmployeeID = e.EmployeeID
            AND er.RegionID = r.RegionID
        )
    )
END
GO
EXEC sp_Xuatdanhsachcacnhanvien_lamviectatcakhuvucXquanly 2;
GO
/*Câu 3: Viết thủ tục cho biết danh sách điều chuyển nhân sự dự kiến (mã nhân viên, họ
tên, tên khu vực đang làm việc, Số lượng hợp đồng đã ký, Số năm làm việc).
Biết rằng: đối tượng điều chuyển sẽ là:
• Các nhân viên đã làm việc trên 3 năm tại 1 region và chưa chuyển khu vực
công tác lần nào
• Các nhân viên chưa ký được hợp đồng nào với khách hàng*/
CREATE PROCEDURE sp_dieuchuyennhansu
AS
BEGIN
    SELECT e.EmployeeID, e.FullName, r.RegionName, 
           (SELECT COUNT(*) FROM Contract c WHERE c.EmployeeID = e.EmployeeID) AS NumberOfContracts, 
           DATEDIFF(YEAR, er.StartDate, ISNULL(er.EndDate, GETDATE())) AS YearsWorked
    FROM Employee e
    JOIN EmployeeRegion er ON e.EmployeeID = er.EmployeeID
    JOIN Region r ON er.RegionID = r.RegionID
    WHERE DATEDIFF(YEAR, er.StartDate, ISNULL(er.EndDate, GETDATE())) > 3
    AND er.EndDate IS NULL
    AND (SELECT COUNT(*) FROM EmployeeRegion er2 WHERE er2.EmployeeID = e.EmployeeID) = 1
    
    UNION
    
    SELECT e.EmployeeID, e.FullName, r.RegionName, 
           0 AS NumberOfContracts, 
           DATEDIFF(YEAR, er.StartDate, ISNULL(er.EndDate, GETDATE())) AS YearsWorked
    FROM Employee e
    JOIN EmployeeRegion er ON e.EmployeeID = er.EmployeeID
    JOIN Region r ON er.RegionID = r.RegionID
    WHERE NOT EXISTS (SELECT 1 FROM Contract c WHERE c.EmployeeID = e.EmployeeID);
END
GO
EXEC sp_dieuchuyennhansu
GO
