#include <iostream>
using namespace std;

//In tam giac Pascal canh N
void InDong(int *&a,int *&b, int n) {
	if (n == 1) {
		//Chieu cao = 1
		a[n - 1] = 1;
		cout << a[n - 1] << endl;
		return;
	}
	else if (n == 2) {
		a[n - 1] = 1;
		InDong(a, b, n - 1);
		XuatMang(a, n);
	}
	else {
		//n>2
		b[0] = b[1] = 1;
		InDong(a, b, n - 1);
		int i =0;
		i++;
		Them(a, n, i, a[i - 1] + a[i]);
		XuatMang(a, n);
		int temp = 0;
		if(i!=(n-1))for (int j = n - 1; j >= i; j--) a[j] = a[temp];
		XuatMang(a, n);
	}
}
//void InTamGiacPascal(int *&a, int n) {
//	if (n == 0) return;
//	InTamGiacPascal(a, n - 1);
//	InDong(a, b, n);
//}
void KhuDeQuy(int a[], int n) {
	int b[20];
	b[0] = b[1] = 1;	
	int i = 1;//so dong
	while (i != n) {
		int dem = 0;	int chay = 1;

		while (1) {
			a[0] = 1;
			a[chay] = b[dem] + b[dem + 1];
			dem++;
			chay++;
			if (chay == i + 1) break;
		}
		for (int j = 0; j <= i; j++) {
			cout << a[j] << "  ";
			b[j] = a[j];
		}
		i++;
		b[i] = 1;
		cout << b[i];
		cout << endl;
	}
}
int main() {
	int n;
	for (int i = 0; i < 5; i++) {

	
	cout << "Nhap N = "; do {
		cin >> n;
		if (n <= 0) cout << "Ban nhap sai N. Moi ban nhap lai." << endl;
	} while (n <= 0);
	//N la chieu cao cua tam giac pascal
	int* a = new int[n + 1];
	int* b = new int[n + 1];
	for (int i = 0; i < n; i++) a[i] = 0;
	InDong(a, b, n);
	//KhuDeQuy(a, n);
	}
}


#include <iostream>
using namespace std;

//In tam giac Pascal canh N bang cong thuc truy hoi
int TamGiacPascal(int k, int n) {
	if (k == 0 || k == n) return 1;
	return TamGiacPascal(k, n - 1) + TamGiacPascal(k - 1, n - 1);
}
int main() {
	int n;
	do {
		cout << "Nhap N = ";
		cin >> n;
	} while (n <= 0);
	for (int i = 0; i <= n; i++) {
		for (int k = 0; k <= i; k++) cout << TamGiacPascal(k, i) << "  ";
		cout << endl;
	}
	return 0;
}
