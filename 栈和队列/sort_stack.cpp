// 问题的描述：栈的排序
//		给定一个栈，按照栈顶到栈底从大到小对栈进行排序，要求最多只使用一个额外栈存放临时数据
// 		不断将栈中的元素放到辅助栈中，如果当前元素大于辅助栈的栈顶元素时，将辅助栈的元素依次弹回栈中，放好当前元素
// 像倒水一样，不断倒过来倒过去

// 测试用例有3组：（从左到右<--->从栈顶到栈底）
//		1、空栈
//			输入：
//			输出：
//		2、随机的栈
//			输入：5,4,9,7,8
//			输出：9,8,7,5,4
//		3、顺序栈
//			输入：9,8,7,5,4
//			输出：9,8,7,5,4

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void SortStack(stack<int> &data) {
	if (data.empty())
		return;

	stack<int> assistant_stack;
	int top_element = 0;
	while (!data.empty()) {
		top_element = data.top();
		data.pop();
		
		while (!assistant_stack.empty() && assistant_stack.top() < top_element) {
			data.push(assistant_stack.top());
			assistant_stack.pop();
		}
		assistant_stack.push(top_element);
	}

	while (!assistant_stack.empty()) {
		data.push(assistant_stack.top());
		assistant_stack.pop();
	}
}

int main() {
	// 空栈
	//vector<int> nums;

	// 随机的栈
	//vector<int> nums = { 5,4,9,7,8 };

	// 顺序栈
	vector<int> nums = { 9,8,7,5,4 };
	stack<int> data;
	for (int i = 0; i < nums.size(); ++i)
		data.push(nums[i]);

	SortStack(data);

	while (!data.empty()) {
		cout << data.top() << endl;
		data.pop();
	}

	system("pause");
	return 0;
}