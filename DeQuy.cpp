#include <iostream>
using namespace std;
int tongMu2(int n) {
	if (n == 1) return 1;
	return tongMu2(n - 1) + n * n;
}
float tongPhanSo(int n) {
	if (n == 1) return 1;
	return tongPhanSo(n - 1) + 1.0 / n;
}
float tongPhanSoChan(int n) {
	if (n == 1) return 0.5;
	return tongPhanSoChan(n - 1) + 1.0 / (2 * n);
}
int luyThuaMuChan(int n, int x) {
	if (n == 1) return pow(x,2);
	return luyThuaMuChan(n - 1,x) + pow(x, n * 2);

}
int fibonacci(int n) {
	if (n < 1) return 0;
	if (n == 1) return 1;
	if (n == 2) return 1;
	return fibonacci(n - 1) + fibonacci(n - 2);
}
int demSoChuSo(int n) {
	if (abs(n) < 10) return 1;
	return demSoChuSo(n / 10) + 1;
}
int tongCacChuSoChan(int n) {
	if (abs(n) < 10) {
		return ((n % 2 == 0) ? n : 0);
	}
	return tongCacChuSoChan(n / 10) + (((n % 10) % 2 == 0) ? (n % 10) : 0);
}
int chuSoDauTien(int n) {
	if (abs(n) < 10) return abs(n);
	return chuSoDauTien(n / 10);
}
int soDao(int n) {
	if (n < 10) return n;
	int x = (n % 10) * pow(10, int(log10(n)));
	return soDao(n / 10) + x;
}
int chuSoLonNhat(int n) {
	if (n < 10) return n;
	int max = chuSoLonNhat(n / 10);
	return (max > (n % 10)) ? max : n % 10;
}
bool soToanLe(int n) {
	if (n < 10 && n % 2 != 0) {
		return 1;
	}
	if (n % 2 == 0) {
		return 0;
	}
	else return soToanLe(n / 10);
}
bool check(int n) {
	if ((n % 10) % 2 == 0) {
		return false;
	}
	else if (n / 10 == 0 && n % 2 != 0) {
		return true;
	}
	n /= 10;
	return check(n);
}
void nhapMang(int* &a, int n) {
	for (int i = 0; i < n; i++) {
		cout << "Nhap phan tu thu " << i << " : ";
		cin >> a[i];
	}
}
void xuatMang(int* a, int n) {
	if (n == 0) return;
	xuatMang(a, n - 1);
	cout << a[n - 1]<<" ";
}
void xuatMangNguoc(int* a, int n) {
	if (n == 0) return;
	cout << a[n - 1] << " ";
	xuatMangNguoc(a, n - 1);
}
int soLonNhatTrongMang(int* a, int n) {
	if (n == 1) return a[n];
	int max = soLonNhatTrongMang(a,n-1);
	return (max > a[n]) ? max : a[n];
}

int kiemTraNguyenTo(int x, int i)
{
	if (x < 2) return 0;
	return (x == i) ? 1 : ((x % i == 0) ? 0 : kiemTraNguyenTo(x, i + 1));
}

int demSoNguyenTo(int *a, int n)
{
	return (n == 0) ? 0 : (kiemTraNguyenTo(a[n-1], 2) == 1) ? 1 + demSoNguyenTo(a, n-1) : demSoNguyenTo(a, n-1);
}
int demPhanBiet(int* a, int n) {
	if (n == 1) return 1;
}
bool soNguyenTo(int x, int i) {
	if (x < 2) return 0;
	
}
int demPhanBiet(int *a, int left, int right)
{
	if (left > right) return 0;
	for (int i = left + 1; i <= right; i++)
		if (a[left] == a[i]) return demPhanBiet(a, left + 1, right);
	return 1 + demPhanBiet(a, left + 1, right);
}
int dem(int* a, int n) {
	int d = 0;
	for (int i = 0; i < n; i++) {
		int dem = 0;
		for (int j = 0; j < i; j++) {
			if (a[i] == a[j]) dem++;
		}
		if (dem == 0) d += 1;
	}
	return d;
}
int main() {
	/*cout << tongMu2(3) << endl << tongPhanSo(3)<< endl<<tongPhanSoChan(3)<<endl<<luyThuaMuChan(3,2)<<endl<<fibonacci(4)<<endl;
	cout << demSoChuSo(54234123) << endl;
	cout << abs(tongCacChuSoChan(-232))<<endl;
	cout << chuSoDauTien(3423)<<endl;
	cout << soDao(12345) << endl;
	cout << chuSoLonNhat(125479324) << endl;
	cout << soToanLe(246);
	cout << check(11111111111125555555);*/
	int n;
	cout << "Nhap so luong phan tu mang: ";
	cin >> n;
	int *a = new int[n];
	nhapMang(a, n);
	cout << "Mang la: ";
	xuatMang(a, n);
	/*cout << "\nMang nguoc la: ";
	xuatMangNguoc(a, n);
	cout << "\nSo lon nhat trong mang la: "<<soLonNhatTrongMang(a, n);*/
	cout << endl<<dem;
}

