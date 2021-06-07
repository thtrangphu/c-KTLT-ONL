#include "Header.h"
int main() {
	List l;
	initList(l);
	int n;
	cout << "Nhap so luong node cua danh sach: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cout << "Nhap data: ";
		cin >> x;
		addTail(l, x);
	}
	printList(l);

	removeAll(l);
	printList(l);

	addHead(l, 1);
	addTail(l, 5);
	printList(l);

}
