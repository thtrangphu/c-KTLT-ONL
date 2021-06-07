#include "Header.h"

void initList(List& l) {
	l.pHead = l.pTail = NULL;
}
bool isEmpty(List l) {
	return (l.pHead == NULL);
}
Node* createNote(int data) {
	Node* p = new Node;
	p->data = data;
	p->pNext = NULL;
	return p;
}
Node* findIndex(List l, int i) {
	Node* p = l.pHead;
	if (l.pHead == NULL) return NULL;
	 do{
		if (i == 0) return p;
		i--;
		p = p->pNext;
	}while (p != l.pHead);
	return NULL; // trường hợp i < 0 và i > số node
}
Node* findData(List l, int data) {
	Node* p = l.pHead;
	do {
		if (p->data == data) return p;
		p = p->pNext;
	} while (p != l.pHead);
	return NULL; // trường hợp không có data và ds rỗng thì return NULL
}
Node* findTail(List l) {
	Node* p = l.pHead;
	if (l.pHead == NULL) return NULL;
	do {
		p = p->pNext;
	}while (p->pNext != l.pHead);
	return p;
}
void addHead(List& l, int data) {
	Node* p = createNote(data);
	if (isEmpty(l)) l.pHead = l.pTail = p;
	else {
		p->pNext = l.pHead; //prev->p->l.head
		l.pHead = p;
	}
	l.pTail->pNext = l.pHead; //Trỏ cuối đến đầu để tạo vòng
}
void addTail(List& l, int data) {
	Node* p = createNote(data);
	if (isEmpty(l)) addHead(l, data);
	else {
		//prev->pTail->p
		l.pTail->pNext = p; //Trỏ next
		l.pTail = p; //Cập nhật lại pTail
	}
	l.pTail->pNext = l.pHead; //Trỏ cuối đến đầu để tạo vòng
}
void addAfterI(List& l, int data, int i) {
	if (isEmpty(l) || i < 0) addHead(l, data);
	else {
		Node* p = findIndex(l, i);
		Node* padd = createNote(data);
		if (p != NULL && p->pNext!=l.pHead) {
			padd->pNext = p->pNext;
			p->pNext = padd;
		}
		else {
			addTail(l, data);
		}
	}
	l.pTail->pNext = l.pHead; //Trỏ cuối đến đầu để tạo vòng
}
void addKeepOrder(List& l, int data) {
	if (isEmpty(l)) addHead(l, data);
	else {
		if (l.pHead->data >= data) addHead(l, data);
		else {
			if (l.pTail->data <= data) addTail(l, data);
			else {
				int i = 0;
				Node* padd = createNote(data);
				Node* k = l.pHead;
				while (k) {
					if (k->data < data) {
						k = k->pNext;
						i++;
					}
					else {
						addAfterI(l, data, i - 1);
						return;
					}
				}
			}
		}
	}
	l.pTail->pNext = l.pHead; //Trỏ cuối đến đầu để tạo vòng
}
void removeHead(List& l) {
	Node* p = l.pHead;
	if (l.pHead == NULL) return;
	if (l.pHead->pNext == l.pTail) {
		l.pHead = l.pTail = NULL;
		return;
	}
	l.pHead = l.pHead->pNext;
	delete p;
	l.pTail->pNext = l.pHead; //Trỏ cuối đến đầu để tạo vòng
}
void removeTail(List& l) {
	if (l.pHead == NULL) return;
	if (l.pHead->pNext == l.pTail) {
		l.pHead = l.pTail = NULL;
		return;
	}
	Node* p = l.pTail;
	Node* prev = l.pHead;
	while (prev->pNext != l.pTail) prev = prev->pNext;
	l.pTail = prev;
	l.pTail->pNext = NULL;
	delete p;
	l.pTail->pNext = l.pHead;
}
void removeAfterIndex(List& l, int i) {
	Node* p = findIndex(l, i);
	if (p == NULL && i < 0) {
		removeHead(l);
		return;
	}
	if (p!=NULL){
		if (p == l.pTail) {
			removeTail(l);
			return;
		}
		Node* pDel = p->pNext;
		if (pDel == NULL) return;
		p->pNext = pDel->pNext;
		delete pDel;
	}
	l.pTail->pNext = l.pHead; //Trỏ cuối đến đầu để tạo vòng
}
void removeData(List& l, int data) {
	if (isEmpty(l)) return;
	else {
		if (l.pHead->data == data) removeHead(l);
		else if (l.pTail->data == data) removeTail(l);
		else {
			int i = 0;
			Node* pDel = createNote(data);
			Node* k = l.pHead;
			while (k) {
				if (k->data != data) {
					k = k->pNext;
					i++;
				}
				else {
					removeAfterIndex(l, i - 1);
					return;
				}
			}
		}
	}
	l.pTail->pNext = l.pHead; //Trỏ cuối đến đầu để tạo vòng
}
void removeAll(List& l) {
	Node* p = l.pHead;
	do {
		removeTail(l);
	} while (l.pHead!=NULL);
	l.pHead = l.pTail = NULL;
}
void printList(List& l) {
	Node* p = l.pHead;
	if (l.pHead == NULL) return;
	do {
		cout << p->data << "  ";
		p = p->pNext;
	} while (p != l.pHead);
	cout << endl;
}
