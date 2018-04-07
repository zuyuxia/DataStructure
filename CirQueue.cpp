#include "CirQueue.h"

template<typename T>
CirQueue<T>::CirQueue() {
	front = 0;
	rear = 0;
}

template<typename T>
CirQueue<T>::~CirQueue() {
}

template<typename T>
void CirQueue<T>::enQueue(T element) {
	if (full()) {
		std::cout << "Queue is full\n";
	}
	else {
		data[rear] = element;
		rear = (rear + 1) % maxSize;
	}
}

template<typename T>
void CirQueue<T>::deQueue() {
	if (empty()) {
		std::cout << "Queue is empty\n";
	}
	else {
		front = (front + 1) % maxSize;
	}
}

template<typename T>
T CirQueue<T>::getFront() {
	return data[front];
}

template<typename T>
bool CirQueue<T>::empty() {
	if (front == rear)
		return true;
	return false;
}

template<typename T>
bool CirQueue<T>::full() {
	if (((rear + 1) % maxSize) == front)
		return true;
	return false;
}

template<typename T>
int CirQueue<T>::size() {
	if (empty())
		return 0;
	else if (full())
		return maxSize - 1;
	else
		return (rear - front + maxSize) % maxSize;
}