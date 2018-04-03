//图的遍历有两种方式，DFS（深度优先遍历）和BFS（广度优先遍历）

//先以一颗二叉树为例，DFS相当于是前序遍历，BFS相当于是层序遍历
//树结点的定义
struct Node{
	int data;
	struct Node* lchild;
	struct Node* rchild;
};

//DFS
void DFS(Node *root){
	if(!root)
		return;
	
	//打印结点值
	cout << root->data << endl;
	DFS(root->lchild);
	DFS(root->rchild);
}

//BFS
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

//图的存储方式（图中的结点值以int为例）
//1.邻接矩阵
#define MAXVEX 100
struct Graph{
	int vexs[MAXVEX];
	int arc[MAXVEX][MAXVEX];
	int numberVertex, numberEdge;
};

//2.邻接表
#define MAXVEX 100
struct EdgeNode{
	int index;
	int weight;
	struct EdgeNode *next;
};

struct VertexNode{
	int data;
	EdgeNode *first;
};

struct Graph{
	VertexNode vertex[MAXVEX];
	int numberVertex, numberEdge;
};

//图的遍历，以邻接矩阵作为图的数据结构
//DFS
bool visited[MAXVEX];

void DFS(Graph &gra, int i){
	visited[i] = true;
	//打印顶点
	cout << gra.vexs[i] << endl;
	
	//对顶点i的所有邻接顶点进行访问
	for(int j = 0; j < gra.numberVertex; ++j){
		if(!visited[j] && gra.arc[i][j] == 1)
			DFS(gra, j);
	}
}

void DFSTraverse(Graph gra){
	//对于每一个顶点数组，维持一个数组判断该顶点是否被访问
	for(int i = 0; i < MAXVEX; ++i)
		visited[i] = false;
	
	for(int i = 0; i < gra.numberVertex; ++i){
		if(!visited[i])
			DFS(gra, i);
	}
}

//BFS
bool visited[MAXVEX];

void BFSTraverse(Graph gra){
	for(int i = 0; i < MAXVEX; ++i)
		visited[i] = false;
	
	//初始化一个队列
	queue<int> q;
	for(int i = 0; i < gra.numberVertex; ++i){
		if(!visited[i]){
			visited[i] = true;
			//打印结点值
			cout << gra.vexs[i] << endl;
			
			q.push(i);
			while(!q.empty()){
				int temp = q.front();
				q.pop();
				for(int j = 0; j < gra.numberVertex; ++j){
					if(!visited[j] && gra.arc[temp][j] == 1){
						visited[j] = true;
						cout << gra.vexs[j] << endl;
						q.push(j);
					}
						
				}
			}
		}
	}
}