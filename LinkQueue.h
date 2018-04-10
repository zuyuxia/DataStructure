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

	void EnQueue(T element);
	void DeQueue();
	T GetFront();
	bool Empty();
private:
	Node<T>* front_;
	Node<T>* rear_;
};

#endif