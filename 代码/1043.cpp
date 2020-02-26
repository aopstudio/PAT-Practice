#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
vector<int> pre, post;
void getPost(int root, int tail,bool mirror) { //root->根，tail->最后一个结点索引 
	if (root > tail) return;
	int i = root + 1; //获取根结点下一个结点 
	int j = tail; //j从最后一个结点起
	//极限情况没有右子树，最后i==tail+1 
	if (!mirror)	//是正常的搜索树
	{
		
		while (i <= tail && pre[i] < pre[root]) {
			i++;//用i指示右子树根结点 
		}
		//极限情况没有左子树，最后j==root 
		while (j > root && pre[j] >= pre[root]) {
			j--;//用于标识右子树根结点的前一个结点
		}
		//最终j和i必然相差1，因为i指示右子树根结点
	}
	else //是镜像搜索树
	{
		while (i <= tail && pre[i] >= pre[root]) {
			i++;//用i指示右子树根结点 
		}
		//极限情况没有左子树，最后j==root 
		while (j > root && pre[j] < pre[root]) {
			j--;//用于标识右子树根结点的前一个结点
		}
	}
	if (j != root) getPost(root + 1, j,mirror); //将左子树的后序遍历序列获取到并加入到post序列中 
	if (i != tail + 1) getPost(i, tail,mirror); // 将右子树的后序遍历序列获取到并加入到post序列中 
	post.push_back(pre[root]);
}
int main()
{
	map<int, bool> record;
	int N;
	cin >> N;
	bool lJump = false, rJump = false;	//左跳跃和右跳跃
	int root;
	cin >> root;
	int last = root;
	record[root] = true;
	pre.push_back(root);
	for (int i = 1; i < N; i++)
	{
		int num;
		cin >> num;
		pre.push_back(num);
		//查看当前结点的数值和前一个结点的数值之间是否还有其他数值，如果当前结点比前一个结点小，则记左跳跃，如果大，则记右跳跃
		if (num >= last)	
		{
			for (int j = last + 1; j <= num; j++)
			{
				if (record.find(j) != record.end())
				{
					rJump = true;
					break;
				}
			}
		}
		else
		{
			for (int j = num + 1; j < last; j++)
			{
				if (record.find(j) != record.end())
				{
					lJump = true;
					break;
				}
			}
		}
		last = num;
		record[num] = true;
	}
	if (lJump&&rJump)	//如果同时具有左跳跃和右跳跃，说明不是搜索树
		cout << "NO";
	else
	{
		cout << "YES" << endl;
		if (rJump)	//如果只有右跳跃，说明是正常搜索树
			getPost(0, N - 1,false);
		else //如果只有左跳跃，说明是镜像搜索树
			getPost(0, N - 1, true);
		//如果出现没有跳跃的情况，将无法确定一棵唯一的搜索树。而题意中可以看出搜索树是唯一的，因此例子中不会给没有跳跃的情况
		for (int i = 0; i < N; i++)
		{
			if (i == 0)
				cout << post[i];
			else
				cout << ' ' << post[i];
		}
	}
	return 0;
}