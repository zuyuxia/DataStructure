// 问题的描述：可查询最小值的栈
//		定义栈的结构，实现一个能够查询栈中最小值的函数min
// 使用一个辅助栈

// 测试用例有1组：
//		1、入栈顺序： 1 3 2 4 5
//			输出：1

#include <iostream>
#include <stack>

using namespace std;

/*
// 第一种解法，辅助栈与数据栈大小一致，每个位置都对应
class MinStack {
public:
	void pop() {
		data.pop();
		min_element.pop();
	}
	void push(int number) {
		data.push(number);
		if (min_element.empty() || number < min_element.top())
			min_element.push(number);
		else
			min_element.push(min_element.top());
	}
	int min() {
		return min_element.top();
	}
	int top() {
		return data.top();
	}

private:
	stack<int> data, min_element;
};
*/

// 第二种解法，辅助栈比数据栈稍小，只在发现更小元素时把元素压入辅助栈中
class MinStack {
public:
	void pop() {
		if (data.top() == min_element.top())
			min_element.pop();
		data.pop();
	}
	void push(int number) {
		data.push(number);
		if (min_element.empty() || number <= min_element.top())
			min_element.push(number);
	}
	int min() {
		return min_element.top();
	}
	int top() {
		return data.top();
	}

private:
	stack<int> data, min_element;
};

int main() {
	MinStack ms;
	ms.push(1);
	ms.push(3);
	ms.push(2);
	ms.push(4);
	ms.push(5);

	cout << ms.min() << endl;

	ms.pop();

	cout << ms.min() << endl;

	system("pause");
	return 0;
}