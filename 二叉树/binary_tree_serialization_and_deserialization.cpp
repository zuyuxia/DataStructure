// 问题的描述：二叉树的序列化和反序列化
//		序列化：二叉树被记录成文件的过程
//		反序列化：从文件重建二叉树的过程

// 测试用例有3组：
//		1、空子树
//			输入：string seq = ""
//			输出为：
//				前序遍历：#!
//				层序遍历：#！
//		2、左（右）斜子树
//			输入：string seq = "1!2!#!3!#!#!#!"
//			输出为：
//				前序遍历：1!2!3!#!#!#!#!
//				层序遍历：1!2!#!3!#!#!#!
//		3、正常二叉树
//			输入：string seq = "1!2!3!#!4!5!#!#!#!#!#!"
//			输出为：
//				前序遍历：1!2!#!4!#!#!3!5!#!#!#!
//				层序遍历：1!2!3!#!4!5!#!#!#!#!#!

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

// 前序遍历的序列化，根据一颗二叉树生成字符串
string SerializationByPreorder(Node* root) {
	if (root == nullptr)
		return "#!";
	string sequence = to_string(root->data) + '!';
	sequence += SerializationByPreorder(root->lchild);
	sequence += SerializationByPreorder(root->rchild);
	return sequence;
}

// 前序遍历的反序列化生成一颗二叉树
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

// 前序遍历的反序列化，根据序列构建一颗二叉树
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

// 层序遍历的序列化，根据一颗二叉树生成字符串
string SerializationByLevel(Node* root) {
	if (root == nullptr)
		return "#!";
	
	string sequence = to_string(root->data) + '!';
	queue<Node*> q;
	q.push(root);
	Node* node = nullptr;
	
	while (!q.empty()) {
		node = q.front();
		q.pop();
		
		if (node->lchild != nullptr) {
			q.push(node->lchild);
			sequence = sequence + to_string(node->lchild->data) + '!';
		}
		else {
			sequence += "#!";
		}
		if (node->rchild != nullptr) {
			q.push(node->rchild);
			sequence = sequence + to_string(node->rchild->data) + '!';
		}
		else {
			sequence += "#!";
		}
	}

	return sequence;
}

// 层序遍历的反序列化，根据层序遍历序列构建一颗二叉树
// 采用vector保存结点，是为了方便后面delete掉new的结点
void DeserializationByLevel(const string &sequence, vector<Node*> &result) {
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

// 清理层序遍历生成的二叉树结点
void FreeNodeByLevel(vector<Node*> &result) {
	for (int i = 0; i < result.size(); ++i) {
		if (result[i] != nullptr) {
			delete result[i];
			result[i] = nullptr;
		}
	}
}

int main() {
	
	// 基于前序遍历，测试用例1：空子树
	// string seq = "";

	// 基于前序遍历，测试用例2：左（右）斜子树
	// string seq = "1!2!3!#!#!#!#!";

	// 基于前序遍历，测试用例3：正常的二叉树
	string seq = "1!2!#!4!#!#!3!5!#!#!#!";

	// 基于前序遍历，根据序列生成一颗二叉树（反序列化）
	Node* root = DeserializationByPreorder(seq);

	// 基于前序遍历，根据二叉树生成序列（序列化）
	string preorder_result = SerializationByPreorder(root);
	cout << preorder_result << endl;

	FreeNodeByPreorder(root);
	
	/*
	// 基于层序遍历，测试用例1：空子树
	// string seq = "";

	// 基于层序遍历，测试用例2：左（右）斜子树
	// string seq = "1!2!#!3!#!#!#!";

	// 基于层序遍历，测试用例3：正常的二叉树
	string seq = "1!2!3!#!4!5!#!#!#!#!#!";

	// 基于层序遍历，根据序列生成一颗二叉树（反序列化）
	vector<Node*> result(seq.size() / 2, nullptr);
	DeserializationByLevel(seq, result);

	Node* root = nullptr;
	if (!seq.empty())
		root = result[0];

	// 基于层序遍历，根据二叉树生成序列（序列化）
	string level_result = SerializationByLevel(root);
	cout << level_result << endl;

	FreeNodeByLevel(result);
	*/
	system("pause");
	return 0;
}