#include <iostream>
#include <vector>
using namespace std;
struct node
{
	int parent;
	int level;
	bool hasChild = false;
};
int main()
{
	int nodeSum, nonLeafSum;	//结点总数，非叶子结点总数
	cin >> nodeSum >> nonLeafSum;
	vector<node> tree(nodeSum+1);	//树，用双亲表示法
	tree[1].level = 0;
	tree[1].parent = -1;
	for (int i = 0; i < nonLeafSum; i++)
	{
		int parent;
		cin >> parent;
		tree[parent].hasChild = true;
		int childSum;
		cin >> childSum;
		for (int j = 0; j < childSum; j++)
		{
			int childNum;
			cin >> childNum;
			tree[childNum].parent = parent;
		}
	}
	int maxLevel = 0;	//存储最大层数
	for (int i = 1; i <= nodeSum; i++)
	{
		for (int j = 1; j <= nodeSum; j++)
		{
			if (tree[j].parent== i)
			{
				tree[j].level = tree[i].level + 1;
				if (tree[j].level > maxLevel)
					maxLevel = tree[j].level;
			}
		}
	}
	vector<int> result(maxLevel+1,0);	//存储输出结果，即每层的叶子节点数
	for (int i = 1; i <= nodeSum; i++)
	{
		if (tree[i].hasChild == false)
		{
			result[tree[i].level]++;
		}
	}
	for (int i = 0; i < maxLevel+1; i++)
	{
		if (i == 0)
			cout << result[i];
		else
			cout << ' ' << result[i];
	}
}