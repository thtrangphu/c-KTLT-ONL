#include <iostream>
#include <fstream>
using namespace std;
void capPhat(int*& p, int ncu, int nmoi)//tạo bản sao của p p'
{
	//B1: cho *tam giu nha cu
	int* tam = p;//NULL
	//B2: mua nha moi
	p = new int[nmoi];//thay đổi miền giá trị	//nmoi: xem coi cần mua mấy phòng
	//B3: chuyen do
	for (int i = 0; i < ncu; i++)//duyệt xem dời đồ ở bao nhiêu phòng
	{
		p[i] = tam[i];
	}
	//B4: ban nha
	if (tam != NULL)
	{
		delete[] tam;
	}
}
void docFile(int *&a, int& n) {
	ifstream f;
	f.open("input.txt", ios_base::in);
	if (f.fail()) {
		cout << "Khong mo duoc file !";
		return;
	}
	n = 0;
	while (!f.eof()) {
		capPhat(a, n, n + 1);
		f >> a[n];
		n++;
		if (f.eof()==true)
		{
			break;
		}
		f.seekg(1, 1);
	}
	f.close();
}
void nhapMang(int *& a, int& n) {
	cout << "Nhap so luong phan tu can them: ";
	int sl;
	cin >> sl;
	for (int i = 0; i < sl; i++) {
		cout << "Nhap phan tu thu " << n << ": ";
		capPhat(a, n, n + 1);
		cin >> a[n++];
	}
}

void xuatMang(int* a, int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}
void themPhanTu(int*& a, int& n, int vt, int x) {
	capPhat(a, n, n + 1);
	for (int i = n; i > vt; i--)
	{
		a[i] = a[i - 1];
	}
	a[vt] = x;
	n++;
}
void xoaPhanTu(int*& a, int& n, int vt)
{
	for (int i = vt; i < n - 1; i++)
	{
		a[i] = a[i + 1];
	}
	n--;
	capPhat(a, n, n);
}
bool kiemTraSoHoanThien(int x) {
	int s = 0;//khai bao biem sum
	for (int i = 1; i <= x / 2; i++) {
		if (x % i == 0)
			s += i;
	}
	if (s == x) return true; // tra ve true
	return false;
}
void them0TruocSoHoanThien(int*& a, int& n) {
	for (int i = 0; i < n; i++) {
		if (kiemTraSoHoanThien(a[i]) == true)
		{
			themPhanTu(a, n, i, 0);
			i++;
		}
	}
}
int soDaoNguoc(int n) {
	int temp = 0;
	while (n != 0)
	{
		temp = temp * 10 + (n % 10);
		n /= 10;
	}
	return temp;
}
bool kiemTraSoDoiXung(int x) {
	if (x == soDaoNguoc(x)) return true;
	return false;
}
void xoaSoDoiXung(int*& a, int& n) {
	for (int i = 0; i < n; i++) {
		if (kiemTraSoDoiXung(a[i]) == true)
		{
			xoaPhanTu(a, n, i);
			i--;
		}
	}
}
void inMangCon(int *a, int n)
{
	int j = 0, k = 1;
	while (j < n)
	{
		while (k <= n)
		{
			for (int i = j; i <= k - 1; i++)
			{
				cout << a[i] << " ";
			}
			cout << endl;
			k++;
		}
		j++;
		k = j + 1;
	}
}
bool kt(int xt, int x, int xp) {
	if ((x > xt && x < xp) || (x < xt && x > xp))
		return true;
	return false;
}
bool kiemTraMangGonSong(int* a, int n) {
	for (int i = 1; i < n - 1; i++) {
		if(kt(a[i-1],a[i],a[i+1])) return true;
	}
	return false;
}
void menu() {
	cout << "0.Load File\n1.Nhap\n2.Xuat\n3.Them phan tu x tai vt\n4.Xoa phan tu tai vt\n5.Them 0 truoc so hoan thien\n6.Xoa pt la so doi xung\n7.Liet ke all mang con" << endl;
	cout << "8.KT mang co la mang gon song" << endl;
	cout << "9.Thoat chuong trinh\n";
}
int main() {
	
	int n = 0;
	int *a = NULL;
	int lc;
	while (1) {
		system("cls");
		menu();
		do {
			cout << "Moi ban nhap lua chon: ";
			cin >> lc;
			if (lc < 0 || lc>9) cout << "Moi ban nhap lai!!!" << endl;
		} while (lc < 0 || lc>9);
		bool check = false;
		switch (lc)
		{
		case 0: {
			cout << "==================== LOAD FILE ====================" << endl;
			docFile(a, n);
			check = true;
			system("pause");
			break;
		}
		case 1: {
			cout << "============= NHAP DANH SACH SO NGUYEN =============" << endl;
			nhapMang(a, n);
			system("pause");
			break;
		}
		case 2: {
			cout << "============= XUAT DANH SACH SO NGUYEN =============" << endl;
			xuatMang(a, n);
			if (n == 0) {
				cout << "Khong co phan tu nao trong mang." << endl;
				system("pause");
				break;
			}

			system("pause");
			break;
		}
		case 3: {
			cout << "============ THEM PHAN TU X TAI VI TRI ============" << endl;
			int x;
			cout << "Moi ban nhap x can them: ";
			cin >> x;
			cout << "Moi ban nhap vi tri can them: ";
			int vt;
			do {
				cin >> vt;
				if (vt<0 || vt>n) cout << "Nhap vi tri khong hop le!!!! Moi ban nhap lai..." << endl;
			} while (vt<0 || vt>n);
			themPhanTu(a, n, vt, x);
			system("pause");
			break;
		}
		case 4: {
			cout << "============ XOA PHAN TU TAI VI TRI ============" << endl;
			cout << "Moi ban nhap vi tri can xoa: ";
			int vt;
			do {
				cin >> vt;
				if (vt<0 || vt>n) cout << "Nhap vi tri khong hop le!!!! Moi ban nhap lai..." << endl;
			} while (vt<0 || vt>n);
			xoaPhanTu(a, n, vt);
			system("pause");
			break;
		}
		case 5:
		{
			cout << "========= THEM SO 0 TRUOC SO HOAN THIEN =========" << endl;
			them0TruocSoHoanThien(a, n);
			system("pause");
			break;
		}
		case 6: {
			cout << "========== XOA PHAN TU LA SO DOI XUNG ===========" << endl;
			xoaSoDoiXung(a, n);
			system("pause");
			break;
		}
		case 7: {
			cout << "============ LIET KE TAT CA MANG CON ============" << endl;
			inMangCon(a, n);
			system("pause");
			break;
		}
		case 8: {
			cout << "============ KIEM TRA MANG GON SONG =============" << endl;
			if (kiemTraMangGonSong(a, n) == true) cout << "La mang gon song" << endl;
			else cout << "Khong la mang gon song :(" << endl;
			system("pause");
			break;
		}
		case 9: exit(0);
		}
	}
	
}
