--mssv: 21127511
--malop: 21CLC02


-- switch db to 'master'
use master
go

--check if DB is exist
PRINT DB_ID('QLDTAI')
--b1: tạo csdl
-- KIỂM TRA DB QLDTAI ĐÃ TỒN TẠI CHƯA
IF DB_ID('QLDTAI') IS NOT NULL 
	DROP database QLDTAI
go 
-- create database
create database QLDTAI
go 
-- switch DB
USE QLDTAI
go 
create table GIAOVIEN
(
    MAGV char(5),
    HOTEN nvarchar(40), 
    LUONG float, 
    PHAI nvarchar(10), 
    NGSINH datetime, 
    DIACHI nvarchar(100), 
    GVQLCM char(5), 
    MABM nchar(5)

	Constraint PK_GV
	Primary key (MAGV),
	Constraint C_Giaovien_Phai
	Check (PHAI in ('Nam', 'Nu'))
)
create table GV_DT (
    MAGV char(5), 
    DIENTHOAI char(12),

	Constraint PK_GV_DT
	Primary key (MAGV, DIENTHOAI)
)

create table BOMON (
    MABM nchar(5),
    TENBM nvarchar(40),
    PHONG char(5),
    DIENTHOAI char(12), 
    TRUONGBM char(5), 
    MAKHOA char(4),
    NGAYNHANCHUC date,

	Constraint PK_BOMON
	Primary key (MABM)
)
create table KHOA (
    MAKHOA char(4), 
    TENKHOA nvarchar(40), 
    NAMTL int, 
    PHONG char(5), 
    DIENTHOAI char(12),
    TRUONGKHOA char(5), 
    NGAYNHANCHUC date,

	Constraint PK_KHOA
	Primary key (MAKHOA)
)

create table DETAI (
    MADT char(3), 
    TENDT nvarchar(100), 
    CAPQL nvarchar(40), 
    KINHPHI float, 
    NGAYBD date, 
    NGAYKT date,
    MACD nchar(4),
    GVCNDT char(5),

	Constraint PK_DETAI
	Primary key (MADT)
)

create table CHUDE( 
    MACD nchar(4), 
    TENCD nvarchar(50),

	Constraint PK_CHUDE
	Primary key (MACD)
)
create table CONGVIEC( 
    MADT char(3), 
    SOTT int, 
    TENCV nvarchar(40), 
    NGAYBD date, 
    NGAYKT date,

	Constraint PK_CONGVIEC
	Primary key (MADT, SOTT)
)

create table THAMGIADT (
    MAGV char(5), 
    MADT char(3), 
    STT int, 
    PHUCAP float , 
    KETQUA nvarchar(40),
)

create table NGUOITHAN (
    MAGV char(5), 
    TEN nvarchar(20), 
    NGSINH date, 
    PHAI nchar(3),

	Constraint PK_NGUOITHAN
	Primary key (MAGV, TEN)
)


--B2: TẠO KHÓA NGOẠI
ALter table GIAOVIEN
ADD
	Constraint FK_GV_GV
	Foreign key (GVQLCM)
	References GIAOVIEN,

	Constraint FK_GV_BM
	Foreign key (MABM)
	References BOMON

Alter table BOMON
ADD
	Constraint FK_BM_GV
	Foreign key (TRUONGBM)
	References GIAOVIEN,

	Constraint FK_BM_KHOA
	Foreign key (MAKHOA)
	References KHOA

Alter table KHOA
ADD
	Constraint FK_KHOA_GV
	Foreign key (TRUONGKHOA)
	References GIAOVIEN

ALter table THAMGIADT
ADD
	Constraint FK_THAMGIADT_GV
	Foreign key (MAGV)
	References GIAOVIEN,

	Constraint FK_THAMGIADT_CONGVIEC
	Foreign key (MADT, STT)
	References CONGVIEC

Alter table CONGVIEC
ADD
	Constraint FK_CONGVIEC_DETAI
	Foreign key (MADT)
	References DETAI

Alter table DETAI
ADD
	Constraint FK_DETAI_GIAOVIEN
	Foreign key (GVCNDT)
	References GIAOVIEN,

	Constraint FK_DETAI_CHUDE
	Foreign key (MACD)
	References CHUDE

Alter table NGUOITHAN
ADD
	Constraint FK_NGUOITHAN_GIAOVIEN
	Foreign key (MAGV)
	References GIAOVIEN

ALter table GV_DT
ADD
	Constraint FK_GVDT_GIAOVIEN
	Foreign key (MAGV)
	References GIAOVIEN


-- B4: NHẬP LIỆU
-- THỨ TỰ NHẬP LIỆU: KHOA (TRƯỞNG KHOA = NULL) -> BOMON (TRUONGBM = NULL) -> GV
INSERT KHOA (MAKHOA, TENKHOA, NAMTL, PHONG, DIENTHOAI, NGAYNHANCHUC)
VALUES ('CNTT', N'CÔNG NGHỆ THÔNG TIN', 1995, 'B11', '0838123456', '02-20-2002'), ('HH', N'HÓA HỌC', 1980, 'B41', 0838456456, '10-15-2001')