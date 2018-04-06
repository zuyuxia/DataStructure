#ifndef SEQSTACK_H
#define SEQSTACK_H

const int MaxSize = 100;

template<typename T>
class SeqStack {
public:
	SeqStack();
	~SeqStack() {}

	void push(T data);
	T pop();
	T GetTop();
	bool Empty();
	bool Full();
private:
	T stack[MaxSize];
	int top;
};

#endif