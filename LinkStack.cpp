#include "LinkStack.h"

template<typename T>
LinkStack<T>::LinkStack() :top(nullptr), count(0) {
	
}

template<typename T>
LinkStack<T>::~LinkStack() {
	Node<T>* p = nullptr;
	while (top) {
		p = top;
		top = top->next;
		delete p;
	}
	/*
	Node<T>* p = nullptr;
	for (int i = 0; i != count; ++i) {
		p = top;
		top = top->next;
		delete p;
	}
	count = 0;
	top = nullptr;
	*/
}

template<typename T>
void LinkStack<T>::push(T data) {
	Node<T>* p = new Node<T>;
	p->data = data;
	p->next = top;
	top = p;
	++count;
}

template<typename T>
T LinkStack<T>::pop() {
	T data;
	Node<T>* p;
	data = top->data;
	p = top;
	top = top->next;
	delete p;
	--count;
	return data;
}

template<typename T>
T LinkStack<T>::GetTop() {
	return top->data;
}

template<typename T>
bool LinkStack<T>::Empty() {
	if (count == 0)
		return true;
	return false;
}