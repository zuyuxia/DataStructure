// 问题的描述：荷兰三色国旗问题
//		给定一个只包含0、1、2的数组，要求返回排序后的数组
// 将0全部放到前面，将2全部放到后面

// 测试用例有2组：
//		1、空数组
//			输入：[]
//			输出：[]
//		2、正常数组
//			输入：[0, 1, 1, 0, 2, 2]
//			输出：[0, 0, 1, 1, 2, 2]

#include <iostream>
#include <vector>

using namespace std;

void SortThreeColors(vector<int> &nums, int array_length) {
	if (nums.empty() || array_length <= 1)
		return;

	int zero_index = -1, two_index = array_length;
	for (int i = 0; i < array_length; ++i) {
		if (nums[i] == 1)
			continue;
		else if (nums[i] == 0) {
			swap(nums[i], nums[++zero_index]);
		}
		else{
			swap(nums[i], nums[--two_index]);
			--i;
			array_length = two_index;
		}
	}
}

int main() {
	// 空数组
	//vector<int> nums;

	// 正常数组
	vector<int> nums = { 0, 1, 1, 0, 2, 2 };

	SortThreeColors(nums, nums.size());

	for (int i = 0; i < nums.size(); ++i)
		cout << nums[i] << "\t";

	cout << endl;

	system("pause");
	return 0;
}