#include"SeqList.h"

using std::cout;
using std::string;

template<typename T>
SeqList<T>::SeqList() :length(0) {
	
}

template<typename T>
SeqList<T>::SeqList(int len) : length(len) {
	
}

template<typename T>
SeqList<T>::SeqList(int len, T arr[]):length(len) {
	for (int i = 0; i != len; ++i) {
		data[i] = arr[i];
	}
}

template<typename T>
SeqList<T>::SeqList(const SeqList<T> &sl) :length(sl.length) {
	for (int i = 0; i != sl.length; ++i) {
		data[i] = sl.data[i];
	}
}

template<typename T>
SeqList<T>::~SeqList() {

}

template<typename T>
inline int SeqList<T>::GetLength() {
	return length;
}

template<typename T>
inline T SeqList<T>::Get(int i) {
	return data[i];
}

template<typename T>
string SeqList<T>::Locate(T x) {
	string s = "";
	for (int i = 0; i != length; ++i) {
		if (data[i] == x) {
			s = s + to_string(i + 1) + " ";
		}
	}
	return s;
}

template<typename T>
bool SeqList<T>::Insert(int i, T x) {
	if (length == max_size) {
		cout << "no room for new element\n";
		return false;
	}
	if (i<1 || i>length + 1) {
		cout << "the inserting position is wrong\n";
		return false;
	}
	if (i != length + 1) {
		for (int k = length; k != i - 1; --k) {
			data[k] = data[k - 1];
		}
	}
	data[i - 1] = x;
	++length;
	return true;
}

template<typename T>
bool SeqList<T>::Delete(int i) {
	if (i<1 || i>length) {
		cout << "the deleting position is wrong\n";
		return false;
	}
	if (i != length) {
		for (int k = i - 1; k != length - 1; ++k) {
			data[k] = data[k + 1];
		}
	}
	--length;
	return true;
}

template<typename T>
void SeqList<T>::PrintList() {
	for (int i = 0; i != length; ++i) {
		cout << data[i] << " ";
	}
	cout << "\n";
}