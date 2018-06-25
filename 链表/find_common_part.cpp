// 问题的描述：打印两个链表的公共值
//		给定两个升序的链表，且链表中无重复元素。打印两个链表的公共值部分
//		同时遍历，相等就打印

// 测试用例有3组：
//		1、空链表（至少一个为空链表）
//			输入：NULL NULL
//			输出：NULL
//		2、非空链表
//			输入：{1,2,3,4,5,6,7} {2,4,6,8,10}
//			输出：2,4,6
//		3、非空链表
//			输入：{1,3,5,7} {2,4,6,8}
//			输出：NULL

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

// 打印链表公共部分
vector<int> FindCommonPart(ListNode *head1, ListNode *head2) {
	if (head1 == nullptr || head2 == nullptr)
		return{};

	vector<int> result;
	while (head1 != nullptr && head2 != nullptr) {
		if (head1->val < head2->val)
			head1 = head1->next;
		else if (head1->val > head2->val)
			head2 = head2->next;
		else {
			result.push_back(head1->val);
			head1 = head1->next;
			head2 = head2->next;
		}
	}
	return result;
}

int main() {
	// 空链表
	//vector<int> nums1;
	//vector<int> nums2;

	// 非空链表
	//vector<int> nums1 = { 1,2,3,4,5,6,7 };
	//vector<int> nums2 = { 2,4,6,8,10 };

	// 非空链表
	vector<int> nums1 = { 1,3,5,7 };
	vector<int> nums2 = { 2,4,6,8 };

	ListNode *head1 = CreateList(nums1);
	ListNode *head2 = CreateList(nums2);

	vector<int> result = FindCommonPart(head1, head2);
	for (int i = 0; i < result.size(); ++i)
		cout << result[i] << "\t";
	cout << endl;

	FreeList(head1);
	FreeList(head2);

	system("pause");
	return 0;
}