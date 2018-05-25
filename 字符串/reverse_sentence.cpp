// 问题的描述：句子逆序
//		给定一个字符串，只将字符串中的单词间的顺序做调整
//		如 string = "fish loves panda"，逆序后的结果：string = "panda loves fish"
// 第一种解法：借助stack来解题
// 第二种解法：实现一个能够在指定范围内进行逆序的函数，再对string进行第一次逆序，最后对每一个单词进行逆序

// 测试用例有2组：
//		1、空字符串
//			输入：
//			string sentence = "";
//			输出：""
//		2、sentence为普通字符串
//			输入：
//			string sentence = "fish loves panda";
//			输出："panda loves fish"

#include <iostream>
#include <string>
#include <stack>

using namespace std;

/*
// 第一种解法：借助stack来实现句子的逆序
string ReverseSentence(string sentence) {
	if (sentence.size() == 0 || sentence.size() == 1)
		return sentence;

	// 将sentence拆分成words，放进stack中
	stack<string> container;
	string word = "";
	for (int i = 0; i < sentence.size(); ++i) {
		if (sentence[i] != ' ')
			word += sentence[i];
		else {
			container.push(word);
			word = "";
		}
	}
	container.push(word);

	// 将words逆序组成新的sentence
	string result = "";
	while (container.size() > 1) {
		result = result + container.top() + " ";
		container.pop();
	}
	result = result + container.top();

	return result;
}
*/

// 第二种解法
// 逆序函数，作用于一个闭区间[begin, end]
void ReverseWord(string &sentence, int begin, int end) {
	if (sentence.size() == 0 || (begin >= end))
		return;

	for (int i = begin; i <= (begin + end) / 2; ++i) {
		swap(sentence[i], sentence[end + begin - i]);
	}
}

// 逆序函数
string ReverseSentence(string sentence) {
	if (sentence.size() == 0 || sentence.size() == 1)
		return sentence;

	// 先将整个句子当做一个整体进行逆序
	ReverseWord(sentence, 0, sentence.size() - 1);

	// 再对句子中的每一个单词进行逆序
	int begin = 0;
	for (int i = 0; i < sentence.size(); ++i) {
		if (sentence[i] == ' ') {
			ReverseWord(sentence, begin, i - 1);
			begin = i + 1;
		}
	}
	ReverseWord(sentence, begin, sentence.size() - 1);

	return sentence;
}

int main() {
	// 空字符串
	// string sentence = "";

	// sentence为普通字符串
	string sentence = "fish loves panda";

	cout << ReverseSentence(sentence) << endl;

	system("pause");
	return 0;
}