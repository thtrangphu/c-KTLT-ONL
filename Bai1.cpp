#include <iostream>
#include <fstream>
using namespace std;

struct Node {
	int data;
	struct Node* pNext;
};
struct Stack {
	Node* Head;
	Node* Tail;
	int max;
	int size;
};
void InitStack(Stack& s, int n) {
	s.Head = s.Tail = NULL;
	s.max = n;
	s.size = 0;
}
bool IsEmpty(Stack s) {
	return (s.size == 0) ? 1 : 0;
}
bool IsFull(Stack s) {
	return (s.size == s.max) ? 1 : 0;
}
Node* CreateNode(int x) {
	Node* p = new Node;
	if (p == NULL) return NULL;
	p->data = x;
	p->pNext = NULL;
	return p;
}

bool Push(Stack& s, int value) {
	if (IsFull(s)==1) return 0;
	else {
		Node* p = CreateNode(value);
		if (IsEmpty(s) == 1) {
			s.Head = s.Tail = p;
		}
		else {
			//1,2,3->4
			s.Tail->pNext = p;
			s.Tail = p;
		}
	}
	s.size++;
	return 1;
}
bool Pop(Stack& s) {
	if (s.size == 0) return 0;
	if (s.Head != s.Tail) {
		Node* pDel = s.Tail;
		Node* pCur = s.Head;
		while (pCur->pNext != s.Tail) pCur = pCur->pNext;
		pCur->pNext = NULL;
		s.Tail = pCur;
		delete pDel;
	}
	else {
		Node* pDel = s.Head;
		delete pDel;
		s.Head = s.Tail = NULL;
	}
	s.size--;
	return 1;
}
//Lấy phần tử đầu stack
int Top(Stack s) {
	if (IsEmpty(s) == 1) return INT_MIN;
	return s.Tail->data;
}
void PrintStack(Stack s) {
	cout << endl << "XUAT DS NODE: "<<endl;
	for (Node* k = s.Head; k; k = k->pNext) cout << k->data << "  ";
	cout << endl;
}
void xuLy(Stack s, Stack kq) {
	Node* pCur = kq.Head;
	Node* p = s.Head;
	bool check = true;
	while ( p!= NULL) {
		if (s.Head == NULL || kq.Head==NULL) {
			cout << "Khong co ket qua mong muon.";
			return;
		}
		cout << "Push  ";
		if (p->data == pCur->data ) {
			check = false;
			p = p->pNext;
			pCur = pCur->pNext;
			if (pCur== NULL) return;
		}
		else {
			cout << "Pop  ";
			p = p->pNext;
		}
	//	if (pCur/*->pNext*/ == NULL) return;
	}
	if(check==true)
	cout << "Khong co ket qua mong muon.";
}
void binhPhuong(Stack& s) {
	if (s.Head == NULL) return;
	s.Tail->data = (s.Tail->data) * 2;
}

int cong(Stack &s) {
	Node* p = s.Head;
	while (p->pNext != s.Tail) {
		//Gan cuoi
		p = p->pNext;

	}
	Pop(s);
	return p->data + s.Tail->data;
}
int tru(Stack& s) {
	Node* p = s.Head;
	while (p->pNext != s.Tail) {
		//Gan cuoi
		p = p->pNext;
		
	}
	Pop(s);
	return p->data - s.Tail->data;
}
int nhan(Stack& s) {
	Node* p = s.Head;
	while (p->pNext != s.Tail) {
		//Gan cuoi
		p = p->pNext;
	}
	Pop(s);
	return p->data * s.Tail->data;
}
float chia(Stack& s) {
	Node* p = s.Head;
	while (p->pNext != s.Tail) {
		//Gan cuoi
		p = p->pNext;
	}
	Pop(s);
	return p->data*1.0 / s.Tail->data;
}
void loadFile(Stack &s) {
	Node* p = s.Head;
	fstream f;
	f.open("input.txt", ios::in);
	char x;
	int kq = 0;
	while (1) {
		f >> x;
		if (x == ']') {
			//cout << kq;
			return;
		}
		f >> x;
		switch (x) {
		case 'A': {
			//Xoa so gan nhat
			Pop(s); break;
		}
		case 'B': {
			//Binh phuong so cuoi
			binhPhuong(s); break;
		}
		case 'C': {
			//Xoa toan bo
			while (s.Head != NULL) Pop(s);
			s.Head = s.Tail = NULL;
			break;
		}
		case '+': {
			kq = cong(s);
			s.Tail->data = kq;
			
			break;
		}
		case '-': {
			kq = tru(s);
			s.Tail->data = kq; break;
		}
		case '*': {
			kq = nhan(s);
			s.Tail->data = kq; break;
		}
		case '/': {
			kq = chia(s);
			s.Tail->data = (float)kq; break;
		}
		default: {Push(s, int(x - 48)); break; }
		}
	}

	
		
	
}
int main() {
	Stack s;
	InitStack(s,10);
	loadFile(s);
	PrintStack(s);
}
