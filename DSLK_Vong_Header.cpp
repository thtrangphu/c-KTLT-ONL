#pragma once
#ifndef Header_h
#define  Header_h
#include <iostream>
using namespace std;
struct Node {
	int data;
	struct Node* pNext;
};
struct List {
	Node* pHead;
	Node* pTail;
};

void initList(List& l);
bool isEmpty(List l);
Node* createNote(int data);
Node* findIndex(List l, int i);
Node* findData(List l, int data);
Node* findTail(List l);
void addHead(List& l, int data);
void addTail(List& l, int data);
void addAfterI(List& l, int data, int i);
void addKeepOrder(List& l, int data);
void removeHead(List& l);
void removeTail(List& l);
void removeAfterIndex(List& l, int i);
void removeData(List& l, int data);
void removeAll(List& l);
void printList(List& l);


#endif //  Header_h

