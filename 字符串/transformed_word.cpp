// 问题的描述：词语变形
//		给定两个字符串，判断它们是否互为变形词，即A、B中字符种类和字符出现的次数相同
// 哈希

// 测试用例有3组：
//		1、空字符串
//			输入：
//			string sequence1 = "";
//			string sequence2 = "";
//			输出：false
//		2、A、B互为变形词
//			输入：
//			string sequence1 = "abc";
//			string sequence2 = "cab";
//			输出：true
//		3、A、B互不为变形词
//			输入：
//			string sequence1 = "abc";
//			string sequence2 = "dab";
//			输出：false

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

bool CheckTransformWord(const string &sequence1, const string &sequence2) {
	if (sequence1.empty() || sequence2.empty() || (sequence1.size() != sequence2.size()))
		return false;

	unordered_map<char, int> container;
	for (int i = 0; i < sequence1.size(); ++i)
		++container[sequence1[i]];

	for (int i = 0; i < sequence2.size(); ++i) {
		--container[sequence2[i]];
		if (container[sequence2[i]] < 0)
			return false;
	}
	return true;
}

int main() {
	// 空字符串
	// string sequence1 = "";
	// string sequence2 = "";

	// A、B互为变形词
	// string sequence1 = "abc";
	// string sequence2 = "cab";

	// A、B互不为变形词
	string sequence1 = "abc";
	string sequence2 = "dab";

	if (CheckTransformWord(sequence1, sequence2))
		cout << "true" << endl;
	else
		cout << "false" << endl;

	system("pause");
	return 0;
}