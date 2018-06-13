// 问题的描述：空格替换
//		给定一个包含空格的字符串和字符串的长度，将空格替换为“%20”，假定字符串有足够的空间容纳新增的字符
// 先统计出空格数量，再从后向前遍历进行替换	

// 测试用例有2组：
//		1、空字符串
//			输入：""
//			输出：""
//		2、普通的字符串
//			输入："a b c"
//			输出："a%20b%20c"
//			输入："a  b c"
//			输出："a%20%20b%20c"

#include <iostream>
#include <string>

using namespace std;

void ReplaceSpace(string &str, int length) {
	if (str.size() == 0)
		return;

	// 统计空格的数量
	int space_number = 0;
	for (int i = 0; i < length; ++i) {
		if (str[i] == ' ')
			++space_number;
	}

	int index = length + space_number * 2 - 1;

	// 从后向前进行替换
	for (int i = length - 1; i >= 0; --i) {
		if (str[i] != ' ') {
			str[index--] = str[i];
		}
		else {
			str[index--] = '0';
			str[index--] = '2';
			str[index--] = '%';
		}
	}
}

int main() {
	// 空字符串
	// string str = "";

	// 普通的字符串(c是最后一个字符，后面的空格用来容纳新增字符)
	// string str = "a b c       ";
	string str = "a  b c         ";

	ReplaceSpace(str, 6);
	cout << str << endl;

	system("pause");
	return 0;
}