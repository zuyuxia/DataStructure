// 问题的描述：判断数组中是否有重复值
//		给定一个数组和它的长度，判断数组中是否有重复值，要求空间复杂度为O(1)
// 解决方案：堆排序（非递归）

// 测试用例有3组：
//		1、空数组
//			输入：[]
//			输出：[]
//		2、无重复值数组
//			输入：[1, 2, 3, 4, 5, 6, 7]
//			输出：true
//		3、有重复值数组
//			输入：[3, 5, 1, 4, 2, 5, 6]
//			输出：false

#include <iostream>
#include <vector>

using namespace std;

// 堆排序中的调整堆函数，使得剩余的数满足堆定义的要求
void HeapAdjust(vector<int> &nums, int begin, int end) {
	if (nums.empty() || begin >= end)
		return;

	// root_value用来保存要调整的根节点的值
	int root_value = nums[begin];

	for (int j = 2 * begin + 1; j <= end; j = 2 * j + 1) {
		if (j < end && nums[j] < nums[j + 1])
			++j;
		if (nums[j] < root_value)
			break;
		nums[begin] = nums[j];
		begin = j;
	}
	nums[begin] = root_value;
}

// 堆排序
void HeapSort(vector<int> &nums, int array_length) {
	if (nums.empty() || array_length <= 1)
		return;

	// 将数组构建成一个堆
	for (int i = array_length / 2 - 1; i >= 0; --i)
		HeapAdjust(nums, i, array_length - 1);

	// 不断将最大值移到n, n - 1, n - 2......位上
	for (int i = array_length - 1; i > 0; --i) {
		swap(nums[0], nums[i]);
		HeapAdjust(nums, 0, i - 1);
	}
}

// 判断重复值函数
bool JudgeDuplicateValue(vector<int> &nums, int array_length) {
	// 先进行堆排序
	HeapSort(nums, array_length);

	// 遍历数组
	for (int i = 0; i < array_length - 1; ++i) {
		if (nums[i] == nums[i + 1])
			return false;
	}
	return true;
}

int main() {
	// 空数组
	// vector<int> nums;

	// 无重复值数组
	// vector<int> nums = { 1, 2, 3, 4, 5, 6, 7 };

	// 有重复值数组
	vector<int> nums = { 3, 5, 1, 4, 2, 5, 6 };

	if (JudgeDuplicateValue(nums, nums.size()))
		cout << "true" << endl;
	else
		cout << "false" << endl;

	system("pause");
	return 0;
}