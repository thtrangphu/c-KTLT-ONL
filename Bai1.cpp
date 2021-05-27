//24=2*2*2*3;
#include <iostream>
using namespace std;
bool checkNguyenTo(int n) {
	if (n < 2) return 0;
	if (n > 2) {
		for (int i = 2; i <= sqrt(n); i++) {
			if (n % i == 0) return 0;
		}
	}
	return 1;
}
void mangNguyenTo(int a[], int &sl) {
	sl = 0;
	for (int i = 2; i <= 200; i++) {
		if (checkNguyenTo(i)) {
			a[sl] = i;
			sl++;
		}
	}
}
int sum(int n, int a[], int sl) {
	mangNguyenTo(a, sl);
	while (1) {
		if (checkNguyenTo(n)) return n;
			int i = 0;
			int s = 0;
			while (n != 1) {
				if (n % a[i] == 0) {
					s += a[i];
					n /= a[i];				
				}
				else i++;
			}
			n = s;
		
	}
}
int main() {
	int a[100];
	int sl=0 ;
	cout<<sum(24, a, sl);
}
