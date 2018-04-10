#include "LinkQueue.h"

template<typename T>
LinkQueue<T>::LinkQueue() {
	front_ = new Node<T>;
	rear_ = front_;
}

template<typename T>
LinkQueue<T>::~LinkQueue() {
	Node<T>* p;
	while (front_ != rear_) {
		p = front_;
		front_ = p->next;
		delete p;
	}
	delete rear_;
}

template<typename T>
void LinkQueue<T>::EnQueue(T element) {
	Node<T>* s = new Node<T>;
	s->data = element;
	s->next = nullptr;
	rear_->next = s;
	rear_ = s;
}

template<typename T>
void LinkQueue<T>::DeQueue() {
	Node<T>* p = front_->next;
	front_->next = p->next;
	delete p;
}

template<typename T>
T LinkQueue<T>::GetFront() {
	return front_->next->data;
}

template<typename T>
bool LinkQueue<T>::Empty() {
	if (front_ == rear_)
		return true;
	return false;
}

