// 问题的描述：环形链表插值
//		给定一个元素有序的环形链表（以vector的形式），将一个新的元素val插入到链表中，要求保持链表依旧有序
//		要求先构造出环形链表再进行插值
// 链表为空；链表不为空

// 测试用例有4组：
//		1、空链表    val = 2
//			输入：NULL 2
//			输出：2
//		2、非空链表    val = 2
//			输入：{1,3,4,5,7} 2
//			输出：1,2,3,4,5,7
//		3、非空链表    val = 8
//			输入：{1,3,4,5,7} 8
//			输出：1,3,4,5,7,8
//		4、非空链表    val = 0
//			输入：{1,3,4,5,7} 0
//			输出：0,1,3,4,5,7

#include <iostream>
#include <vector>

using namespace std;

// 链表结点的定义
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :val(x), next(nullptr) {}
};

ListNode* InsertValue(vector<int> &nums, int value) {
	if (nums.size() == 0) {
		ListNode *head = new ListNode(value);
		head->next = head;
		return head;
	}

	// 先构造环形链表
	ListNode *head = new ListNode(nums[0]);
	ListNode *temp = head;
	ListNode *new_node = nullptr;
	for (int i = 1; i < nums.size(); ++i) {
		new_node = new ListNode(nums[i]);
		temp->next = new_node;
		temp = new_node;
	}
	temp->next = head;

	// 再进行插入值
	ListNode *target_node = new ListNode(value);

	// 链表长度为1
	if (nums.size() == 1) {
		head->next = target_node;
		target_node->next = head;
		if (nums[0] < value)
			return head;
		else
			return target_node;
	}

	// 链表长度大于1，遍历链表
	// 1 目标结点插入到链表之中
	ListNode *current_node = head, *next_node = head->next;
	while (next_node != head) {
		if (current_node->val <= value && next_node->val >= value) {
			current_node->next = target_node;
			target_node->next = next_node;
			return head;
		}
		current_node = next_node;
		next_node = next_node->next;
	}
	// 2 目标结点插入到头结点前面
	target_node->next = head;
	current_node->next = target_node;
	if (value < head->val)
		return target_node;
	else
		return head;
}

int main() {
	// 空链表
	//vector<int> nums;

	// 非空链表
	vector<int> nums = { 1,3,4,5,7 };

	int insert_value = 2;

	ListNode *root = InsertValue(nums, insert_value);

	// 遍历链表，输出元素值
	ListNode *node = root;
	int list_length = nums.size() + 1;
	while (list_length > 0) {
		cout << node->val << "\t";
		node = node->next;
		--list_length;
	}
	cout << endl;

	// 回收分配给链表结点的内存
	ListNode *delete_node = nullptr;
	for (int i = 0; i < nums.size() + 1; ++i) {
		delete_node = node;
		node = node->next;
		delete delete_node;
	}
	node = nullptr;
	delete_node = nullptr;
	root = nullptr;

	system("pause");
	return 0;
}