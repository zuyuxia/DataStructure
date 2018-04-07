#include "LinkQueue.h"

template<typename T>
LinkQueue<T>::LinkQueue() {
	front = new Node<T>;
	rear = front;
}

template<typename T>
LinkQueue<T>::~LinkQueue() {
	Node<T>* p;
	while (front != rear) {
		p = front;
		front = p->next;
		delete p;
	}
	delete rear;
}

template<typename T>
void LinkQueue<T>::enQueue(T element) {
	Node<T>* s = new Node<T>;
	s->data = element;
	s->next = nullptr;
	rear->next = s;
	rear = s;
}

template<typename T>
void LinkQueue<T>::deQueue() {
	Node<T>* p = front->next;
	front->next = p->next;
	delete p;
}

template<typename T>
T LinkQueue<T>::getFront() {
	return front->next->data;
}

template<typename T>
bool LinkQueue<T>::empty() {
	if (front == rear)
		return true;
	return false;
}

