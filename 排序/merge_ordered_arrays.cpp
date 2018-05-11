// 问题的描述：有序数组的合并
//		给定两个有序数组A、B，A的末端有足够的空间容纳B，要求将两个数组合并为一个有序数组
// 关键在于从后向前比较，进行合并

// 测试用例有2组：
//		1、空数组
//			输入：A为[1, 2, 3]，B为[]
//			输出：[1, 2, 3]
//		2、正常数组
//			输入：A为[1, 3, 5, 7]，B为[2, 4, 6]
//			输出：[1, 2, 3, 4, 5, 6, 7]

#include <iostream>
#include <vector>

using namespace std;

void MergeTwoArrays(vector<int> &nums1, vector<int> &nums2, int nums1_length, int nums2_length) {
	if (nums1.empty() || nums1_length == 0) {
		nums1 = nums2;
		return;
	}
	if (nums2.empty() || nums2_length == 0)
		return;

	int nums1_index = nums1_length - 1;
	int nums2_index = nums2_length - 1;
	int merge_index = nums1_length + nums2_length - 1;

	// 循环比较
	while (nums1_index >= 0 && nums2_index >= 0) {
		if (nums1[nums1_index] >= nums2[nums2_index]) {
			nums1[merge_index--] = nums1[nums1_index];
			--nums1_index;
		}
		else {
			nums1[merge_index--] = nums2[nums2_index];
			--nums2_index;
		}
	}

	// 将剩余元素加入nums1中
	while (nums1_index >= 0)
		nums1[merge_index--] = nums1[nums1_index--];

	while (nums2_index >= 0)
		nums1[merge_index--] = nums2[nums2_index--];
}

int main() {
	// 空数组
	//vector<int> nums1 = { 1, 2, 3 };
	//vector<int> nums2;

	// 正常数组
	vector<int> nums1 = { 1, 3, 5, 7, 0, 0, 0};
	vector<int> nums2 = { 2, 4, 6 };

	MergeTwoArrays(nums1, nums2, nums1.size() - nums2.size(), nums2.size());

	for (int i = 0; i < nums1.size(); ++i)
		cout << nums1[i] << "\t";

	cout << endl;

	system("pause");
	return 0;
}