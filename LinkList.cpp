#include "LinkList.h"

using std::cout;

template<typename T>
LinkList<T>::LinkList() {
	first = new Node<T>;
	first->next = nullptr;
}

template<typename T>
LinkList<T>::LinkList(int length, int arr[]) {
	first = new Node<T>;
	first->next = nullptr;
	Node<T>* s;
	for (int i = 0; i != length; ++i) {
		s = new Node<T>;
		s->data = arr[length - 1 - i];
		s->next = first->next;
		first->next = s;
	}
}

template<typename T>
LinkList<T>::LinkList(LinkList &ll) {
	first = ll.GetFirst();
	ll.SetFirst();
}

template<typename T>
LinkList<T>::~LinkList() {
	Node<T>* p = first;
	while (p != nullptr) {
		Node<T>* q = p;
		p = p->next;
		delete q;
	}
}

template<typename T>
int LinkList<T>::GetLength() {
	int len = 0;
	if (first == nullptr || first->next == nullptr) {
		return len;
	}
	Node<T>* p = first;
	Node<T>* q = p->next;
	while (q != nullptr) {
		++len;
		p = q;
		q = p->next;
	}
	return len;
}

template<typename T>
int LinkList<T>::Get(int pos) {
	Node<T>* p = first;
	Node<T>* q = p->next;
	for (int i = 0; i != pos; ++i) {
		p = q;
		q = p->next;
	}
	return p->data;
}

template<typename T>
void LinkList<T>::Set(int pos) {
	Node<T>* p = first;
	Node<T>* q = p->next;
	for (int i = 0; i != pos; ++i) {
		p = q;
		q = p->next;
	}
	p->data = 0;
}

template<typename T>
bool LinkList<T>::Insert(int pos, int d) {
	if (pos<1 || pos>(GetLength() + 1)) {
		cout << "location of inserting has error\n";
		return false;
	}
	Node<T>* element=new Node<T>;
	Node<T>* p = first;
	Node<T>* q = p->next;
	for (int i = 1; i != pos; ++i) {
		p = q;
		q = p->next;
	}
	if (q != nullptr) {
		element->next = q;
		element->data = d;
		p->next = element;
		return true;
	}
	element->next = nullptr;
	element->data = d;
	p = element;
	return true;
}

template<typename T>
bool LinkList<T>::Delete(int pos) {
	int j = 0;
	Node<T>* p = first;
	while (p && j < pos - 1) {
		p = p->next;
		++j;
	}
	Node<T>* q = p->next;
	p->next = q->next;
	delete q;
	return true;
}

template<typename T>
Node<T>* LinkList<T>::GetFirst() {
	return first;
}

template<typename T>
void LinkList<T>::SetFirst() {
	first = nullptr;
}