#ifndef LINKSTACK_H
#define LINKSTACK_H

template<typename T>
struct Node {
	T data;
	Node<T>* next;
};

template<typename T>
class LinkStack {
public:
	LinkStack();
	~LinkStack();

	void push(T data);
	T pop();
	T GetTop();
	bool Empty();
private:
	Node<T>* top;
	int count;
};

#endif