#include <iostream>
#include <string>
using namespace std;

int bai1(int n) {
	if (n == 0) return n;
	return n + bai1(n - 1);
}
int bai2(int n) {
	if (n == 1) return 2;
	return 2 * n * bai2(n - 1);
}
float bai3(int n) {
	if (n == 1) return 1;
	return 1.0 / (2 * n + 1) + bai3(n - 1);
}
int bai4(int n) {
	if (abs(n) < 10) return 1;
	return 1 + bai4(n / 10);
}
string bai5(int n, string &x) {
	if (n == 0) return "0";
	char temp[2];
	temp[0] = char(n % 2 + 48);
	temp[1] = '\0';
	x = temp + x;
	return bai5(n / 2, x);
}
int max(int a, int b)
{
	return (a > b) ? b : a;
}
int bai6(int a, int b, int i) {
	if (i == 1) return 1;
	if (a % i == 0 && b % i == 0) return i;
	else return bai6(a, b, i - 1);
}
string Bai5(int n)
{
	if (n == 0) return "0";
	string s = to_string(n % 2);
	return Bai5(n / 2) + s;
}
void bai7(int n) {
	if (n == 1) {
		cout << n << "  ";
		return;
	}
	bai7(n - 1);
	cout << n<<"  ";
}
int main() {
	string x;
	bai5(123, x);
	for (int i = x.length() - 1; i >= 0; i--) cout << x[i];
	cout << Bai5(123);
	int a, b;
	cout << "Nhap a, b: ";
	cin >> a >> b;
	int i = max(a, b);
	cout << bai6(a, b,i);
	//bai7(5);
	return 0;
}
