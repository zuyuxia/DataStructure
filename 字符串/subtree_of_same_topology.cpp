// 问题的描述：拓扑结构相同子树
//		给定一个两棵二叉树，判断树A中是否存在一棵子树与B树的拓扑结构完全相同
// 普通解法：二叉树遍历 + 匹配	O(M * N)
// 最优解法：二叉树序列化 + KMP算法（判断A序列中是否包含B序列）	O(M * N)

// 测试用例有3组：
//		1、空树
//			输入：nullptr; nullptr
//			输出：false
//		2、包含相同拓扑结构的子树
//			输入：
//			 1			2
//			/ \		   / \
//		   2   3	  4   5
//		  / \
//		 4   5
//			输出：true
//		3、不包含相同拓扑结构的子树
//			输入：
//			 1			2
//			/ \		   /
//		   2   3	  4
//		  / \
//		 4   5
//			输出：true

#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

// 树结点的定义
struct Node {
	int data;
	struct Node* lchild;
	struct Node* rchild;
};

/*
// 普通解法：二叉树遍历 + 匹配
// 将结点按照层序遍历的方式保存在vector中，便于后面进行比较
void SaveNodeToVector(Node* root, vector<Node*> &vec) {
	if (root == nullptr)
		return;

	queue<Node*> node_queue;
	node_queue.push(root);
	Node* node = nullptr;
	while (!node_queue.empty()) {
		node = node_queue.front();
		node_queue.pop();
		vec.push_back(node);

		if (node->lchild != nullptr)
			node_queue.push(node->lchild);
		else
			vec.push_back(nullptr);
		if (node->rchild != nullptr)
			node_queue.push(node->rchild);
		else
			vec.push_back(nullptr);
	}
}

// 匹配比较函数，对满足条件的两棵子树进行比较
bool CompareTopology(Node* root1, vector<Node*> &root2_vector) {
	if (root1 == nullptr || root2_vector.empty())
		return false;

	// 先将树2的结点以层序遍历的方式都保存在vector中
	vector<Node*> root1_vector;
	SaveNodeToVector(root1, root1_vector);

	if (root1_vector.size() != root2_vector.size())
		return false;

	// 遍历vector，进行比较
	for (int i = 0; i < root1_vector.size(); ++i) {
		// 树1和树2结点均为空直接跳过
		if (root1_vector[i] == nullptr && root2_vector[i] == nullptr)
			continue;
		// 树1和树2结点均不为空进行比较
		else if (root1_vector[i] != nullptr && root2_vector[i] != nullptr) {
			if (root1_vector[i]->data != root2_vector[i]->data)
				return false;
		}
		// 树1和树2结点只有一个为空直接返回false
		else
			return false;
	}
	return true;
}

// 对两棵树进行比较判断
bool CheckSameTopology(Node* root1, Node* root2) {
	if (root1 == nullptr || root2 == nullptr)
		return false;

	// 先将树2的结点以层序遍历的方式都保存在vector中，等下直接比较
	vector<Node*> root2_vector;
	SaveNodeToVector(root2, root2_vector);

	// 遍历树1，找到结点值与树2根结点值相同的结点，进行匹配比较
	bool flag = false;
	queue<Node*> node_queue;
	node_queue.push(root1);
	Node* node = nullptr;
	while (!node_queue.empty()) {
		node = node_queue.front();
		node_queue.pop();
		
		if (node->data == root2->data)
			flag = CompareTopology(node, root2_vector);
		
		if (flag)
			return true;

		if (node->lchild != nullptr)
			node_queue.push(node->lchild);
		if (node->rchild != nullptr)
			node_queue.push(node->rchild);
	}
	return false;
}
*/

// 最优解法：二叉树序列化 + KMP算法
// 前序遍历的序列化，根据一颗二叉树生成字符串
string SerializationByPreorder(Node* root) {
	if (root == nullptr)
		return "#!";
	string sequence = to_string(root->data) + '!';
	sequence += SerializationByPreorder(root->lchild);
	sequence += SerializationByPreorder(root->rchild);
	return sequence;
}

// 判断树2的序列化结果是否在树1的序列化结果中
bool CheckSameTopology(Node* root1, Node* root2) {
	if (root1 == nullptr || root2 == nullptr)
		return false;

	// 对两棵树进行序列化
	string tree1 = SerializationByPreorder(root1);
	string tree2 = SerializationByPreorder(root2);

	// 查找tree2是否在tree1中
	if (tree1.find(tree2) != string::npos)
		return true;
	else
		return false;
}

// 前序遍历的反序列化，根据序列构建一颗二叉树
Node* HelpDeserialization(queue<string> &values) {
	string value = values.front();
	values.pop();

	if (value == "#")
		return nullptr;

	Node* root = new Node();
	root->data = stoi(value);
	root->lchild = HelpDeserialization(values);
	root->rchild = HelpDeserialization(values);
	return root;
}

Node* DeserializationByPreorder(const string &sequence) {
	if (sequence.empty() || (sequence == "#!"))
		return nullptr;

	// 从sequence中提取出来每一个值，放在queue中
	string temp_sequence = sequence;
	queue<string> values;
	string::size_type pos = 0;
	while (!temp_sequence.empty()) {
		pos = temp_sequence.find('!');
		if (pos == string::npos)
			break;
		values.push(temp_sequence.substr(0, pos));
		temp_sequence = temp_sequence.substr(pos + 1);
	}

	return HelpDeserialization(values);
}

// 清理前序遍历生成的二叉树结点
void FreeNodeByPreorder(Node* root) {
	if (root == nullptr)
		return;
	FreeNodeByPreorder(root->lchild);
	FreeNodeByPreorder(root->rchild);
	delete root;
	root = nullptr;
}

int main() {
	// 空树
	// string sequence1 = "#!";
	// string sequence2 = "#!";

	// 包含相同拓扑结构的子树
	// string sequence1 = "1!2!4!#!#!5!#!#!3!#!#!";
	// string sequence2 = "2!4!#!#!5!#!#!";

	// 不包含相同拓扑结构的子树
	string sequence1 = "1!2!4!#!#!5!#!#!3!#!#!";
	string sequence2 = "2!4!#!#!#!";

	Node* root1 = DeserializationByPreorder(sequence1);
	Node* root2 = DeserializationByPreorder(sequence2);

	if (CheckSameTopology(root1, root2))
		cout << "true" << endl;
	else
		cout << "false" << endl;

	FreeNodeByPreorder(root1);
	FreeNodeByPreorder(root2);

	system("pause");
	return 0;
}