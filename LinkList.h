#ifndef LINKLIST_H
#define LINKLIST_H

#include<iostream>

template<typename T>
struct Node {
	int data = 0;
	Node<T> *next;
};

template<typename T>
class LinkList {
public:
	LinkList();
	LinkList(int length, int arr[]);
	LinkList(LinkList& ll);
	~LinkList();

	int GetLength();
	int Get(int pos);
	void Set(int pos);
	bool Insert(int pos, int d);
	bool Delete(int pos);
	Node<T>* GetFirst();
	void SetFirst();
private:
	Node<T> *first = nullptr;
};

#endif