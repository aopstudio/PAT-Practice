#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct node
{
	int data;
	node *left = NULL;
	node *right = NULL;
};
vector<int> postOrder;
vector<int> inOrder;
queue<node*> levelOrder;
void level(node* root, int N);
node* construct(int postl, int postr, int inl, int inr);
int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int digit;
		cin >> digit;
		postOrder.push_back(digit);
	}
	for (int i = 0; i < N; i++)
	{
		int digit;
		cin >> digit;
		inOrder.push_back(digit);
	}
	node *tree= construct(0, N - 1, 0, N - 1);
	level(tree, N);
}

//四个参数都代表构建结点时统计数据的边界，postl,postr代表后序列表的开始结点和结尾结点，inl和inr代表中序列表的开始结点和结尾结点
//左子树的postl永远是0，右子树的inr永远是N-1
node* construct(int postl, int postr, int inl, int inr)	
{
	if (postl > postr)
		return NULL;
	node* root = new node;
	root->data = postOrder[postr];	//后序列表的结尾结点为当前树的根节点
	int index;
	for (index = inl; index <= inr; index++)	//找到根节点在中序列表中的位置
		if (inOrder[index] == postOrder[postr])
			break;
	int numl = index - inl;
	root->left = construct(postl, postl + numl - 1, inl, index - 1);	//构建左子树
	root->right = construct(postl + numl, postr - 1, index + 1, inr);	//构建右子树
	return root;
}

void level(node* root,int N)	//层次遍历
{
	int size = 0;	//记录已经弹出过的数量，当size为N时最后不输出空格
	levelOrder.push(root);	//推入根节点到队列
	while (levelOrder.size() != 0)	//当队列不为空时
	{
		node* temp = levelOrder.front();	//弹出队列头
		levelOrder.pop();
		size++;
		if (size == N)
			cout << temp->data;
		else
			cout << temp->data << ' ';
		if (temp->left != NULL)	//如果队列头左子节点不为空
			levelOrder.push(temp->left);	//将左子节点推入队列
		if (temp->right != NULL)	//右子节点也一样
			levelOrder.push(temp->right);
	}
}