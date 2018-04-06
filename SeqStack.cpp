#include "SeqStack.h"

template<typename T>
SeqStack<T>::SeqStack() :top(-1) {
	
}

template<typename T>
void SeqStack<T>::push(T data) {
	++top;
	stack[top] = data;
}

template<typename T>
T SeqStack<T>::pop() {
	T element;
	element = stack[top];
	--top;
	return element;
}

template<typename T>
T SeqStack<T>::GetTop() {
	return stack[top];
}

template<typename T>
bool SeqStack<T>::Empty() {
	if (top == -1)
		return  true;
	return false;
}

template<typename T>
bool SeqStack<T>::Full() {
	if (top == (MaxSize - 1))
		return  true;
	return false;
}