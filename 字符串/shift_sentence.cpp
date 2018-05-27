// 问题的描述：字符串移位
//		给定一个字符串，将字符串中[0, i]的前缀移到右边，[i + 1, N - 1]的后缀移到左边
//		如 string = "ABCDE"，i = 2，移动后：string = "DEABC"
// 第一种解法：O(N) O(N)  用一个新的string保存结果
// 第二种解法：O(N) O(1)  灵活运用逆序函数，对[0, i]进行逆序，对[i + 1, N - 1]进行逆序，最后对整个字符串进行逆序

// 测试用例有2组：
//		1、空字符串
//			输入：
//			string sentence = "";
//			输出：""
//		2、sentence为普通字符串
//			输入：
//			string sentence = "ABCDE"; index = 2;
//			输出："DEABC"

#include <iostream>
#include <string>

using namespace std;

/*
// 第一种解法：借助string保存结果
void ShiftSentence(string &sentence, int index) {
	if (sentence.size() == 0 || index < 0 || index >= sentence.size() - 1)
		return;

	string result = "";
	if (index > sentence.size() - 1)
		index = sentence.size() - 1;

	// 将[0, index]移到右边
	for (int i = 0; i <= index; ++i)
		result = result + sentence[i];

	// 将[index + 1, N - 1]移到左边
	for (int i = sentence.size() - 1; i > index; --i)
		result = sentence[i] + result;

	sentence = result;
}
*/

// 第二种解法：灵活运用逆序函数
// 逆序函数，作用于一个闭区间[begin, end]
void ReverseWord(string &sentence, int begin, int end) {
	if (sentence.size() == 0 || (begin >= end))
		return;

	for (int i = begin; i <= (begin + end) / 2; ++i) {
		swap(sentence[i], sentence[end + begin - i]);
	}
}

void ShiftSentence(string &sentence, int index) {
	if (sentence.size() == 0 || index < 0 || index >= sentence.size() - 1)
		return;

	// 先对[0, i]进行逆序
	ReverseWord(sentence, 0, index);

	// 再对[i + 1, N - 1]进行逆序
	ReverseWord(sentence, index + 1, sentence.size() - 1);

	// 最后对整个sentence进行逆序
	ReverseWord(sentence, 0, sentence.size() - 1);
}

int main() {
	// 空字符串
	// string sentence = "";

	// sentence为普通字符串
	string sentence = "ABCDE";

	ShiftSentence(sentence, 2);

	cout << sentence << endl;

	system("pause");
	return 0;
}