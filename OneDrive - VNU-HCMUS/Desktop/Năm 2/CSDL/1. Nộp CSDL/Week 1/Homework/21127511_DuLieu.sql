USE [QLBanHang]
GO
INSERT [dbo].[KHACH_HANG] ([makh], [hoten], [gioitinh], [dthoai], [diachi]) VALUES (N'KH001', N'Nguyễn Văn A', N'Nam', N'0911223345', N'H? Chí Minh')
INSERT [dbo].[KHACH_HANG] ([makh], [hoten], [gioitinh], [dthoai], [diachi]) VALUES (N'KH002', N'Nguyễn Văn B', N'Nam', N'0987654321', N'An Giang')
INSERT [dbo].[KHACH_HANG] ([makh], [hoten], [gioitinh], [dthoai], [diachi]) VALUES (N'KH003', N'Nguyễn Thị C', N'Nu', N'0989898989', N'Vung Tàu')
INSERT [dbo].[KHACH_HANG] ([makh], [hoten], [gioitinh], [dthoai], [diachi]) VALUES (N'KH004', N'Trần Văn E', N'Nam', N'0983232321', N'Phan Thi?t')
INSERT [dbo].[KHACH_HANG] ([makh], [hoten], [gioitinh], [dthoai], [diachi]) VALUES (N'KH005', N'Trần Thị D', N'Nu', N'0390888877', N'Long An')
GO
INSERT [dbo].[HOA_DON] ([mahd], [ngaylap], [makh]) VALUES (N'HD001', CAST(N'2023-05-05' AS Date), N'KH002')
INSERT [dbo].[HOA_DON] ([mahd], [ngaylap], [makh]) VALUES (N'HD002', CAST(N'2023-06-04' AS Date), N'KH003')
INSERT [dbo].[HOA_DON] ([mahd], [ngaylap], [makh]) VALUES (N'HD003', CAST(N'2023-04-04' AS Date), N'KH005')
INSERT [dbo].[HOA_DON] ([mahd], [ngaylap], [makh]) VALUES (N'HD004', CAST(N'2023-04-01' AS Date), N'KH001')
INSERT [dbo].[HOA_DON] ([mahd], [ngaylap], [makh]) VALUES (N'HD005', CAST(N'2023-02-28' AS Date), N'KH004')
GO
INSERT [dbo].[SAN_PHAM] ([masp], [tensp], [ngaysx], [dongia]) VALUES (N'SP001', N'Tủ lạnh', CAST(N'2023-01-25' AS Date), 10000000.0000)
INSERT [dbo].[SAN_PHAM] ([masp], [tensp], [ngaysx], [dongia]) VALUES (N'SP002', N'Máy giặt', CAST(N'2022-12-30' AS Date), 5000000.0000)
INSERT [dbo].[SAN_PHAM] ([masp], [tensp], [ngaysx], [dongia]) VALUES (N'SP003', N'Máy lạnh', CAST(N'2021-06-06' AS Date), 7000000.0000)
INSERT [dbo].[SAN_PHAM] ([masp], [tensp], [ngaysx], [dongia]) VALUES (N'SP004', N'Điện thoại', CAST(N'2022-05-05' AS Date), 15000000.0000)
INSERT [dbo].[SAN_PHAM] ([masp], [tensp], [ngaysx], [dongia]) VALUES (N'SP005', N'Laptop', CAST(N'2023-02-20' AS Date), 24000000.0000)
GO
INSERT [dbo].[CT_HOA_DON] ([mahd], [masp], [soluong], [dongia]) VALUES (N'HD001', N'SP001', 2, 10000000.0000)
INSERT [dbo].[CT_HOA_DON] ([mahd], [masp], [soluong], [dongia]) VALUES (N'HD002', N'SP002', 3, 5000000.0000)
INSERT [dbo].[CT_HOA_DON] ([mahd], [masp], [soluong], [dongia]) VALUES (N'HD003', N'SP004', 5, 13000000.0000)
INSERT [dbo].[CT_HOA_DON] ([mahd], [masp], [soluong], [dongia]) VALUES (N'HD004', N'SP005', 1, 12500000.0000)
INSERT [dbo].[CT_HOA_DON] ([mahd], [masp], [soluong], [dongia]) VALUES (N'HD005', N'SP003', 4, 5430000.0000)
GO
