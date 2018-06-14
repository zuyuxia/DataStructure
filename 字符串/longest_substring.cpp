// 问题的描述：最长无重复子串
//		给定一个字符串，找到该字符串中最长无重复子串的长度
// 设置一个哈希表，记录当前字符上一次出现的位置；设置一个变量，记录s[i - 1]为结尾时的最长无重复子串的长度

// 测试用例有2组：
//		1、空字符串
//			输入：""
//			输出：0
//		2、普通的字符串
//			输入："abcd"
//			输出：4
//			输入："abcb"
//			输出：3

#include <iostream>
#include <map>
#include <string>

using namespace std;

int LongestSubstring(const string &str) {
	if (str.size() <= 1)
		return str.size();

	map<char, int> index_table;
	int pre = 0;
	int result = 0;

	for (int i = 0; i < str.size(); ++i) {
		// 先判断i处的字符是否在前面已出现过，如果没出现过，那么最长的substring = i + 1
		if (index_table.find(str[i]) == index_table.end()) {
			if (i + 1 > result) {
				result = i + 1;
			}
			pre = i + 1;
		}
		else {
			// 判断以str[i - 1]为结尾的substring的开始字符的位置是否比上一次str[i]出现的小
			if (i - pre <= index_table[str[i]]) {
				if (i - index_table[str[i]] > result) {
					result = i - index_table[str[i]];
				}
				pre = i - index_table[str[i]];
			}
			else {
				if (pre + 1 > result) {
					result = pre + 1;
				}
				pre = pre + 1;
			}
		}
		index_table[str[i]] = i;
	}

	return result;
}

int main() {
	// 空字符串
	// string str = "";

	// 普通的字符串
	// string str = "abcd";
	string str = "abcb";

	cout << LongestSubstring(str) << endl;

	system("pause");
	return 0;
}