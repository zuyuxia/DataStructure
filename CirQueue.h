#ifndef CIRQUEUE_H
#define CIRQUEUE_H

template<typename T>
class CirQueue {
public:
	CirQueue();
	~CirQueue();

	void EnQueue(T element);
	void DeQueue();
	T GetFront();
	bool Empty();
	bool Full();
	int Size();
private:
	static const int max_size = 100;
	T data[max_size];
	int front_;
	int rear_;
};

#endif