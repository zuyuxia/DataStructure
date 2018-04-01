//树结点的定义
struct Node{
	int data;
	struct Node* lchild;
	struct Node* rchild;
};

//树的前序遍历
void PreorderTraverse(Node *root){
	if(!root)
		return;
	
	//打印结点值
	cout << root->data << endl;
	PreorderTraverse(root->lchild);
	PreorderTraverse(root->rchild);
}

//树的中序遍历
void InorderTraverse(Node *root){
	if(!root)
		return;
	
	InorderTraverse(root->lchild);
	//打印结点的值
	cout << root->data << endl;
	InorderTraverse(root->rchild);
}

//树的后序遍历
void PostorderTraverse(Node *root){
	if(!root)
		return;
	
	PostorderTraverse(root->lchild);
	PostorderTraverse(root->rchild);
	//打印结点的值
	cout << root->data << endl;
}

//树的层序遍历（图的宽度优先算法BFS）
void BFS(Node *root){
	if(!root)
		return;
	
	//辅助数据结构，队列
	queue<Node*> q;
	q.push_back(root);
	while(!q.empty()){
		Node *head = q.front();
		q.pop_front();
		//打印结点的值
		cout << head->data << endl;
		if(head->lchild)
			q.push_back(head->lchild);
		if(head->rchild)
			q.push_back(head->rchild);
	}
}