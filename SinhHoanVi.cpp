#include <iostream>
#include <string>
using namespace std;
//Sinh hoan vi 
//i la so phan tu chay duoc trong chuoi
bool kiemTraTrung(int* pos, int i, int j) {
	for (int k = 0; k < i; k++)
		if (pos[k] == j) 
return 0;
	return 1;
}
bool kiemTraLap(string t, string temp[], int dem) {
	for (int i = 0; i <= dem; i++) {
		if (t == temp[i]) return 0;
	}
	return 1;
}
void HoanVi(string s, int *pos, int n, int i, string temp[], int &dem) {
	if (i == n)
	{
		//DK dung va Xuat ket qua
		//Giữ nguyên s, xuat tai vi tri mang phu pos
		string t;
		for (int j = 0; j < n; j++) 
			t += s[pos[j]];

		if (kiemTraLap(t, temp, dem)) {
			cout << t << endl;
			temp[dem] = t;
		}
	}
	else
	{
		for (int j = 0; j < n; j++)
		{
			//Neu k co trung thi kiem tra HoanVi cua i tiep theo
			if (kiemTraTrung(pos, i, j)) {
				pos[i] = j;
				HoanVi(s, pos, n, i + 1, temp, dem);
			}
		}
	}
}
void SinhHoanVi() {
	string s;
	cout << "Nhap chuoi: ";
	cin >> s;
	int n = s.length();
	int* pos = new int[n];
	int i = 0;
	int dem = 0;
	string temp[100];
	HoanVi(s, pos, n, i, temp, dem);
	delete[] pos;
}
void HoanViKhongQuayLui(string s, int n, int *pos) {

}
int main() {
	SinhHoanVi();
}
