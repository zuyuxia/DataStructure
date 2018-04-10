#include "CirQueue.h"

template<typename T>
CirQueue<T>::CirQueue() {
	front_ = 0;
	rear_ = 0;
}

template<typename T>
CirQueue<T>::~CirQueue() {
}

template<typename T>
void CirQueue<T>::EnQueue(T element) {
	if (full()) {
		std::cout << "Queue is full\n";
	}
	else {
		data[rear_] = element;
		rear_ = (rear_ + 1) % max_size;
	}
}

template<typename T>
void CirQueue<T>::DeQueue() {
	if (empty()) {
		std::cout << "Queue is empty\n";
	}
	else {
		front_ = (front_ + 1) % max_size;
	}
}

template<typename T>
T CirQueue<T>::GetFront() {
	return data[front_];
}

template<typename T>
bool CirQueue<T>::Empty() {
	if (front_ == rear_)
		return true;
	return false;
}

template<typename T>
bool CirQueue<T>::Full() {
	if (((rear_ + 1) % max_size) == front_)
		return true;
	return false;
}

template<typename T>
int CirQueue<T>::Size() {
	if (empty())
		return 0;
	else if (full())
		return max_size - 1;
	else
		return (rear_ - front_ + max_size) % max_size;
}