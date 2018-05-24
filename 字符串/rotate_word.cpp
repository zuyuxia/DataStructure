// 问题的描述：旋转词
//		给定两个字符串，判断它们是否互为旋转词，即A字符串前面一部分字符移到后面形成的新字符串与B字符串相同
//		如 A = "1234", B = "2341"就是其中的一个旋转词
// 关键点在于(A + A)形成的新字符串，包含了A所有的旋转词

// 测试用例有3组：
//		1、空字符串
//			输入：
//			string sequence1 = "";
//			string sequence2 = "";
//			输出：false
//		2、A、B互为旋转词
//			输入：
//			string sequence1 = "abcd";
//			string sequence2 = "cdab";
//			输出：true
//		3、A、B互不为旋转词
//			输入：
//			string sequence1 = "abcd";
//			string sequence2 = "dcab";
//			输出：false

#include <iostream>
#include <string>

using namespace std;

bool CheckRotateWord(const string &sequence1, const string &sequence2) {
	if (sequence1.empty() || sequence2.empty() || (sequence1.size() != sequence2.size()))
		return false;

	string synthesis_word = sequence1 + sequence1;
	if (synthesis_word.find(sequence2) != string::npos)
		return true;
	else
		return false;
}

int main() {
	// 空字符串
	// string sequence1 = "";
	// string sequence2 = "";

	// A、B互为旋转词
	// string sequence1 = "abcd";
	// string sequence2 = "cdab";

	// A、B互不为旋转词
	string sequence1 = "abcd";
	string sequence2 = "dcab";

	if (CheckRotateWord(sequence1, sequence2))
		cout << "true" << endl;
	else
		cout << "false" << endl;

	system("pause");
	return 0;
}