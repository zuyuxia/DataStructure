// 问题的描述：合法括号序列判断
//		给定一个只包含括号“()”的字符串，判断字符串中的括号是否合法
// 设置一个变量，记录左括号和右括号的差值，遍历字符串

// 测试用例有2组：
//		1、空字符串
//			输入：""
//			输出：true
//		2、普通的字符串
//			输入："(())"  "()()"
//			输出：true
//			输入："(()" "())"
//			输出：false

#include <iostream>
#include <string>

using namespace std;

bool CheckParentheses(const string &str) {
	if (str.size() == 0)
		return true;

	int count = 0;
	for (int i = 0; i < str.size(); ++i) {
		if (str[i] == '(')
			++count;
		else
			--count;
		if (count < 0)
			return false;
	}
	if (count != 0)
		return false;

	return true;
}

int main() {
	// 空字符串
	// string str = "";

	// 普通的字符串
	// string str = "(())";
	// string str = "()()";

	// string str = "(()";
	string str = "())";

	if (CheckParentheses(str))
		cout << "true" << endl;
	else
		cout << "false" << endl;

	system("pause");
	return 0;
}