USE QL_DeTai
GO

--Q35 Cho biết mức lương cao nhất của các giảng	viên.
SELECT DISTINCT gv1.LUONG AS N'Mức lương cao nhất'
FROM GIAOVIEN gv1
WHERE gv1.LUONG =
(
	SELECT MAX(gv2.LUONG)
	FROM GIAOVIEN gv2
)

-- Q36: Cho biết những giáo viên có lương lớn nhất.
SELECT gv.*
FROM GiAOVIEN gv
WHERE gv.LUONG = (
	SELECT MAX(gv.LUONG)
	FROM GIAOVIEN gv
)

-- Q37: Cho biết lương cao nhất trong bộ môn “HTTT”.
SELECT DISTINCT gv1.LUONG
FROM GIAOVIEN gv1
WHERE gv1.MABM = 'HTTT' AND gv1.LUONG >= ALL 
(
	SELECT gv2.LUONG
	FROM GIAOVIEN gv2
)

-- Q38: Cho biết tên giáo viên lớn tuổi nhất của bộ môn Hệ thống thông tin.
SELECT gv1.HOTEN
FROM GiAOVIEN gv1
WHERE YEAR(gv1.NGSINH) = (
	SELECT MIN(YEAR(gv2.NGSINH))
	FROM GIAOVIEN gv2 JOIN BOMON bm ON gv2.MABM = bm.MABM
	WHERE bm.TENBM = N'Hệ thống thông tin'
)

-- Q39: Cho biết tên giáo viên nhỏ tuổi nhất khoa Công nghệ thông tin.
SELECT gv1.HOTEN
FROM GIAOVIEN gv1
WHERE YEAR(gv1.NGSINH) IN (
	SELECT MAX(YEAR(gv2.NGSINH))
	FROM GiAOVIEN gv2 JOIN BOMON bm ON gv2.MABM = bm.MABM
	JOIN KHOA k ON bm.MAKHOA = k.MAKHOA
	WHERE k.TENKHOA = N'Công nghệ thông tin'
)

-- Q40: Cho biết tên giáo viên và tên khoa của giáo viên có lương cao nhất.
SELECT gv.HOTEN, k.TENKHOA
FROM GIAOVIEN gv JOIN BOMON bm ON gv.MABM = bm.MABM
JOIN KHOA k ON bm.MAKHOA = k.MAKHOA
WHERE gv.LUONG = (
	SELECT MAX(gv.LUONG)
	FROM GIAOVIEN gv
)

-- Q41: Cho biết những giáo viên có lương lớn nhất trong bộ môn của họ.
SELECT gv1.*
FROM GiAOVIEN gv1
WHERE gv1.LUONG = (
	SELECT MAX(gv2.LUONG)
	FROM GIAOVIEN gv2
	WHERE gv1.MABM = gv2.MABM
)
ORDER BY gv1.MAGV

-- Q42: Cho biết tên những đề tài mà giáo viên Nguyễn Hoài An chưa tham gia.
SELECT dt.TENDT
FROM DETAI dt
WHERE dt.MADT NOT IN 
(
	SELECT tgdt.MADT
	FROM THAMGIADT tgdt, GIAOVIEN gv
	WHERE tgdt.MAGV=gv.MAGV AND gv.HOTEN = N'Nguyễn Hoài An'
)

-- Q43: Cho biết những đề tài mà giáo viên Nguyễn Hoài An chưa tham gia. Xuất ra tên đề tài, tên người chủ nhiệm đề tài.
SELECT dt.TENDT, gv.HOTEN AS N'Chủ nhiệm đề tài'
FROM DETAI dt JOIN GiAOVIEN gv ON dt.GVCNDT = gv.MAGV
WHERE dt.MADT NOT IN 
(
	SELECT tgdt.MADT
	FROM THAMGIADT tgdt, GIAOVIEN gv
	WHERE tgdt.MAGV=gv.MAGV AND gv.HOTEN = N'Nguyễn Hoài An'
)

-- Q44: Cho biết tên những giáo viên khoa Công nghệ thông tin mà chưa tham gia đề tài nào.
SELECT gv.HOTEN
FROM GiAOVIEN gv JOIN BOMON bm ON gv.MABM = bm.MABM
JOIN KHOA k ON bm.MAKHOA = k.MAKHOA
WHERE NOT EXISTS(
	SELECT 1
	FROM THAMGIADT tgdt
	WHERE gv.MAGV = tgdt.MAGV
) AND k.TENKHOA = N'Công nghệ thông tin'

-- Q45: Tìm những giáo viên không tham gia bất kỳ đề tài nào.
SELECT gv.*
FROM GiAOVIEN gv
WHERE NOT EXISTS (
	SELECT 1
	FROM THAMGIADT tgdt
	WHERE gv.MAGV = tgdt.MAGV
)

-- Q46: Cho biết giáo viên có lương lớn hơn lương của giáo viên “Nguyễn Hoài An”.
SELECT gv1.*
FROM GiAOVIEN gv1
WHERE EXISTS(
	SELECT 1
	FROM GiAOVIEN gv2
	WHERE gv1.LUONG > gv2.LUONG AND gv2.HOTEN = N'Nguyễn Hoài An'
)

-- Q47: Tìm những trưởng bộ môn tham gia tối thiểu 1 đề tài.
SELECT *
FROM GIAOVIEN
WHERE MAGV IN (SELECT TRUONGBM FROM BOMON) AND MAGV IN (SELECT MAGV FROM THAMGIADT)

-- Q48: Tìm giáo viên trùng tên và cùng giới tính với giáo viên khác trong cùng bộ môn.
-- Q49: Tìm những giáo viên có lương lớn hơn lương của ít nhất một giáo viên bộ môn “Công nghệ phần mềm”.
