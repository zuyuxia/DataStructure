// 问题的描述：栈的反转
//		实现栈的反转，规定只能用递归函数和栈的pop操作实现，不能使用其他数据结构
// 两个递归函数，一个用来实现反转，一个用来得到栈底元素

// 测试用例有1组：
//		1、原栈： 5,4,9,7,8
//			输出：8,7,9,4,5

#include <iostream>
#include <stack>

using namespace std;

// 得到栈底元素
int GetStackBottom(stack<int> &data) {
	int top_data = data.top();
	data.pop();
	if (data.empty())
		return top_data;
	else {
		int result = GetStackBottom(data);
		data.push(top_data);
		return result;
	}
}

// 栈的反转
void ReverseStack(stack<int> &data) {
	if (data.empty())
		return;
	
	int bottom_element = GetStackBottom(data);
	ReverseStack(data);
	data.push(bottom_element);
	
}

int main() {
	// 普通栈
	vector<int> nums = { 8,7,9,4,5 };
	stack<int> data;
	for (int i = 0; i < nums.size(); ++i)
		data.push(nums[i]);

	ReverseStack(data);

	while (!data.empty()) {
		cout << data.top() << "\t";
		data.pop();
	}
	cout << endl;

	system("pause");
	return 0;
}