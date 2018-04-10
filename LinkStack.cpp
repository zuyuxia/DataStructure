#include "LinkStack.h"

template<typename T>
LinkStack<T>::LinkStack() :top_(nullptr), count_(0) {
	
}

template<typename T>
LinkStack<T>::~LinkStack() {
	Node<T>* p = nullptr;
	while (top_) {
		p = top_;
		top_ = top_->next;
		delete p;
	}
	/*
	Node<T>* p = nullptr;
	for (int i = 0; i != count_; ++i) {
		p = top_;
		top_ = top_->next;
		delete p;
	}
	count_ = 0;
	top_ = nullptr;
	*/
}

template<typename T>
void LinkStack<T>::Push(T data) {
	Node<T>* p = new Node<T>;
	p->data = data;
	p->next = top_;
	top_ = p;
	++count_;
}

template<typename T>
T LinkStack<T>::Pop() {
	T data;
	Node<T>* p;
	data = top_->data;
	p = top_;
	top_ = top_->next;
	delete p;
	--count_;
	return data;
}

template<typename T>
T LinkStack<T>::GetTop() {
	return top_->data;
}

template<typename T>
bool LinkStack<T>::Empty() {
	if (count_ == 0)
		return true;
	return false;
}