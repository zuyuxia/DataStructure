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

	void Push(T data);
	T Pop();
	T GetTop();
	bool Empty();
private:
	Node<T>* top_;
	int count_;
};

#endif