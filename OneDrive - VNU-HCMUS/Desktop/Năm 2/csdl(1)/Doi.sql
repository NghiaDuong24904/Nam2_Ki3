CREATE DATABASE Qly_Doi
GO 

USE Qly_Doi
GO

CREATE TABLE DOI
(
	IDDoi int PRIMARY KEY,
	TenDoi nvarchar(30),
	DoiTruong int,
	Soluong int
)

CREATE TABLE BOTRI
(
	IDDoi int,
	IDThanhVien int,
	DiaChi nvarchar(50),
	NhiemVu nvarchar(30),
	QuanLi int,
	CONSTRAINT PK_BOTRI PRIMARY KEY (IDDoi,IDThanhVien)
)

CREATE TABLE THANHVIEN
(
	IDThanhVien int PRIMARY KEY,
	HoTen nvarchar(30),
	SoCMND varchar(9),
	DiaChi nvarchar(50),
	NgaySinh date,
)

ALTER TABLE BOTRI
ADD CONSTRAINT FK_BT_D
FOREIGN KEY (IDDoi)
REFERENCES DOI(IDDoi)

ALTER TABLE BOTRI
ADD CONSTRAINT FK_BT_TV
FOREIGN KEY (IDThanhVien)
REFERENCES THANHVIEN(IDThanhVien)

ALTER TABLE DOI
ADD CONSTRAINT FK_D_TV
FOREIGN KEY (DoiTruong)
REFERENCES THANHVIEN(IDThanhVien)

ALTER TABLE BOTRI
ADD CONSTRAINT FK_BT_QL
FOREIGN KEY (QuanLi)
REFERENCES THANHVIEN(IDThanhVien)

INSERT INTO DOI(IDDoi,TenDoi)
VALUES (2,N'Đội Tân Phú'),
(7,N'Đội Bình Phú');

INSERT INTO THANHVIEN(IDThanhVien,HoTen,SoCMND,DiaChi,NgaySinh)
VALUES (1,N'Nguyễn Quan Tùng','240674018',N'TPHCM','2000-01-30'),
(2,N'Lưu Phi Nam','240674027',N'Quảng Nam','2001-03-12'),
(3,N'Lê Quang Bảo','240674063',N'Quảng Ngãi','1999-05-14'),
(4,N'Hà Ngọc Thúy','240674504',N'TPHCM','1998-07-26'),
(5,N'Trương Thị Minh','240674405',N'Hà Nội',NULL),
(6,N'Ngô Thị Thủy','240674306',NULL,'2000-09-18');

INSERT INTO BOTRI(IDDoi,IDThanhVien,DiaChi,NhiemVu,QuanLi)
VALUES (2,2,N'123 Vườn Lài Tân Phú',N'Trực khu vực vòng xoay 1',1),
(2,1,N'45 Phú Thọ Hòa Tân Phú',N'Theo dõi hoạt động',1),
(7,3,N'11 Chợ lớn Bình Phú',NULL,2),
(7,4,N'2 Bis Nguyễn Văn Cừ Q5',NULL,5);

UPDATE DOI SET DoiTruong = 1 WHERE IDDoi = 2;
UPDATE DOI SET DoiTruong = 2 WHERE IDDoi = 7;

SELECT DISTINCT d.TenDoi, tv.HoTen
FROM BOTRI bt LEFT JOIN DOI d ON bt.IDDoi = d.IDDoi
LEFT JOIN THANHVIEN tv ON d.DoiTruong = tv.IDThanhVien
WHERE bt.DiaChi LIKE N'%Tân Phú%'

SELECT tv.HoTen AS QuanLyTen, COUNT(bt.IDThanhVien) AS SoLuongThanhVien
FROM THANHVIEN tv
JOIN BOTRI bt ON tv.IDThanhVien = bt.QuanLi
JOIN THANHVIEN tv2 ON bt.IDThanhVien = tv2.IDThanhVien
WHERE tv2.NgaySinh IS NOT NULL
GROUP BY tv.HoTen;