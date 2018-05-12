// 问题的描述：需要排序的最短子数组
//		给定一个数组，将其中的某一部分的子数组进行排序即可使得整个数组有序，计算需要排序的最短子数组的长度
// 从左向右遍历找到子数组的最右端，从右向左遍历找到子数组的最左端

// 测试用例有4组：
//		1、空数组
//			输入：[]
//			输出：0
//		2、顺序数组
//			输入：[1, 2, 3, 4, 5, 6]
//			输出：0
//		3、逆序数组
//			输入：[6, 5, 4, 3, 2, 1]
//			输出：6
//		3、部分乱序数组
//			输入：[1, 4, 6, 5, 9, 10]
//			输出：2

#include <iostream>
#include <vector>

using namespace std;

int ShortestSubarray(vector<int> &nums) {
	if (nums.empty() || nums.size() == 1)
		return 0;

	int max_num = nums[0], min_num = nums[nums.size() - 1];
	int begin = 0, end = 0;
	// 找到最短子数组的结束位置end
	for (int i = 1; i < nums.size(); ++i) {
		if (nums[i] > max_num)
			max_num = nums[i];
		else
			end = i;
	}

	// 找到最短子数组的开始位置begin
	for (int i = nums.size() - 2; i >= 0; --i) {
		if (nums[i] < min_num)
			min_num = nums[i];
		else
			begin = i;
	}

	if ((end - begin) == 0)
		return 0;
	else
		return end - begin + 1;
}

int main() {
	// 空数组
	//vector<int> nums;

	// 顺序数组
	//vector<int> nums = { 1, 2, 3, 4, 5, 6 };

	// 逆序数组
	//vector<int> nums = { 6, 5, 4, 3, 2, 1 };

	// 部分乱序数组
	vector<int> nums = { 1, 4, 6, 5, 9, 10 };

	cout << ShortestSubarray(nums) << endl;

	system("pause");
	return 0;
}