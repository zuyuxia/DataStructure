#ifndef SEQSTACK_H
#define SEQSTACK_H



template<typename T>
class SeqStack {
public:
	SeqStack();
	~SeqStack() {}

	void Push(T data);
	T Pop();
	T GetTop();
	bool Empty();
	bool Full();
private:
	static const int max_size = 100;
	T stack[max_size];
	int top_;
};

#endif