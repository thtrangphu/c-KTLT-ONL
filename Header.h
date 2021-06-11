#pragma once
#ifndef Header_h
#define  Header_h

#include <iostream>
using namespace std;

void Nhap(int**& a, int& m, int& n);
void Xuat(int** a, int m, int n);
int TongDuong(int** a, int m, int n);
bool SoNguyenTo(int x);
int DemNguyenTo(int** a, int m, int n);
int SoLonNhatBien(int** a, int m, int n);
int SoDuongNhoNhat(int** a, int m, int n);
void DongChuaSoAm(int** a, int m, int n);
void DongToanChan(int** a, int m, int n);
bool YenNgua(int** a, int m, int n, int dong, int cot);
bool HoangHau(int** a, int m, int n, int dong, int cot);
int DemYenNgua(int** a, int m, int n);
int DemHoangHau(int** a, int m, int n);
bool CucTri(int** a, int m, int n, int dong, int cot);
int TongCucTri(int** a, int m, int n);
void TachChuSo(int n, int b[]);
void ChuSoXuatHienNhieuNhat(int** a, int m, int n);
void SXBienTangDanKimDongHo(int** a, int m, int n);
void ViTriTiepTheo(int& i, int& j, int m, int n);
int menu();
void runMenu(int soLuaChon);

#endif //  Header_h
