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
FROM GIAOVIEN gv
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
SELECT gv1.HOTEN AS N'Người già'
FROM GIAOVIEN gv1 JOIN BOMON bm ON gv1.MABM = bm.MABM
WHERE bm.TENBM = N'Hệ thống thông tin' AND gv1.NGSINH = (
	SELECT MIN(gv2.NGSINH)
	FROM GIAOVIEN gv2 JOIN BOMON bm ON gv2.MABM = bm.MABM
	WHERE bm.TENBM = N'Hệ thống thông tin'
)

-- Q39: Cho biết tên giáo viên nhỏ tuổi nhất khoa Công nghệ thông tin.
SELECT gv1.HOTEN AS N'Người trẻ'
FROM GIAOVIEN gv1 JOIN BOMON bm ON gv1.MABM = bm.MABM
JOIN KHOA k ON bm.MAKHOA = k.MAKHOA
WHERE k.TENKHOA = N'Công nghệ thông tin' AND gv1.NGSINH IN (
	SELECT MAX(gv2.NGSINH)
	FROM GIAOVIEN gv2 JOIN BOMON bm ON gv2.MABM = bm.MABM
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
FROM GIAOVIEN gv1
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
FROM DETAI dt JOIN GIAOVIEN gv ON dt.GVCNDT = gv.MAGV
WHERE dt.MADT NOT IN 
(
	SELECT tgdt.MADT
	FROM THAMGIADT tgdt, GIAOVIEN gv
	WHERE tgdt.MAGV=gv.MAGV AND gv.HOTEN = N'Nguyễn Hoài An'
)

-- Q44: Cho biết tên những giáo viên khoa Công nghệ thông tin mà chưa tham gia đề tài nào.
SELECT gv.HOTEN
FROM GIAOVIEN gv JOIN BOMON bm ON gv.MABM = bm.MABM
JOIN KHOA k ON bm.MAKHOA = k.MAKHOA
WHERE NOT EXISTS(
	SELECT 1
	FROM THAMGIADT tgdt
	WHERE gv.MAGV = tgdt.MAGV
) AND k.TENKHOA = N'Công nghệ thông tin'

-- Q45: Tìm những giáo viên không tham gia bất kỳ đề tài nào.
SELECT gv.*
FROM GIAOVIEN gv
WHERE NOT EXISTS (
	SELECT 1
	FROM THAMGIADT tgdt
	WHERE gv.MAGV = tgdt.MAGV
)
--Q46: Cho biết giáo viên có lương lớn hơn lương của giáo viên “Nguyễn Hoài An”
SELECT *
FROM GIAOVIEN
WHERE LUONG > 
(
	SELECT GV.LUONG 
	FROM GIAOVIEN GV
	WHERE GV.HOTEN = N'Nguyễn Hoài An'
)

--Q47: Tìm những trưởng bộ môn tham gia tối thiểu 1 đề tài
SELECT *
FROM GIAOVIEN GV
WHERE GV.MAGV IN 
(
	SELECT TG.MAGV
	FROM THAMGIADT TG
	WHERE GV.MAGV IN
	(
		SELECT BM.TRUONGBM
		FROM BOMON BM
	)
)

--Q48. Tìm giáo viên trùng tên và cùng giới tính với giáo viên khác trong cùng bộ môn
SELECT GV1.*
FROM GIAOVIEN GV1
WHERE EXISTS (
    SELECT 1
    FROM GIAOVIEN GV2
    WHERE GV1.HOTEN = GV2.HOTEN
      AND GV1.PHAI = GV2.PHAI
      AND GV1.MABM = GV2.MABM
      AND GV1.MAGV != GV2.MAGV
);
--Q49. Tìm những giáo viên có lương lớn hơn lương của ít nhất một giáo viên bộ môn “Công nghệ phần mềm”
SELECT *
FROM GIAOVIEN
WHERE LUONG > ANY
(
    SELECT GV.LUONG
    FROM GIAOVIEN GV
    JOIN BOMON BM ON GV.MABM = BM.MABM
    WHERE BM.TENBM = N'Công nghệ phần mềm'
);

--Q50. Tìm những giáo viên có lương lớn hơn lương của tất cả giáo viên thuộc bộ môn “Hệ thống thông tin”
SELECT *
FROM GIAOVIEN
WHERE LUONG > ALL
(
	SELECT GV.LUONG
	FROM GIAOVIEN GV, BOMON BM
	WHERE GV.MABM=BM.MABM AND BM.TENBM=N'Hệ thống thông tin'
)

--Q51. Cho biết tên khoa có đông giáo viên nhất
SELECT K.TENKHOA
FROM KHOA K
JOIN BOMON BM ON BM.MAKHOA = K.MAKHOA
JOIN GIAOVIEN GV ON GV.MABM = BM.MABM
GROUP BY K.TENKHOA
HAVING COUNT(DISTINCT GV.MAGV) >= ALL
(
    SELECT COUNT(DISTINCT GV1.MAGV)
    FROM KHOA K1
    JOIN BOMON BM1 ON BM1.MAKHOA = K1.MAKHOA
    JOIN GIAOVIEN GV1 ON GV1.MABM = BM1.MABM
    GROUP BY K1.MAKHOA
);

--Q52. Cho biết họ tên giáo viên chủ nhiệm nhiều đề tài nhất
SELECT GV.HOTEN
FROM GIAOVIEN GV
JOIN DETAI DT ON GV.MAGV = DT.GVCNDT
GROUP BY GV.HOTEN
HAVING COUNT(*) >= ALL
(
    SELECT COUNT(*)
    FROM GIAOVIEN GV1
    JOIN DETAI DT1 ON GV1.MAGV = DT1.GVCNDT
    GROUP BY GV1.MAGV
);


--Q53. Cho biết mã bộ môn có nhiều giáo viên nhất
SELECT MABM
FROM GIAOVIEN
GROUP BY MABM
HAVING COUNT(*) >= ALL
(
	SELECT COUNT(*)
	FROM GIAOVIEN
	GROUP BY MABM
)

--Q54. Cho biết tên giáo viên và tên bộ môn của giáo viên tham gia nhiều đề tài nhất.
SELECT GV.HOTEN, BM.TENBM
FROM GIAOVIEN GV, BOMON BM, THAMGIADT TG
WHERE GV.MABM=BM.MABM AND GV.MAGV=TG.MAGV
GROUP BY GV.HOTEN, BM.TENBM
HAVING COUNT(*) >= ALL
(
	SELECT COUNT(*)
	FROM GIAOVIEN GV1, THAMGIADT TG1
	WHERE TG1.MAGV=GV1.MAGV
	GROUP BY GV1.HOTEN
)

--Q55. Cho biết tên giáo viên tham gia nhiều đề tài nhất của bộ môn HTTT.
SELECT GV.HOTEN
FROM GIAOVIEN GV, THAMGIADT DT
WHERE GV.MAGV=DT.MAGV AND GV.MABM='HTTT'
GROUP BY GV.HOTEN
HAVING COUNT(*) >= ALL
(
	SELECT COUNT(*)
	FROM GIAOVIEN GV1, THAMGIADT TG1
	WHERE TG1.MAGV=GV1.MAGV
	GROUP BY GV1.MAGV
)

--Q56. Cho biết tên giáo viên và tên bộ môn của giáo viên có nhiều người thân nhất.
SELECT GV.HOTEN, BM.TENBM
FROM GIAOVIEN GV, BOMON BM, NGUOITHAN NT
WHERE GV.MABM=BM.MABM AND GV.MAGV=NT.MAGV
GROUP BY GV.HOTEN, BM.TENBM
HAVING COUNT(*) >= ALL
(
	SELECT COUNT(*)
	FROM GIAOVIEN GV1, NGUOITHAN NT1
	WHERE GV1.MAGV=NT1.MAGV
	GROUP BY GV1.MAGV
)

--Q57. Cho biết tên trưởng bộ môn mà chủ nhiệm nhiều đề tài nhất.
SELECT GV.HOTEN
FROM GIAOVIEN GV, DETAI DT, BOMON BM
WHERE GV.MAGV=DT.GVCNDT AND GV.MAGV=BM.TRUONGBM
GROUP BY GV.HOTEN
HAVING COUNT(*) >= ALL
(
	SELECT COUNT(*)
	FROM GIAOVIEN GV1, DETAI DT1
	WHERE GV1.MAGV=DT1.GVCNDT
	GROUP BY GV1.MAGV
)