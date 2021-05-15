int stringToNumber(char s[])
{
	int x = 0;
	for (int i = strlen(s) - 1; i >= 0; i--)
	{
		x = x+pow(10,strlen(s)-1-i)*(s[i]-48);
	}
	return x;
}
string to_String(int x){
  char s[100]="";
	int n = log10(x) + 1;
	for (int i = n - 1; i >= 0; i--)
	{
		s[i] = char(x % 10 + 48);
		x /= 10;
	}
	return s;
}
#include <iostream>
#include <string>
using namespace std;
int checkLength(char s1[], char s2[]) {
	int l1 = strlen(s1);
	int l2 = strlen(s2);
	if (l1 == l2) return 0;
	else if (l1 > l2) return 1;
	return -1;
}

int compare(char s1[], char s2[]) {
	if (checkLength(s1, s2) != 0) {
		return checkLength(s1, s2);
	}
	for (int i = 0; i < strlen(s1); i++) {
		if (s1[i] > s2[i]) return 1;
		else if (s1[i] > s2[i]) return -1;
	}
	return 0;
}
string min(char s1[], char s2[]) {
	if (compare(s1,s2)<=0)
	{
		return s1;
	}
	return s2;
}
string max(char s1[], char s2[]) {
	if (compare(s1, s2) >= 0)
	{
		return s1;
	}
	return s2;
}
void xoaKiTu(char a[], int vt) {
	int n = strlen(a);
	for (int i = vt; i < n; i++)
	{
		a[i] = a[i + 1];
		//Lấy dư đến n để có /0 
	}
}
string abs(char s[]) {
	if (s[0] == '-') xoaKiTu(s, 0);
	return s;
}
int numberCharacter(char s[]) {
	int count = 0;
	for (int i = 0; i < strlen(s); i++) {
		if (s[i] <= '0' && s[i] >= '9') count++;
	}
	return count;
}
int main() {
	char s1[] = "12345678";
	char s2[] = "1234567";
	cout<<min(s1, s2);
	cout<<endl<<max(s1, s2);
 }
	
