// 问题的描述：相邻两数最大差值
//		给定一个数组，算出排序后相邻两数的最大差值
// 桶排序，桶比数组长度大1，数组最大值单独放在一个桶中

// 测试用例有4组：
//		1、空数组或数组大小为1的数组
//			输入：[]  or [1]
//			输出：0
//		2、相同数值的数组
//			输入：[2, 2, 2, 2, 2, 2]
//			输出：0
//		3、顺序数组
//			输入：[1, 2, 3, 4, 5, 6]
//			输出：1
//		4、普通数组
//			输入：[7, 9, 3, 4, 2, 1, 8]
//			输出：3

#include <iostream>
#include <vector>
#include <set>

using namespace std;

// 求相邻两数最大差值
int MaxDifference(vector<int> &nums) {
	if (nums.empty() || nums.size() == 1)
		return 0;

	// 构造桶，vector表示桶，set用来存放一个桶中的数据
	vector<set<int>> bucket(nums.size() + 1);

	// 遍历原数组找出数组中最大值和最小值
	int max_num = nums[0], min_num = nums[0];
	for (int i = 0; i < nums.size(); ++i) {
		if (nums[i] > max_num)
			max_num = nums[i];
		if (nums[i] < min_num)
			min_num = nums[i];
	}

	// 如果最大值与最小值相同，则数组为一个相同值数组
	if (max_num == min_num)
		return 0;

	// 计算区间间隔
	double bucket_interval = 1.0 * (max_num - min_num) / nums.size();

	// 将数据放到各个桶中
	int bucket_index = 0;
	for (int i = 0; i < nums.size(); ++i) {
		bucket_index = (int)((nums[i] - min_num) / bucket_interval);
		bucket[bucket_index].insert(nums[i]);
	}

	// 比较相邻桶的最大值和最小值之差，利用set的begin和rbegin迭代器
	int max_bucket = 0, min_bucket = 0;
	int result = 0;
	for (int i = 0; i < bucket.size() - 1; ++i) {
		// 如果桶是空桶，则跳过
		if (bucket[i].empty())
			continue;

		// 找当前桶的最大值
		max_bucket = *(bucket[i].rbegin());
		
		// 找到下一个桶的最小值
		while (bucket[i + 1].empty())
			++i;
		if (i >= bucket.size() - 1)
			break;
		min_bucket = *(bucket[i + 1].begin());

		if (result < min_bucket - max_bucket)
			result = min_bucket - max_bucket;
	}
	return result;
}

int main() {
	// 空数组
	// vector<int> nums;

	// 相同数组数组
	// vector<int> nums = {2, 2, 2, 2, 2, 2};

	// 顺序数组
	// vector<int> nums = { 1, 2, 3, 4, 5, 6 };

	// 普通数组
	vector<int> nums = { 7, 9, 3, 4, 2, 1, 8 };

	cout << MaxDifference(nums) << endl;

	system("pause");
	return 0;
}