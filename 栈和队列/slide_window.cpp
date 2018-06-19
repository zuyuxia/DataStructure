// 问题的描述：滑动窗口
//		给定一个整形数组，和一个w(保证w<n)宽度的窗口。
//		窗口每次向右滑动一个单位，从数组最左边滑动到最右边，要求返回一个n-w+1的数组，记录窗口每次滑动状态下的最大值
// 借助双端队列

// 测试用例有3组：
//		1、空数组或者w == 1
//			输入：arr
//			输出：arr
//		2、普通数组，w == 3
//			输入：4,3,5,4,3,3,6,7
//			输出：5,5,5,4,6,7
//		3、普通数组，w == 5
//			输入：4,3,5,4,3,3,6,7
//			输出：5,5,6,7
#include <iostream>
#include <vector>
#include <deque>

using namespace std;

void SlideWindow(vector<int> &nums, vector<int> &result, int width) {
	if (nums.empty() || width == 1) {
		result = nums;
		return;
	}

	deque<int> help_queue;
	for (int i = 0; i < nums.size(); ++i) {
		while (!help_queue.empty() && nums[help_queue.back()] < nums[i])
			help_queue.pop_back();
		help_queue.push_back(i);
		
		if (help_queue.front() == i - width)
			help_queue.pop_front();

		if (i < width - 1)
			continue;

		result.push_back(nums[help_queue.front()]);
	}
}

int main() {
	// 空数组
	//vector<int> nums;

	// 普通数组
	vector<int> nums = { 4,3,5,4,3,3,6,7 };

	vector<int> result;

	SlideWindow(nums, result, 5);

	for (int i = 0; i < result.size(); ++i)
		cout << result[i] << "\t";
	cout << endl;

	system("pause");
	return 0;
}