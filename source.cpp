#include "Header.h"

void Nhap(int**&a, int&m, int&n)
{
	do {
		cout << "Nhap m: ";
		cin >> m;
	} while (m < 1);
	do {
		cout << "Nhap n: ";
		cin >> n;
	} while (n < 1);	
	
	a = new int* [m];
	for	(int i = 0; i < m; i++)
		a[i] = new int [n];
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "a[" << i << "][" << j << "]: "	;
			cin >> a[i][j];
		}
	}
}
void Xuat(int** a, int m, int n)
{
	cout << endl << "      ===  XUAT MANG  ===" << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}
int TongDuong(int** a, int m, int n)
{
	int tong = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] > 0) tong += a[i][j];
		}
	}
	return tong;
}
bool SoNguyenTo(int x) {
	if (x < 2) return 0;
	if (x > 2) {
		for (int i = 2; i <= sqrt(x); i++) {
			if (x % i == 0) return 0;
		}
	}
	return 1;
}
int DemNguyenTo(int** a, int m, int n)
{
	int dem = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (SoNguyenTo(a[i][j])) dem++;
		}
	}
	return dem;
}
int SoLonNhatBien(int** a, int m, int n)
{
	int max = INT_MIN;
	for (int j = 0; j < n; j++) {
		if (a[0][j] > max) max = a[0][j];
		if (a[m - 1][j] > max) max = a[m - 1][j];
	}
	for (int i = 1; i < m - 1; i++) {
		if (a[i][0] > max) max = a[i][0];
		if (a[i][n - 1] > max) max = a[i][n - 1];
	}
	return max;
}
int SoDuongNhoNhat(int** a, int m, int n)
{
	int min = INT_MAX;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] > 0 && a[i][j] < min) min = a[i][j];
		}
	}
	return min;
}
void DongChuaSoAm(int** a, int m, int n)
{
	bool check = false;
	cout << "\nCac dong chua gia tri am la: ";
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] < 0) {
				cout << i << "  ";
				check = true;
				break;
			}
		}
	}
	if (check == false) cout << "khong co dong nao ca." << endl;
}
void DongToanChan(int** a, int m, int n)
{
	bool check1 = false;
	cout << "\nCac dong chua gia tri toan chan la: ";
	for (int i = 0; i < m; i++)
	{
		bool check = false;
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] % 2 !=0) {
				
				check = true;
				break;
			}

		}
		if (check == false) {
			cout << i << "  ";
			check1 = true;
		}
	}
	if (check1 == false) cout << "khong co dong nao ca." << endl;
}

bool YenNgua(int** a, int m, int n, int dong, int cot) {
	int max = INT_MIN;
	int min = INT_MAX;
	for (int i = 0; i < n; i++) {
		if (a[i][cot] < min) min = a[i][cot];
	}
	for (int j = 0; j < m; j++) {
		if (a[dong][j] > max) max = a[dong][j];
	}
	if (a[dong][cot] == max && a[dong][cot] == min) return 1;
	return 0;
}
bool HoangHau(int** a, int m, int n, int dong, int cot) {
	for (int i = 0; i < n; i++)
	{
		if (a[dong][i] > a[dong][cot])
		{
			return false;
		}
	}
	for (int j = 0; j < m; j++)
	{
		if (a[j][cot] > a[dong][cot])
		{
			return false;
		}
	}
	int dong1 = dong + 1;
	int cot1 = cot + 1;
	while (cot1 + 1 < n && dong1 < m)
	{
		if (a[cot1][dong1] > a[dong][cot])
			return false;
		cot1++;
		dong1++;
	}
	dong1 = dong - 1;
	cot1 = cot - 1;
	while (cot1 - 1 >= 0 && dong1 >= 0)
	{
		if (a[cot1][dong1] > a[dong][cot])
			return false;
		cot1--;
		dong1--;
	}
	dong1 = dong + 1;
	cot1 = cot - 1;
	while (cot1 - 1 >= 0 && dong1 < m)
	{
		if (a[cot1][dong1] > a[dong][cot])
			return false;
		dong1++;
		cot1--;
	}
	dong1 = dong - 1;
	cot1 = cot + 1;
	while (dong1 - 1 >= 0 && cot1 < n)
	{
		if (a[cot1][dong1] > a[dong][cot])
			return false;
		dong1--;
		cot1++;
	}
	return true;
}
int DemYenNgua(int** a, int m, int n) {
	int dem = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (YenNgua(a,m,n,i,j)) {
				dem++;
			}
		}
	}
	return dem;
}
int DemHoangHau(int** a, int m, int n) {
	int dem = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (HoangHau(a, m, n, i, j)) {
				dem++;
			}
		}
	}
	return dem;
}
bool CucTri(int **a, int m, int n, int dong, int cot) {
	bool CucDai = true, CucTieu = true;
	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			// !(i=0 & j=0) khác a[dong][cot]
			if (dong + i >= 0 && cot + j >= 0 && dong + i < m && cot + j < n && !(i == 0 && j == 0))
			{
				if (a[dong][cot] <= a[dong + i][cot + j]) CucDai = false;
				if (a[dong][cot] >= a[dong + i][cot + j]) CucTieu = false;
				if (!CucDai && !CucTieu) return false;
			}
		}
	}
	return true;
}
int TongCucTri(int** a, int m, int n)
{
	int tong = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (CucTri(a, m, n, i, j)) tong += a[i][j];
		}
	}
	return tong;
}
void TachChuSo(int n, int b[])
{
	int ChuSo;
	n = abs(n);
	do
	{
		ChuSo = n % 10;
		b[ChuSo]++;
		n /= 10;
	} while (n > 0);
}
void ChuSoXuatHienNhieuNhat(int** a, int m, int n)
{
	int b[10] = { 0 };
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			TachChuSo(a[i][j], b);
		}
	}
	int ChuSoXuatHienNhieuNhat = 0;
	for (int i = 0; i < 10; i++)
	{
		if (b[ChuSoXuatHienNhieuNhat] < b[i])
		{
			ChuSoXuatHienNhieuNhat = i;
		}
	}
	cout<<"\nCac chu so xuat hien nhieu nhat: ";
	for (int i = 0; i < 10; i++)
	{
		if (b[ChuSoXuatHienNhieuNhat] == b[i])
		{
			cout << i << "  ";
		}
	}
}
void SXBienTangDanKimDongHo(int** a, int m, int n)
{
	int i = 0, j = 0;
	do {
		int x = i; int y = j;
		ViTriTiepTheo(x, y, m, n);
		do {
			if (x == 0 && y == 0) break;
			if (a[i][j] > a[x][y]) 
			{ 
				int temp = a[x][y];
				a[x][y] = a[i][j];
				a[i][j] = temp; 
			}
			ViTriTiepTheo(x, y, m, n);
		} while (!(x == y && y == 0));
		ViTriTiepTheo(i, j, m, n);
	} while (!(i == j && j == 0));
	Xuat(a, m, n);
}
void ViTriTiepTheo(int& i, int& j, int m, int n) {
	if (i + j == j && j < n - 1) { j++; return; } // hàng 0
	if (i + j == n - 1 + i && i < n - 1) { i++; return; } //
	if (i + j == n - 1 + j && j > 0) { j--; return; } //
	if (i + j == i && i > 0) { i--; return; } //
}
int menu() {
	cout << "0. Thoat" << endl;
	cout << "1.Nhap ma tran" << endl;
	cout << "2. Xuat ma tran" << endl;
	cout << "3. Tong cac phan tu duong trong ma tran" << endl;
	cout << "4. Dem so luong so nguyen to trong ma tran" << endl;
	cout << "5. Tim so lon nhat tren bien ma tran" << endl;
	cout << "6. Tim so duong nho nhat trong ma tran " << endl;
	cout << "7. Liet ke cac dong chua gia tri am trong ma tran" << endl;
	cout << "8. Liet ke cac dong chua toan so chan trong ma tran" << endl;
	cout << "9. Dem gia tri yen ngua" << endl;
	cout << "10. Dem gia tri hoang hau" << endl;
	cout << "11. Tong cac phan tu cuc tri" << endl;
	cout << "12. Tim chu so xuat hien nhieu nhat" << endl;
	cout << "13. Sap xep bien tang dan theo chieu kim dong ho" << endl;
	return 13;
}
void menu(int soLuaChon) {
	int lc;
	int** a = NULL;
	int m=0;
	int n = 0;
	while (1) {
		system("cls");
		menu();
		cout << "MOI BAN NHAP LUA CHON: ";
		do {
			cin >> lc;
			if (lc<0 || lc>soLuaChon) cout << "Nhap sai lua chon !!! Moi ban nhap lai..." << endl;
		} while (lc<0 || lc>soLuaChon);
		system("cls");
		switch (lc)
		{
		case 1: {
			cout << "1.Nhap ma tran" << endl;
			Nhap(a, m, n);
			break;
		}
		case 2: {
			cout << "2. Xuat ma tran" << endl;
			Xuat(a, m, n);
			break;
		}
		case 3: {
			cout << "3. Tong cac phan tu duong trong ma tran" << endl;
			cout << "Ket qua la: " << TongDuong(a, m, n) << endl;
			break;
		}
		case 4: {
			cout << "4. Dem so luong so nguyen to trong ma tran" << endl;
			cout << "Ket qua la: " << DemNguyenTo(a, m, n) << endl;
			break;
		}
		case 5: {
			cout << "5. Tim so lon nhat tren bien ma tran" << endl;
			cout << "Ket qua la: " << SoLonNhatBien(a, m, n) << endl;
			break;
		}
		case 6: {
			cout << "6. Tim so duong nho nhat trong ma tran " << endl;
			cout << "Ket qua la: " << SoDuongNhoNhat(a, m, n) << endl;
			break;
		}
		case 7: {
			cout << "7. Liet ke cac dong chua gia tri am trong ma tran" << endl;
			DongChuaSoAm(a, m, n);
			break;
		}
		case 8: {
			cout << "8. Liet ke cac dong chua toan so chan trong ma tran" << endl;
			DongToanChan(a, m, n);
			break;
		}
		case 9: {
			cout << "9. Dem gia tri yen ngua" << endl;
			cout << "Ket qua la: " << DemYenNgua(a, m, n) << endl;
			break;
		}
		case 10: {
			cout << "10. Dem gia tri hoang hau" << endl;
			cout << "Ket qua la: " << DemHoangHau(a, m, n) << endl;
			break;
		}
		case 11: {
			cout << "11. Tong cac phan tu cuc tri" << endl;
			cout << "Ket qua la: " << TongCucTri(a, m, n) << endl;

			break;
		}
		case 12: {
			cout << "12. Tim chu so xuat hien nhieu nhat" << endl;
			ChuSoXuatHienNhieuNhat(a, m, n);
			break;
		}
		case 13: {
			cout << "13. Sap xep bien tang dan theo chieu kim dong ho" << endl;
			SXBienTangDanKimDongHo(a, m, n);
			break;
		}
		default:
			exit(0);
		}
		system("pause");
	}
}
