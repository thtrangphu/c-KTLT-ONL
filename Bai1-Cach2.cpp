#include <iostream>
#include <string>
#pragma warning(disable : 4996)
using namespace std;
void chuanHoa2(char s[]) {

	int n = strlen(s);
	char *s1 = new char[n+1];
	//strcpy(s1, s);

	int j = 0;
	int i = 0;

	cout << "Ban dau: "<<s1 << endl;

	// Bo qua dau cach o dau
	while (s[i] == ' ') {
		i++;
	}

	for (; i < n; i++) {
		while (s[i] == ' ' && s[i + 1] == ' ') {
			i++;
		}
		//Viet hoa chu cai dau
		if (s[i] != ' ') {
			if (s[i] >= 'A' && s[i] <= 'Z') {
				s[i] += 32;
			}
			//Viet hoa chu cai dau
			if (s[i - 1] == ' ')
				if (s[i] >= 'a' && s[i] <= 'z') {
					s[i] -= 32;
				}
		}
		s1[j++] = s[i];
	}
	s1[j] = '\0';
	cout <<"Xong game:"<< s1 << endl;
}
int main() {
	char s[] = "      pHu   tHi    kiM  TranG       ";
	cout << s << endl;

	chuanHoa2(s);
}
