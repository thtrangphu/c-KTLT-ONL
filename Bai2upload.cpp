#pragma once // tránh đụng độ thư viện khi gọi chồng file lên nhau
#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include <iomanip>
#include <stdio.h>
#include <conio.h>
#include<ctime>
#include "windows.h" 
using namespace std;
#define MAX 100
struct User {
	string account = "";
	string pass = "";
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
void nhap1(User x) {
	cout << "Nhap tai khoan: ";
	getline(cin,x.account);
	cout << "Nhap mat khau: ";
	getline(cin, x.pass);
}
bool xuLi(User s[], int n, User a) {
	for (int i = 0; i < n; i++) {
		if (_stricmp(s[i].account.c_str(), a.account.c_str()) == 0 || _stricmp(s[i].pass.c_str(), a.pass.c_str()) == 0) {
			return false;
		}
	}
	return true;
}

void Login(User &x) {
	char c;
	c = 13;
	cin.ignore();
	cout << "Nhap tai khoan: ";
	getline(cin, x.account);
	cout << "Mat khau: ";
	do {
		c = _getch();
		cout << "*";
		if (int(c) != 13) x.pass += c;
	} while (int(c) != 13);
}
void menu() {
	cout << "0.Thoat\n1.Load File\n2.Xuat danh sach\n3.Xu li dang nhap\n";
}
//============== làm ẩn trỏ chuột ===========
void ShowCur(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
	SetConsoleCursorInfo(handle, &cursor);
}

//============== dịch con trỏ hiện tại đến điểm có tọa độ (x,y) ==========
void gotoXY(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x, y };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}
//============= đặt màu cho chữ =========
void SetColor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}

void login(int x, int y)
{
	char c;
	c = 13;
	cin.ignore();
	gotoXY(x - 3, y);
	cout << "TK:";
	gotoXY(x - 3, y + 1);
	cout << "MK:";
	gotoXY(x, y + 2);
	cout << "LOGIN";
	gotoXY(x, y);
}

//void main()
//{
//	string s = "LOGIN";
//	//-------- seting ----------
//	int xtk = 50, ytk = 13;
//	User a;
//	login(xtk, ytk);
//	int x = 50, y = 13;
//	bool kt = false;
//	while (true)
//	{
//		if (_kbhit())
//		{
//			char c = _getch();
//			if (c == -32)
//			{
//				c = _getch();
//				if (c == 72 && (y != ytk))
//				{
//
//					y--;
//					kt = true;
//					if (y == ytk + 1)//vừa đi từ login lên mk
//					{
//						
//						SetColor(10);
//						gotoXY(x, y + 1);
//						cout << s;
//						ShowCur(1);
//					}
//				}
//				else if (c == 80 && (y != ytk + 2))
//				{
//					
//					y++;
//					kt = true;
//				}
//				else {
//					gotoXY(x, y);
//					getline(cin, a.account);
//					gotoXY(x, y + 1);
//					do {
//						c = _getch();
//						cout << "*";
//						if (int(c) != 13) a.pass += c;
//					} while (int(c) != 13);
//				}//Nếu là phím khác -> nghĩa là nhập dữ liệu login
//			}
//		}
//		//------------
//		if (kt == true)
//		{
//			kt = false;
//			if (y == ytk + 2)
//			{
//				ShowCur(0);
//				SetColor(4);
//				gotoXY(x, y);
//				cout << s;
//				SetColor(10);
//			}
//			else
//			{
//				gotoXY(x, y);
//			}
//		}
//
//	}
//	_getch();
//}

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
			Login(a);
			cout << endl;
			if (xuLi(s,n,a)==true)
			{
				cout << "Dang nhap thanh cong !!! "<<endl;
			}
			else {
				cout << "Dang nhap that bai !!!" << endl;
			}
			system("pause");
		}
	}
}
