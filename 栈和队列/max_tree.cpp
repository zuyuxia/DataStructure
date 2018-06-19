// 问题的描述：数组变树
//		给定一个没有重复元素的数组，利用其中的元素构建一个MaxTree的树（二叉树），返回的数组为对应的父节点在原数组中的编号
//		MaxTree的定义为：对于每棵子树，根元素为子树的最大值
// 建树方法：对于每一个元素，找到左边第一个比它大的元素，找到右边第一个比它大的元素，取较小的元素作为根

// 测试用例有3组：
//		1、空数组
//			输入：arr
//			输出：arr
//		2、普通数组
//			输入：3,1,4,2
//			输出：2,0,-1,2
//		3、普通数组
//			输入：3,4,5,1,2
//			输出：1,2,-1,4,2
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

vector<int> MaxTree(vector<int> &nums) {
	if (nums.empty())
		return{};

	vector<int> left_index, right_index, result;
	// 辅助栈，用来找第i个元素左右第一个大于它的元素
	stack<int> assistant_stack;

	// 先找左边的
	for (int i = 0; i < nums.size(); ++i) {
		while (!assistant_stack.empty() && nums[assistant_stack.top()] <= nums[i])
			assistant_stack.pop();
		if (assistant_stack.empty())
			left_index.push_back(-1);
		else
			left_index.push_back(assistant_stack.top());
		assistant_stack.push(i);
	}

	// 清空辅助栈
	while (!assistant_stack.empty())
		assistant_stack.pop();

	// 再找右边的
	for (int i = nums.size() - 1; i >= 0; --i) {
		while (!assistant_stack.empty() && nums[assistant_stack.top()] <= nums[i])
			assistant_stack.pop();
		if (assistant_stack.empty())
			right_index.push_back(-1);
		else
			right_index.push_back(assistant_stack.top());
		assistant_stack.push(i);
	}
	// 因为是逆序，所以需要对right_index进行逆序处理
	reverse(right_index.begin(), right_index.end());

	// 根据左右两个vector来确定各个元素的父节点
	int min_value = 0;
	for (int i = 0; i < nums.size(); ++i) {
		if (left_index[i] == -1 && right_index[i] == -1)
			result.push_back(-1);
		else if (left_index[i] == -1 || right_index[i] == -1) {
			min_value = (left_index[i] > 0) ? left_index[i] : right_index[i];
			result.push_back(min_value);
		}
		else {
			min_value = (nums[left_index[i]] < nums[right_index[i]]) ? left_index[i] : right_index[i];
			result.push_back(min_value);
		}
	}

	return result;
}

int main() {
	// 空数组
	//vector<int> nums;

	// 普通数组
	//vector<int> nums = { 3,1,4,2 };
	vector<int> nums = { 3,4,5,1,2 };

	vector<int> result;

	result = MaxTree(nums);

	for (int i = 0; i < result.size(); ++i)
		cout << result[i] << "\t";
	cout << endl;

	system("pause");
	return 0;
}