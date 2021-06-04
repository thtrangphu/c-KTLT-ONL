#include "Header.h"

void nhapMang(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << "Nhap phan tu thu " << i << " : ";
		cin >> a[i];
	}
}
void xuatMang(int a[], int n) {
	if (n == 0) return;
	xuatMang(a, n - 1);
	cout << a[n - 1] << " ";
}
void xuatMangNguoc(int a[], int n) {
	if (n == 0) return;
	cout << a[n - 1] << " ";
	xuatMangNguoc(a, n - 1);
}
int soLonNhatTrongMang(int a[], int n) {
	if (n == 1) return a[n];
	int max = soLonNhatTrongMang(a, n - 1);
	return (max > a[n]) ? max : a[n];
}

int kiemTraNguyenTo(int x, int i)
{
	if (x < 2) return 0;
	return (x == i) ? 1 : ((x % i == 0) ? 0 : kiemTraNguyenTo(x, i + 1));
}

int demSoNguyenTo(int a[], int n)
{
	return (n == 0) ? 0 : (kiemTraNguyenTo(a[n - 1], 2) == 1) ? 1 + demSoNguyenTo(a, n - 1) : demSoNguyenTo(a, n - 1);
}

int demPhBiet(int a[], int n) {
	if (n == 0) {
		return 0;
	}
	int dem = 0;
	for (int i = 0; i < n - 1; i++) {
		if (a[i] == a[n - 1]) dem++;
	}
	if (dem == 0) return demPhBiet(a, n - 1) + 1;
	return demPhBiet(a, n - 1);
}
int demChiaHet7(int a[], int n) {
	if (n == 1) if (a[n -1] % 7 != 0)return 0;	else return 1;
	if (a[n - 1] % 7 == 0) return 1 + demChiaHet7(a, n - 1);
	return demChiaHet7(a, n - 1);
}
void sapXepTang(int a[], int n) {
	if (n > 1) {
		sapXepTang(a, n - 1);
		if (a[n - 2] > a[n - 1]) {
			swap(a[n - 1], a[n - 2]);
			sapXepTang(a, n - 1);
		}
	}
}
int menu() {
	cout << "         ==========   MENU   =========          " << endl;
	cout << "         0.Thoat\n";
	cout << "         1. Nhap mang so nguyen\n";
	cout << "         2. Xuat mang so nguyen\n";
	cout << "         3. Xuat mang so nguyen nguoc\n";
	cout << "         4. So lon nhat trong mang\n";
	cout << "         5. Dem so nguyen to trong mang\n";
	cout << "         6. Dem gia tri phan biet trong mang\n";
	cout << "         7. Kiem tra mang co toan so chia 7 hay khong\n";
	cout << "         8. Sap xep mang tang dan\n";
	return 8;
}

void runMenu(int n) {
	int a[100];
	bool check = true;
	int sl;
	while (1) {
		system("cls");
		menu();
		int lc;		
		do {
			cout << "Moi ban nhap lua chon: ";
			cin >> lc;
			if (lc<0 || lc>n) cout << "Nhap sai lua chon !! Moi ban nhap lai ...." << endl;
		} while (lc<0 || lc>n);
		
		switch (lc)
		{
		case 1: {
			system("cls");
			cout << "         ==========   NHAP MANG   =========          " << endl;
			cout << "Nhap so luong phan tu mang: ";
			cin >> sl;
			nhapMang(a, sl);
			check = false;
			break;
		}
		case 2: {
			system("cls");
			cout << "         ==========   XUAT MANG   =========          " << endl;
			if (check == true) {
				cout << "Nhap so luong phan tu mang: ";
				cin >> sl;
				nhapMang(a, sl);
			}
			xuatMang(a, sl);
			break;
		}
		case 3: {
			system("cls");
			cout << "         ==========   XUAT MANG NGUOC   =========          " << endl;
			if (check == true) {
				cout << "Nhap so luong phan tu mang: ";
				cin >> sl;
				nhapMang(a, sl);
			}
			xuatMangNguoc(a, sl);
			break;
		}
		case 4: {
			system("cls");
			cout << "         ==========   SO LON NHAT   =========          " << endl;
			if (check == true) {
				cout << "Nhap so luong phan tu mang: ";
				cin >> sl;
				nhapMang(a, sl);
			}
			cout << "So lon nhat trong mang la: " << soLonNhatTrongMang(a, n);
			break;
		}
		case 5: {
			system("cls");
			cout << "         ==========   DEM SO NGUYEN TO   =========          " << endl;
			if (check == true) {
				cout << "Nhap so luong phan tu mang: ";
				cin >> sl;
				nhapMang(a, sl);
			}
			cout << "Co " << demSoNguyenTo(a, n) << " so nguyen to trong mang.";
			break;
		}
		case 6: {
			system("cls");
			cout << "         ==========   DEM SO PHAN BIET   =========          " << endl;
			if (check == true) {
				cout << "Nhap so luong phan tu mang: ";
				cin >> sl;
				nhapMang(a, sl);
			}
			cout << "Co " << demPhBiet(a, sl) << " so phan biet trong mang.";
			break;
		}
		case 7: {
			system("cls");
			cout << "         ==========   KIEM TRA MANG CO TOAN SO CHIA HET CHO 7   =========          " << endl;
			if (check == true) {
				cout << "Nhap so luong phan tu mang: ";
				cin >> sl;
				nhapMang(a, sl);
			}
			//KIEM TRA
			if (demChiaHet7(a, sl) == sl) cout << "Mang co chua toan so chia het cho 7.";
			else cout << "Khong toan so chia het cho 7.";
			break;
		}
		case 8: {
			system("cls");
			cout << "         ==========   SAP XEP TANG   =========          " << endl;
			if (check == true) {
				cout << "Nhap so luong phan tu mang: ";
				cin >> sl;
				nhapMang(a, sl);
			}
			//SAP XEP TANG DAN 
			sapXepTang(a, sl);
			break;
		}
		default:
			exit(0);
		}
		system("pause");
	
	}
}
