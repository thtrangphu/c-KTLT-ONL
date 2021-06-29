#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct Node
{
	char data;
	Node* pNext;
};
struct Stack
{
	Node* ptop = NULL;//<=> phead
};

struct NodeQ {
	string data;
	NodeQ* pNext;
};
struct Queue {
	NodeQ* pHead = NULL;
	NodeQ* pTail = NULL;
};
int atoi(const char* str);
void xuatQueue(Queue q);
bool isEmptyStack(Stack s);
Node* KhoiTaoNode(char x);
void PushStack(Stack& s, char x);
void PopStack(Stack& s);
int Top(Stack s);
bool isEmptyQueue(Queue q);
void PushQueue(Queue& q, string x);
void PopQueue(Queue& q);
string Front(Queue q);
string Back(Queue);
void loadFile(string& s);
NodeQ* KhoiTaoNodeQ(string x);
void xuatQueue(Queue q);
int chuoiSangSo(string s);
string soSangChuoi(int x);
string cong(string s1, string s2);
void tinhToan(Queue& q);
int doUuTien(char x) {
	if (x == '+' || x == '-') return 1;
	else if (x == '*' || x == '/' || x == '%') return 2;
	else if (x == '^') return 3;
	return 0;//'('
}
void hauTo(Stack& s) {
	int i = 0;
	Queue q;
	string str, str1 = "";
	loadFile(str);
	char a[3];
	while (i < str.length()) {
		char c = str.at(i);
		if (c != ' ') {
			if (c - '0' >= 0 && c - '0' <= 9) str1 += c;
			else {
				if (str1 != "") {
					cout << str1 << "  ";
					PushQueue(q, str1);
					str1 = "";
				}
				if (c == '(') PushStack(s, c);
				else {
					if (c == ')') {
						while (s.ptop->data != '(') {
							cout << s.ptop->data;

							a[0] = s.ptop->data;
							a[1] = '\0';
							PushQueue(q, a);
							PopStack(s);
						}
						PopStack(s);
					}
					else {
						int d2;
						if (s.ptop == NULL) d2 = 0;
						else d2 = doUuTien(s.ptop->data);
						int d1 = doUuTien(c);

						while (!isEmptyStack(s) && (d1 <= d2)) {
							cout << s.ptop->data;
							a[0] = s.ptop->data;
							a[1] = '\0';
							PushQueue(q, a);
							PopStack(s);
						}
						PushStack(s, c);
					}
				}
			}
		}
		i++;
	}
	if (str1 != "") {
		cout << str1 << "  ";
		PushQueue(q, str1);
	}
	while (!isEmptyStack(s)) {
		cout << s.ptop->data;
		a[0] = s.ptop->data;
		a[1] = '\0';
		PushQueue(q, a);
		PopStack(s);
	}
	xuatQueue(q);
	tinhToan(q);
}
void xuatQueue(Queue q) {
	cout << endl;
	for (NodeQ* k = q.pHead; k; k = k->pNext) {
		cout << k->data << endl;
	}
}


string soSangChuoi(int x) {
	string s;
	char temp[3];
	int n = log10(abs(x)) + 1;
	if (x < 0) {
		s += "-";
		x = -x;
	}
	for (int i = 0; i < n; i++)
	{
		int nguyen = x / pow(10, n - i - 1);
		temp[0] = char(nguyen + 48);
		temp[1] = '\0';
		s += temp;
		int du = pow(10, n - i - 1);
		x = x % du;
	}
	return s;
}
string cong(string s1, string s2) {
	return soSangChuoi(stoi(s1) + stoi(s2));
}
string tru(string s1, string s2) {
	return soSangChuoi(stoi(s2) - stoi(s1));
}
string nhan(string s1, string s2) {
	return soSangChuoi(stoi(s1) * stoi(s2));
}
string chia(string s1, string s2) {
	return soSangChuoi(stoi(s1) / stoi(s2));
}
string luythua(string s1, string s2) {
	return soSangChuoi(pow(stoi(s2), stoi(s1)));
}
void tinhToan(Queue& q) {
	string s1, s2, s3 = "";
	while (q.pHead->pNext != NULL) {
		s1 = Front(q);	PopQueue(q);
		s2 = Front(q);	PopQueue(q);
		s3 = Front(q);
		if (s3 == "+") q.pHead->data = cong(s1, s2);
		if (s3 == "-") q.pHead->data = tru(s1, s2);
		if (s3 == "*") q.pHead->data = nhan(s1, s2);
		if (s3 == "/") q.pHead->data = chia(s1, s2);
		if (s3 == "^") q.pHead->data = luythua(s1, s2);
	}
	cout << q.pHead->data;
}
void main()
{
	Stack s;
	hauTo(s);
}

bool isEmptyQueue(Queue q) {
	return q.pHead == NULL;
}
void PushQueue(Queue& q, string x) {
	//Them sau
	NodeQ* p = KhoiTaoNodeQ(x);
	if (q.pHead == NULL) {
		q.pHead = q.pTail = p;
		return;
	}
	q.pTail->pNext = p;
	q.pTail = p;
}
void PopQueue(Queue& q) {
	//Xoa dau
	NodeQ* p = q.pHead;
	if (q.pHead == NULL) return;
	else {
		if (q.pHead == q.pTail) {
			q.pHead = q.pTail = NULL;
		}
		q.pHead = q.pHead->pNext;
		delete p;
	}
}
string Front(Queue q) {
	if (q.pHead == NULL) return NULL;
	return q.pHead->data;
}
string Back(Queue q) {
	if (q.pTail == NULL) return NULL;
	return q.pTail->data;

}
void loadFile(string& s) {
	ifstream f;
	f.open("input.txt", ios_base::in);
	f >> s;
}

bool isEmptyStack(Stack s)
{
	if (s.ptop == NULL)return 1;
	return 0;
}
Node* KhoiTaoNode(char x)
{
	Node* p = new Node;
	p->data = x;
	p->pNext = NULL;
	return p;
}
NodeQ* KhoiTaoNodeQ(string x)
{
	NodeQ* p = new NodeQ;
	p->data = x;
	p->pNext = NULL;
	return p;
}
void PushStack(Stack& s, char x)//thêm đầu
{
	Node* p = KhoiTaoNode(x);
	if (s.ptop == NULL)
	{
		s.ptop = p;
	}
	else//n pt
	{
		p->pNext = s.ptop;
		s.ptop = p;//cập nhật
	}
}
void PopStack(Stack& s)//xoa dau
{
	if (s.ptop == NULL)return;
	Node* tam = s.ptop;
	s.ptop = s.ptop->pNext;
	delete tam;
}
int Top(Stack s)
{
	if (s.ptop != NULL)return s.ptop->data;
}
