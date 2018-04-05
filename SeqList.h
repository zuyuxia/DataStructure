#ifndef SEQLIST_H
#define SEQLIST_H

#include<iostream>
#include<string>

template<typename T>
class SeqList {
public:
	SeqList();
	SeqList(int len);
	SeqList(int len, T arr[]);
	SeqList(const SeqList &sl);
	~SeqList();

	int GetLength();
	T Get(int i);
	std::string Locate(T x);
	bool Insert(int i, T x);
	bool Delete(int i);
	void PrintList();
private:
	static const int max_size = 100;
	int length;
	T data[max_size];
};

#endif