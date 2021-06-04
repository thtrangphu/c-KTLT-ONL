#include "Header.h"
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
	if (n == 1) return pow(x, 2);
	return luyThuaMuChan(n - 1, x) + pow(x, n * 2);

}
int fibonacci(int n) {
	if (n < 1) return 0;
	if (n == 1) return 1;
	if (n == 2) return 1;
	return fibonacci(n - 1) + fibonacci(n - 2);
}
int menu() {
	cout << "         ==========   MENU   =========          " << endl;
	cout << "         0.Thoat\n";
	cout << "         1. Tong 1^2+2^2+...+n^2\n";
	cout << "         2. Tong 1+1/2+...+1/n\n";
	cout << "         3. Tong 1/2+1/4+...+1/2n\n";
	cout << "         4. Tongx^2+x^4+...+x^2n\n";
	cout << "         5. Tinh so hang thu n trong day Fibonacci\n";
	return 5;
}
void runMenu(int sl) {
	
	int n;
	while (1) {
		system("cls");
		menu();
		int lc;
		do {
			cout << "Moi ban nhap lua chon: ";
			cin >> lc;
			if (lc<0 || lc>sl) cout << "Nhap sai lua chon !! Moi ban nhap lai ...." << endl;
		} while (lc<0 || lc>sl);
		int sl;
		if (lc != 0) {
			cout << "Nhap n: ";
			cin >> n;
		}		
		switch (lc)
		{
		case 1: {
			system("cls");
			cout << "         1^2+2^2+...+n^2\n";
			cout << tongMu2(n) << endl;
			break;
		}
		case 2: {
			system("cls");
			cout << "          1+1/2+...+1/n\n";
			cout << tongPhanSo(n) << endl;
			break;
		}
		case 3: {
			system("cls");
			cout << "         1/2+1/4+...+1/2n\n";
			cout << tongPhanSoChan(n) << endl;
			break;
		}
		case 4: {
			system("cls");
			cout << "          x^2+x^4+...+x^2n\n";
			cout << "Nhap x = ";
			int x;
			cin >> x;
			cout << luyThuaMuChan(n,x) << endl;
			break;
		}
		case 5: {
			system("cls");
			cout << "        Tinh so hang thu n trong day Fibonacci\n";
			cout << fibonacci(n) << endl;
			break;
		}
		case 0: exit(0);
		
		}
		system("pause");
	}
}




#include "Header.h"
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
int menu() {
	cout << "         ==========   MENU   =========          " << endl;
	cout << "         0.Thoat\n";
	cout << "         1. Dem so luong chu so cua 1 so\n";
	cout << "         2. Tong cac chu so chan cua n\n";
	cout << "         3. Chu so dau tien cua n\n";
	cout << "         4. So dao nguoc cua n\n";
	cout << "         5. Chu so lon nhat cua n\n";
	cout << "         6. Kiem tra n co chua toan chu so le khong\n";
	return 6;
}
void runMenu(int sl) {
		int n;
		while (1) {
			system("cls");
			menu();
			int lc;
			do {
				cout << "Moi ban nhap lua chon: ";
				cin >> lc;
				if (lc<0 || lc>sl) cout << "Nhap sai lua chon !! Moi ban nhap lai ...." << endl;
			} while (lc<0 || lc>sl);
			int sl;
			if (lc != 0) {
				cout << "Nhap n: ";
				cin >> n;
			}
			switch (lc)
			{
			case 1: {
				system("cls");
				cout << "         ==========   DEM SO LUONG CHU SO   =========          " << endl;
				cout<<n<< " co "<< demSoChuSo(n)<<" chu so.\n";
				break;
			}
			case 2: {
				system("cls");
				cout << "         ==========   TONG CHU SO CHAN   =========          " << endl;
				cout << tongCacChuSoChan(n) << endl;
				break;
			}
			case 3: {
				system("cls");
				cout << "         ==========   CHU SO DAU TIEN  =========          " << endl;
				cout << chuSoDauTien(n) << endl;
				break;
			}
			case 4: {
				system("cls");
				cout << "         ==========   SO DAO NGUOC   =========          " << endl;
				cout << soDao(n) << endl;
				break;
			}
			case 5: {
				system("cls");
				cout << "         ==========   CHU SO LON NHAT   =========          " << endl;
				cout << chuSoLonNhat(n) << endl;
				break;
			}
			case 6: {
				system("cls");
				cout << "         ==========   KIEM TRA TOAN LE   =========          " << endl;
				if (soToanLe(n) == 1) cout << n << " la so toan le." << endl;
				else cout << n << " khong la so toan le." << endl;
				break;
			}
			case 0: exit(0);
			}
			system("pause");
		}
}
