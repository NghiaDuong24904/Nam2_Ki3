USE QL_DeTai

--Q1 Cho biết họ tên và mức lương của các giáo viên nữ.
SELECT HOTEN, LUONG
FROM GiAOVIEN gv
WHERE gv.PHAI = N'Nữ'
--Q2 Cho biết họ tên của các giáo viên và lương của họ sau khi tăng 10%.
SELECT HOTEN, LUONG * 1.1 AS LUONG_TANG
FROM GiAOVIEN
--Q3 Cho biết mã của các giáo viên có họ tên bắt đầu là “Nguyễn” và lương trên $2000 hoặc,giáo viên là trưởng bộ môn nhận chức sau năm 1995.
SELECT gv.MAGV
FROM GiAOVIEN gv LEFT JOIN BOMON bm ON gv.MABM = bm.MABM OR gv.MAGV = bm.TRUONGBM
WHERE (gv.HOTEN LIKE N'Nguyễn%' AND gv.LUONG > 2000) OR (bm.TRUONGBM = gv.MAGV AND YEAR(bm.NGAYNHAMCHUC)>1995)
--Q4 Cho biết tên những giáo viên khoa Công nghệ thông tin.
SELECT SUBSTRING(gv.HOTEN, LEN(gv.HOTEN) - CHARINDEX(' ', REVERSE(gv.HOTEN)) + 2, LEN(gv.HOTEN)) AS TEN
FROM GIAOVIEN gv JOIN BOMON bm ON gv.MABM = bm.MABM JOIN KHOA k ON bm.MAKHOA = k.MAKHOA
WHERE k.TENKHOA = N'Công nghệ thông tin';
--Q5 Cho biết thông tin của bộ môn cùng thông tin giảng viên làm trưởng bộ môn đó.
SELECT bm.*,gv.MAGV,gv.HOTEN,gv.PHAI,gv.NGSINH,gv.LUONG,gv.DIACHI,gv.GVQLCM
FROM BOMON bm LEFT JOIN GiAOVIEN gv ON bm.TRUONGBM = gv.MAGV
--Q6 Với mỗi giáo viên, hãy cho biết thông tin của bộ môn mà họ đang làm việc.
SELECT gv.MAGV,gv.HOTEN,bm.*
FROM GIAOVIEN gv LEFT JOIN BOMON bm ON gv.MABM = bm.MABM;
--Q7 Cho biết tên đề tài và giáo viên chủ nhiệm đề tài.
SELECT dt.TENDT, SUBSTRING(gv.HOTEN, LEN(gv.HOTEN) - CHARINDEX(' ', REVERSE(gv.HOTEN)) + 2, LEN(gv.HOTEN)) AS TEN
FROM DETAI dt LEFT JOIN GiAOVIEN gv ON dt.GVCNDT = gv.MAGV
--Q8 Với mỗi khoa cho biết thông tin trưởng khoa.
SELECT k.MAKHOA,k.TENKHOA,gv.*
FROM KHOA k LEFT JOIN GiAOVIEN gv ON k.TRUONGKHOA = gv.MAGV
--Q9 Cho biết các giáo viên của bộ môn “Vi sinh” có tham gia đề tài 006.
SELECT DISTINCT gv.*
FROM GiAOVIEN gv LEFT JOIN THAMGIADT tgdt ON gv.MAGV = tgdt.MAGV
WHERE MABM = 'VS' AND MADT = '006'
--Q10 Với những đề tài thuộc cấp quản lý “Thành phố”, cho biết mã đề tài, đề tài thuộc về chủ đề nào, họ tên người chủ nghiệm đề tài cùng với ngày sinh và địa chỉ của người ấy.
SELECT dt.MADT, dt.TENDT, gv.HOTEN, gv.NGSINH, gv.DIACHI
FROM DETAI dt JOIN GIAOVIEN gv ON dt.GVCNDT = gv.MAGV
WHERE dt.CAPQL = N'ĐHQG'
--Q11 Tìm họ tên của từng giáo viên và người phụ trách chuyên môn trực tiếp của giáo viên đó.
SELECT gv.HOTEN, gvqlcm.HOTEN as NGUOIPHUTRACH
FROM GiAOVIEN gv LEFT JOIN GiAOVIEN gvqlcm ON gv.GVQLCM = gvqlcm.MAGV
--Q12 Tìm họ tên của những giáo viên được “Nguyễn Thanh Tùng” phụ trách trực tiếp.
SELECT gv.HOTEN
FROM GiAOVIEN gv LEFT JOIN GiAOVIEN gvqlcm ON gv.GVQLCM = gvqlcm.MAGV
WHERE gvqlcm.HOTEN = N'Nguyễn Thanh Tùng'
--Q13 Cho biết tên giáo viên là trưởng bộ môn “Hệ thống thông tin”.
SELECT SUBSTRING(gv.HOTEN, LEN(gv.HOTEN) - CHARINDEX(' ', REVERSE(gv.HOTEN)) + 2, LEN(gv.HOTEN)) AS TEN
FROM GIAOVIEN gv JOIN BOMON bm ON gv.MABM = bm.MABM
WHERE bm.TENBM = N'Hệ thống thông tin'
--Q14 Cho biết tên người chủ nhiệm đề tài của những đề tài thuộc chủ đề Quản lý giáo dục.
SELECT dt.MADT,dt.TENDT,SUBSTRING(gvcndt.HOTEN, LEN(gvcndt.HOTEN) - CHARINDEX(' ', REVERSE(gvcndt.HOTEN)) + 2, LEN(gvcndt.HOTEN)) AS TEN
FROM DETAI dt JOIN CHUDE cd ON dt.MACD = cd.MACD JOIN GIAOVIEN gvcndt ON dt.GVCNDT = gvcndt.MAGV
WHERE cd.TENCD = N'Quản lý giáo dục'
--Q15 Cho biết tên các công việc của đề tài HTTT quản lý các trường ĐH có thời gian bắt đầu trong tháng 3/2008.
SELECT CV.TENCV
FROM CONGVIEC cv JOIN DETAI dt ON cv.MADT = dt.MADT
WHERE dt.TENDT = N'HTTT quản lý các trường ĐH' AND cv.NGAYBD BETWEEN '2008-03-01' AND '2008-03-31'
--Q16 Cho biết tên giáo viên và tên người quản lý chuyên môn của giáo viên đó.
SELECT SUBSTRING(gv.HOTEN, LEN(gv.HOTEN) - CHARINDEX(' ', REVERSE(gv.HOTEN)) + 2, LEN(gv.HOTEN)) AS GV, SUBSTRING(gvqlcm.HOTEN, LEN(gvqlcm.HOTEN) - CHARINDEX(' ', REVERSE(gvqlcm.HOTEN)) + 2, LEN(gvqlcm.HOTEN)) AS GVQLCM
FROM GIAOVIEN gv LEFT JOIN GiAOVIEN gvqlcm ON gv.GVQLCM = gvqlcm.MAGV
--Q17 Cho các công việc bắt đầu trong khoảng từ 01/01/2007 đến 01/08/2007.
SELECT cv.TENCV
FROM CONGVIEC cv
WHERE cv.NGAYBD BETWEEN '2007-01-01' AND '2007-08-01'
--Q18 Cho biết họ tên các giáo viên cùng bộ môn với giáo viên “Trần Trà Hương”.
SELECT gv2.HOTEN
FROM GiAOVIEN gv1 JOIN BOMON bm ON gv1.MABM = bm.MABM JOIN GIAOVIEN gv2 ON gv2.MABM = bm.MABM
WHERE gv1.HOTEN = N'Trần Trà Hương' AND gv2.HOTEN <> N'Trần Trà Hương'
--Q19 Tìm những giáo viên vừa là trưởng bộ môn vừa chủ nhiệm đề tài.
SELECT gv.*
FROM BOMON bm JOIN GiAOVIEN gv ON bm.TRUONGBM = gv.MAGV
INTERSECT
SELECT gv.*
FROM DETAI dt JOIN GiAOVIEN gv ON dt.GVCNDT = gv.MAGV
--Q20 Cho biết tên những giáo viên vừa là trưởng khoa và vừa là trưởng bộ môn.
SELECT SUBSTRING(gv.HOTEN, LEN(gv.HOTEN) - CHARINDEX(' ', REVERSE(gv.HOTEN)) + 2, LEN(gv.HOTEN)) AS TEN
FROM BOMON bm JOIN GiAOVIEN gv ON bm.TRUONGBM = gv.MAGV
INTERSECT
SELECT SUBSTRING(gv.HOTEN, LEN(gv.HOTEN) - CHARINDEX(' ', REVERSE(gv.HOTEN)) + 2, LEN(gv.HOTEN)) AS TEN
FROM KHOA k JOIN GIAOVIEN gv ON k.TRUONGKHOA = gv.MAGV
--Q21. Cho biết tên những trưởng bộ môn mà vừa chủ nhiệm đề tài.
SELECT SUBSTRING(gv.HOTEN, LEN(gv.HOTEN) - CHARINDEX(' ', REVERSE(gv.HOTEN)) + 2, LEN(gv.HOTEN)) AS TEN
FROM BOMON bm JOIN GiAOVIEN gv ON bm.TRUONGBM = gv.MAGV
INTERSECT
SELECT SUBSTRING(gv.HOTEN, LEN(gv.HOTEN) - CHARINDEX(' ', REVERSE(gv.HOTEN)) + 2, LEN(gv.HOTEN)) AS TEN
FROM DETAI dt JOIN GIAOVIEN gv ON dt.GVCNDT = gv.MAGV
--Q22 Cho biết mã số các trưởng khoa có chủ nhiệm đề tài.
SELECT gv.MAGV
FROM KHOA k JOIN GiAOVIEN gv ON k.TRUONGKHOA = gv.MAGV
INTERSECT
SELECT gv.MAGV
FROM DETAI dt JOIN GIAOVIEN gv ON dt.GVCNDT = gv.MAGV
--Q23 Cho biết mã số các giáo viên thuộc bộ môn “HTTT” hoặc có tham gia đề tài mã “001”.
SELECT gv.MAGV
FROM GiAOVIEN gv
WHERE gv.MABM = 'HTTT'
UNION
SELECT gv.MAGV
FROM GIAOVIEN gv JOIN THAMGIADT tgdt ON gv.MAGV = tgdt.MAGV
WHERE tgdt.MADT = '001'
--Q24 Cho biết giáo viên làm việc cùng bộ môn với giáo viên 002.
SELECT gv2.*
FROM GiAOVIEN gv1 JOIN BOMON bm ON gv1.MABM = bm.MABM JOIN GIAOVIEN gv2 ON gv2.MABM = bm.MABM
WHERE gv1.MAGV = '002' AND gv2.MAGV <> gv1.MAGV
--Q25 Tìm những giáo viên là trưởng bộ môn.
SELECT gv.*
FROM BOMON bm JOIN GiAOVIEN gv ON bm.TRUONGBM = gv.MAGV
ORDER BY gv.MAGV
--Q26 Cho biết họ tên và mức lương của các giáo viên.
SELECT gv.HOTEN, gv.LUONG
FROM GIAOVIEN gv