// 问题的描述：小范围排序
//		已知一个几乎有序的数组（要把数组排好序，则每个元素移动的距离可以不超过k，并且k相较于数组的大小来说很小）
// 解决方案：改进后的堆排序（最小堆）

// 测试用例有3组：
//		1、空数组
//			输入：[]
//			输出：[]
//		2、顺序数组
//			输入：[1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
//			输出：[1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
//		3、基本有序数组，输出为：
//			输入：[2, 1, 4, 3, 6, 5, 8, 7, 10, 9]	10	2
//			输出：[1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

#include <iostream>
#include <vector>

using namespace std;

// 堆排序中的关键函数，调整数组[begin, end]满足堆的定义
void HeapAdjust(vector<int> &nums, int begin, int end) {
	int root_value = nums[begin];

	for (int j = 2 * begin + 1; j <= end; j = j * 2 + 1) {
		if (j < end && nums[j + 1] < nums[j])
			++j;
		if (root_value < nums[j])
			break;
		nums[begin] = nums[j];
		begin = j;
	}
	nums[begin] = root_value;
}

// 堆排序（从大到小的顺序）
void HeapSort(vector<int> &nums, int array_length) {
	if (nums.empty() || array_length == 1)
		return;

	// 将数组调整成为一个最小堆
	for (int i = array_length / 2 - 1; i >= 0; --i)
		HeapAdjust(nums, i, array_length - 1);

	// 不断的将最小值调至数组第n、n - 1、n - 2......位，同时每次交换之后，对剩下的元素进行调整
	for (int i = array_length - 1; i > 0; --i) {
		swap(nums[0], nums[i]);
		HeapAdjust(nums, 0, i - 1);
	}
}

// 解决问题的函数代码
void SortElement(vector<int> &nums, int array_length, int k) {
	if (nums.empty() || array_length == 1)
		return;

	// 数组temp_nums用来保存每次移出的最小值
	vector<int> temp_nums(array_length, 0);

	// 先将数组的前k项构建为一个小顶堆
	for (int i = k / 2 - 1; i >= 0; --i)
		HeapAdjust(nums, i, k - 1);

	int index_temp_nums = 0;
	temp_nums[index_temp_nums] = nums[0];

	// 将数组的[k, array_length - 1]的每一个数依次加入到最小堆中，调整满足小顶堆，然后将堆顶取出
	for (int j = k; j < array_length; ++j) {
		nums[0] = nums[j];
		HeapAdjust(nums, 0, k - 1);
		temp_nums[++index_temp_nums] = nums[0];
	}

	// 最后剩下一个k项的小顶堆数组，对这个k项的数组进行堆排序即可（注意这里的是一个从大到小的顺序）
	HeapSort(nums, k);

	// 将这k项依次放入temp_nums中
	for(int i = k - 1; i >= 0; --i)
		temp_nums[index_temp_nums++] = nums[i];

	// 再将数值copy回原数组
	for (int i = 0; i < array_length; ++i)
		nums[i] = temp_nums[i];
}

int main() {
	// 空数组
	// vector<int> nums;

	// 顺序数组
	// vector<int> nums = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	// 基本有序数组
	vector<int> nums = { 2, 1, 4, 3, 6, 5, 8, 7, 10, 9 };
	
	SortElement(nums, 10, 2);

	for (int i = 0; i < nums.size(); ++i)
		cout << nums[i] << "\t";

	cout << endl;

	system("pause");
	return 0;
}