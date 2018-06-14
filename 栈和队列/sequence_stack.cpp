#include "SeqStack.h"

template<typename T>
SeqStack<T>::SeqStack() :top_(-1) {
	
}

template<typename T>
void SeqStack<T>::Push(T data) {
	++top_;
	stack[top_] = data;
}

template<typename T>
T SeqStack<T>::Pop() {
	T element;
	element = stack[top_];
	--top_;
	return element;
}

template<typename T>
T SeqStack<T>::GetTop() {
	return stack[top_];
}

template<typename T>
bool SeqStack<T>::Empty() {
	if (top_ == -1)
		return  true;
	return false;
}

template<typename T>
bool SeqStack<T>::Full() {
	if (top_ == (max_size - 1))
		return  true;
	return false;
}