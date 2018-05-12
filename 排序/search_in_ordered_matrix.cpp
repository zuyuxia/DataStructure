// 问题的描述：有序矩阵查找
//		给定一个矩阵，矩阵的每一行都是从小到大排列，每一列也是从小到大排列。要求判断矩阵中是否存在target_value
// 关键在于从右上角开始查找

// 测试用例有2组：
//		1、空矩阵
//			输入：[]
//			输出：false
//		2、target_value在矩阵中
//			输入：
//				target_value = 3
//				[0, 1, 2, 5]
//				[2, 3, 4, 7]
//				[4, 4, 4, 8]
//				[5, 7, 7, 9]
//			输出：true
//		3、target_value不在矩阵中
//			输入：
//				target_value = -1  or  target_value = 11
//				[0, 1, 2, 5]
//				[2, 3, 4, 7]
//				[4, 4, 4, 8]
//				[5, 7, 7, 9]
//			输出：false

#include <iostream>
#include <vector>

using namespace std;

bool FindTargetValue(vector<vector<int>> &matrix, int target_value) {
	if (matrix.empty())
		return false;

	int row = 0, col = matrix[0].size() - 1;
	while (row < matrix.size() && col >= 0) {
		if (matrix[row][col] == target_value)
			return true;
		else if (matrix[row][col] < target_value)
			++row;
		else
			--col;
	}
	return false;
}

int main() {
	// 空矩阵
	// vector<vector<int>> matrix;

	// 矩阵
	vector<vector<int>> matrix = { { 0, 1, 2, 5 },
								 { 2, 3, 4, 7 },
								 { 4, 4, 4, 8 },
								 { 5, 7, 7, 9 },
								};

	int target_value = 3;

	if (FindTargetValue(matrix, target_value))
		cout << "true" << endl;
	else
		cout << "false" << endl;

	system("pause");
	return 0;
}