#include <iostream>
using namespace std;
//1.Khai báo cấu trúc 
struct Node {
	int data;
	struct Node* pNext;
};
struct List {
	Node* pHead;
};
void init(List& l);
bool isEmpty(List l);
Node* findI(List l, int i);
Node* findTail(List l);
Node* findIndex(List l, int i,Node*& prev);
Node* findData(List l, int data, Node*& prev);

void init(List& l) {
	l.pHead = NULL;
}
//3.Kiểm tra danh sách rỗng
bool isEmpty(List l) {
	return (l.pHead == NULL);
}
//4.Tạo Node
Node* createNote(int data) {
	Node* p = new Node;
	p->data = data;
	p->pNext = NULL;
	return p;
}
//5.Thêm vào danh sách 
void addHead(List& l, int data) {
	Node* p = createNote(data);
	p->pNext = l.pHead;
	l.pHead = p;	
}
void addTail(List& l, int data) {
	Node* p = createNote(data);
	if (isEmpty(l)) {
		addHead(l, data);
		return;
	}	
	Node* tail = findTail(l);
	tail->pNext = createNote(data);
}
void addAfterI(List& l, int data, int i) {
	if (isEmpty(l) || i < 0) {
		addHead(l, data);
	}
	else {
		Node* p = l.pHead;
		Node* pnext = NULL;
		Node* padd = createNote(data);
		p = findIndex(l, i, pnext);
		if (p == NULL) return;//Không tìm thấy i
		if (p->pNext == NULL) {//i ở pTail
			addTail(l, data);
			return;
		}
		pnext = p->pNext;
		p->pNext = padd;
		padd->pNext = pnext;
	}
}
void addKeepOrder(List& l, int data) {
	if (l.pHead == NULL) {
		addHead(l, data);
		return;
	}
	Node* padd = NULL;
	Node* p = findData(l, data, padd);
	padd = createNote(data);
	if (p != NULL) {
		//Thêm một 1 node là data
		if (p->pNext == NULL) {
			addTail(l, data);
			return;
		}
		padd->pNext = p->pNext;
		p->pNext = padd;
	}
	else {		
		Node* k = l.pHead;
		if (k->data > data ) {
			addHead(l, data);
			return;
		}
		while (k->pNext->data < data && k->pNext) k=k->pNext; //
		if (k->pNext == NULL) {
			addTail(l, data);
			return;
		}
		padd->pNext=k->pNext;
		k->pNext = padd;
	}
}
void removeHead(List& l) {
	if (isEmpty(l)) return;
	Node* p = l.pHead;
	l.pHead = p->pNext;
	delete p;
}
void removeTail(List& l) {
	if (isEmpty(l)) return;
	if (l.pHead->pNext) {
		removeHead(l);
		return;
	}
	Node* p = l.pHead;
	while (p->pNext && p->pNext->pNext) p = p->pNext;
	delete p->pNext;
	p->pNext = NULL;
}
void removeAfterIndex(List &l, int i) {
	if (isEmpty(l) || i < 0) return;
	/*Node* p = l.pHead;
	while (p && i > 0) {
		p = p->pNext;
		i--;
	}*/	
	Node* p = l.pHead;
	Node* prev = NULL;
	p = findIndex(l, i, prev);
	p = p->pNext;
	prev->pNext = p;
}
void removeData(List& l, int data) {
	Node* p = l.pHead;
	Node* prev = NULL;
	p = findData(l, data, prev);
	if (isEmpty(l) || p==NULL) return;	
	p = p->pNext;
	prev->pNext = p;
}
void removeAll(List& l) {
	while (l.pHead != NULL) removeHead(l);
	l.pHead = l.pTail = NULL;
}
void printList(List l) {
	cout << "		=====  XUAT DANH SACH  ====" << endl;
	for (Node* k=l.pHead; k; k = k->pNext) {
		cout << k->data << "  ";
	}
	cout << endl;
}
Node* findI(List l, int i) {
	Node* p = l.pHead;
	int dem = 0;	
	if (l.pHead == NULL) return NULL;
	while (p != NULL) {
		if (i == dem) return p;
		dem++;
		p = p->pNext;
	}
	return NULL; // trường hợp i < 0 và i > số node
}
Node *findIndex(List l, int i, Node* &prev) {
	Node* p = l.pHead;
	if (l.pHead == NULL) return NULL;
	while (p != NULL) {
		if (i == 0) return p;
		i--;
		prev = p;
		p = p->pNext;
	}
	return NULL; // trường hợp i < 0 và i > số node
}
Node* findData(List l, int data, Node *&prev) {
	Node* p = l.pHead;
	while (p != NULL) {
		if (p->data==data) return p;
		prev = p;
		p = p->pNext;
	}
	return NULL; // trường hợp không có data và ds rỗng thì return NULL
}
Node* findTail(List l) {
	Node* p = l.pHead;
	if(l.pHead==NULL) return NULL;
	while (p->pNext != NULL) {		
		p = p->pNext; 
	}
	return p;	
}
int main() {
	List l;
	init(l);
	int n;
	cout << "Nhap vao so luong Node: ";
	cin >> n;
	/*for (int i = 0; i < n; i++) {
		int data;
		cout << "Nhap data: ";
		cin >> data;
		addHead(l, data);
	}*/
	for (int i = 0; i < n; i++) {
		int data;
		cout << "Nhap data: ";
		cin >> data;
		addTail(l, data);
	}
	printList(l);
	removeAll(l);
	printList(l);
	/*addKeepOrder(l, 5);
	printList(l);*/
	/*printList(l);
	addKeepOrder(l, 0);
	printList(l);
	addKeepOrder(l, 3);
	printList(l);*/
}
