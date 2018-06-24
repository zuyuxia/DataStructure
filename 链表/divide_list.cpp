// 问题的描述：链表分化
//		给定一个单链表以及一个阈值，对小于阈值的结点放到左边，等于阈值的结点放到中间，大于阈值的结点放到右边
//		保证两种结点内部的位置关系不变
// 分成三个小链表，再组合成一个链表

// 测试用例有4组：
//		1、空链表		threshold = 2
//			输入：NULL 2
//			输出：NULL
//		2、非空链表	threshold = 3
//			输入：{1,4,2,5} 3
//			输出：1,2,4,5
//		3、非空链表	threshold = 8
//			输入：{1,4,2,5} 8
//			输出：1,4,2,5
//		4、非空链表	threshold = 0
//			输入：{1,4,2,5} 0
//			输出：1,4,2,5

#include <iostream>
#include <vector>

using namespace std;

// 链表结点的定义
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :val(x), next(nullptr) {}
};

// 创建一个链表
ListNode* CreateList(vector<int> &nums) {
	if (nums.empty())
		return nullptr;

	ListNode *head = new ListNode(nums[0]);
	ListNode *temp_node = head, *new_node = nullptr;
	for (int i = 1; i < nums.size(); ++i) {
		new_node = new ListNode(nums[i]);
		temp_node->next = new_node;
		temp_node = new_node;
	}
	return head;
}

// 回收链表的内存
void FreeList(ListNode *head) {
	if (head == nullptr)
		return;

	ListNode *free_node = nullptr;
	while (head != nullptr) {
		free_node = head;
		head = head->next;
		delete free_node;
	}
}

// 链表的分化
ListNode* DivideList(ListNode *head, int threshold) {
	if (head == nullptr || head->next == nullptr)
		return head;

	ListNode *small_head = new ListNode(0), *small_tail = small_head;
	ListNode *medium_head = new ListNode(0), *medium_tail = medium_head;
	ListNode *big_head = new ListNode(0), *big_tail = big_head;

	// 分成三个小链表
	while (head != nullptr) {
		if (head->val < threshold) {
			small_tail->next = head;
			small_tail = head;
		}
		else if (head->val == threshold) {
			medium_tail->next = head;
			medium_tail = head;
		}
		else {
			big_tail->next = head;
			big_tail = head;
		}
		head = head->next;
	}

	// 组合起来
	if (medium_head != medium_tail) {
		small_tail->next = medium_head->next;
		medium_tail->next = big_head->next;
	}
	else {
		small_tail->next = big_head->next;
	}
	big_tail->next = nullptr;
	head = small_head->next;

	// 释放掉辅助结点
	delete small_head;
	delete medium_head;
	delete big_head;

	return head;
}

int main() {
	// 空链表
	//vector<int> nums;

	// 非空链表
	vector<int> nums = { 1,4,2,5 };

	int threshold = 3;

	ListNode *root = CreateList(nums);

	ListNode *head = DivideList(root, threshold);

	// 遍历链表，输出元素值
	ListNode *node = head;
	while (node != nullptr) {
		cout << node->val << "\t";
		node = node->next;
	}
	cout << endl;

	FreeList(head);

	system("pause");
	return 0;
}