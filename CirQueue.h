#ifndef CIRQUEUE_H
#define CIRQUEUE_H

const int maxSize = 100;

template<typename T>
class CirQueue {
public:
	CirQueue();
	~CirQueue();

	void enQueue(T element);
	void deQueue();
	T getFront();
	bool empty();
	bool full();
	int size();
private:
	T data[maxSize];
	int front;
	int rear;
};

#endif