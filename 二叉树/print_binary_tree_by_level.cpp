// 问题的描述：给定一颗二叉树，按层打印
// 例子：
//		level1 ： 1
//		level2 :  2  3
//		level3 :  4  5  6
//		......

// 解决代码如下，构建二叉树使用基于层序遍历的反序列化方式
// 测试用例有3组：
//		1、空子树(string seq = "")，输出为空
//		2、左（右）斜子树(string seq = "1!2!#!3!#!")，输出为：
//			1
//			2
//			3
//		3、正常二叉树(string seq = "1!2!3!#!4!5!#!")，输出为：
//			1
//			2  3
//			4  5

#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// 树结点的定义
struct Node {
	int data;
	struct Node* lchild;
	struct Node* rchild;
};

// 二叉树按层打印
void PrintBinaryTreeByLevel(Node* root) {
	if (root == nullptr)
		return;
	queue<Node*> q;
	q.push(root);
	Node* temp = nullptr;

	Node* last = root;
	Node* nlast = nullptr;
	while (!q.empty()) {
		temp = q.front();
		q.pop();
		cout << temp->data << "\t";

		if (temp->lchild != nullptr) {
			q.push(temp->lchild);
			nlast = temp->lchild;
		}
		if (temp->rchild != nullptr) {
			q.push(temp->rchild);
			nlast = temp->rchild;
		}
		if (temp == last && !q.empty()) {
			cout << "\n";
			last = nlast;
		}
	}
	cout << "\n";
}

// 根据层序遍历序列构建一颗二叉树
// 采用vector保存结点，是为了方便后面delete掉new的结点
void CreateBinaryTree(const string &sequence, vector<Node*> &result) {
	if (sequence.empty() || (sequence == "#!"))
		return;

	// 从sequence中提取出来每一个值
	string temp_sequence = sequence;
	vector<string> values;
	string::size_type pos = 0;
	while (!temp_sequence.empty()) {
		pos = temp_sequence.find('!');
		if (pos == string::npos)
			break;
		values.push_back(temp_sequence.substr(0, pos));
		temp_sequence = temp_sequence.substr(pos + 1);
	}

	Node* node = nullptr;
	for (int i = values.size() - 1; i >= 0; --i) {
		if (values[i] == "#")
			continue;
		else {
			node = new Node();
			node->data = stoi(values[i]);
			if (i < values.size() / 2) {
				node->lchild = result[2 * i + 1];
				node->rchild = result[2 * i + 2];
			}
			else {
				node->lchild = nullptr;
				node->rchild = nullptr;
			}
			result[i] = node;
		}
	}
}

// 释放二叉树结点的内存
void FreeNodeMemory(vector<Node*> &result) {
	for (int i = 0; i < result.size(); ++i) {
		if (result[i] != nullptr) {
			delete result[i];
			result[i] = nullptr;
		}
	}
}

int main() {

	// 测试用例1：空子树
	// string seq = "";

	// 测试用例2：左（右）斜子树
	// string seq = "1!2!#!3!#!";

	// 测试用例3：正常的二叉树
	string seq = "1!2!3!#!4!5!#!";
	vector<Node*> result(seq.size() / 2, nullptr);
	CreateBinaryTree(seq, result);

	Node* root = nullptr;
	if (!seq.empty())
		root = result[0];

	PrintBinaryTreeByLevel(root);

	FreeNodeMemory(result);
	system("pause");
	return 0;
}