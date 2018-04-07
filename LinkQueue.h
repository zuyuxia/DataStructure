#ifndef LINKQUEUE_H
#define LINKQUEUE_H

template<typename T>
struct Node {
	T data;
	Node<T>* next;
};

template<typename T>
class LinkQueue {
public:
	LinkQueue();
	~LinkQueue();

	void enQueue(T element);
	void deQueue();
	T getFront();
	bool empty();
private:
	Node<T>* front;
	Node<T>* rear;
};

#endif