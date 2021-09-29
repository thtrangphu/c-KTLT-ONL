#include <iostream>
#include <string>
using namespace std;

#define MAX_SIZE 100

void xoa(char s[], int viTri) {
	int n = strlen(s);
	for (int j = viTri; j < n - 1; j++) {
		s[j] = s[j + 1];
	}
	s[n - 1] = '\0';
}
void vietHoaDau(char s[]) {
	int n = strlen(s);
	if (s[0] >= 'a' && s[0] <= 'z')
		s[0] -= 32;
	for (int i = 1; i < n; i++) {
		if (s[i] != ' ') {
			if (s[i] >= 'A' && s[i] <= 'Z') {
				s[i] += 32;
			}
			//Viet hoa chu cai dau
			if (s[i - 1] == ' ' )
				if (s[i] >= 'a' && s[i] <= 'z') {
					s[i] -= 32;
				}
		}
	}
}

void chuanHoa(char s[]) {
	while (s[0] == ' ') {
		xoa(s, 0);
	}

	while (s[strlen(s) - 1] == ' ')
		s[strlen(s) - 1] = '\0';

	int n = strlen(s);
	for (int i = 0; i < n - 1; i++) {
		if (s[i] == ' ' && s[i + 1] == ' ')
		{
			xoa(s, i);
			i--;
		}
	}
	vietHoaDau(s);
}
int main() {
	char s[] = "      PHu   tHi    kiM  TranG       ";
	/*cout << "Nhap chuoi: ";
	cin.getline(s, MAX_SIZE + 1);*/
	cout << s << endl;

	chuanHoa(s);

	cout << s << "!";
}
