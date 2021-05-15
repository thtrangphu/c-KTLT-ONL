#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;
#define MAX 100
struct User {
	string account;
	string pass;
};

void docFile(User s[], int& n) {
	ifstream f;
	f.open("input.txt", ios_base::in);
	if (f.fail()) {
		cout << "Khong mo duoc file !";
		return;
	}
	n = 0;
	while (!f.eof()) {
		User x;
		getline(f,x.account,',');
		getline(f, x.pass);
		f.ignore();//Xuong dong
		s[n++] = x;
		if (f.eof() == true)
		{
			break;
		}
	}
	f.close();
}
void xuat1(User x) {
	cout <<  x.account << "\t \t   " << x.pass << endl;
}
void xuatDanhSach(User s[], int n) {
	cout << endl << "--TAI KHOAN--"<<"\t    "<<"--MAT KHAU--" << endl;
	for (int i = 0; i < n; i++) {
		xuat1(s[i]);
	}
}
//void nhap1(User x) {
//	cout << "Nhap tai khoan: ";
//	getline(x.account,20);
//}
//void xuLi1(User x) {
//
//}
void menu() {
	cout << "0.Thoat\n1.Load File\n2.Xuat danh sach\n3.Xu li dang nhap\n";
}
int main() {
	User s[MAX];
	int n = 0;
	int lc;
	while (1) {
		system("cls");
		menu();
		do {
			cout << "Moi ban nhap lua chon: ";
			cin >> lc;
			if (lc < 0 || lc>3) cout << "Nhap sai !!! Moi ban nhap lai..." << endl;
		} while (lc < 0 || lc>3);
		if (lc == 0) exit(0);
		else if (lc == 1) {
			cout << "==================== LOAD FILE ====================" << endl;
			docFile(s, n);
			system("pause");
		}
		else if (lc == 2) {
			cout << "============= XUAT DANH SACH HIEN CO ==============" << endl;
			xuatDanhSach(s, n);
			system("pause");
		}
		else if (lc == 3) {
			cout << "================= XU LI DANG NHAP =================" << endl;
			User a;
			
		}
	}
	
}
