// 问题的描述：拼接最小字典序
//		给定一个字符串数组，找到所有字符串拼接起来的结果中字典序最小的一种
//		如 vector<string> = {"abc", "de"}，拼接后最小字典序为：string = "abcde"
// 实际上是给数组进行排序，只是排序的比较方法不能按照默认的方式，新的比较方法为：
// 如果 string1 + string2 < string2 + string1，那么string1在前面

// 测试用例有2组：
//		1、空字符串数组
//			输入：vector<string> strs;
//			输出：""
//		2、普通的字符串数组
//			输入：vector<string> strs = {"abc", "de"};
//			输出："abcde"
//			输入：vector<string> strs = {"ba", "b"};
//			输出："bab"

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

// 第一种解法：直接用自带的sort函数，构造新的比较函数
bool CompareString(const string &str1, const string &str2) {
	return (str1 + str2) < (str2 + str1);
}

/*
string SpliceString(vector<string> &strs) {
	if (strs.size() == 0)
		return "";

	sort(strs.begin(), strs.end(), CompareString);

	string res = "";
	for (int i = 0; i < strs.size(); ++i)
		res += strs[i];

	return res;
}
*/

// 第二种解法：自己写一个排序函数（快排）
//快速排序，闭区间[begin, end]
int Partition(vector<string> &strs, int begin, int end) {
	string mark = strs[begin];
	while (begin < end) {
		while (begin < end && !CompareString(strs[end], mark))
			--end;
		strs[begin] = strs[end];
		while (begin < end && CompareString(strs[begin], mark))
			++begin;
		strs[end] = strs[begin];
	}
	strs[begin] = mark;
	return begin;
}

void QuickSort(vector<string> &strs, int begin, int end) {
	if (strs.size() == 0 || begin >= end)
		return;
	int pivot = Partition(strs, begin, end);
	QuickSort(strs, begin, pivot - 1);
	QuickSort(strs, pivot + 1, end);
}

string SpliceString(vector<string> &strs) {
	if (strs.size() == 0)
		return "";

	QuickSort(strs, 0, strs.size() - 1);

	string res = "";
	for (int i = 0; i < strs.size(); ++i)
		res += strs[i];

	return res;
}

int main() {
	// 空字符串数组
	// vector<string> strs;

	// 普通的字符串数组
	// vector<string> strs = {"abc", "de"};
	vector<string> strs = { "ba", "b" };

	cout << SpliceString(strs) << endl;

	system("pause");
	return 0;
}