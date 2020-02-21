#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, M, S, D;
vector<vector<int> > dist;	//路径长度邻接矩阵
vector<vector<int> > cost;	//花费邻接矩阵
vector<bool> reach; //是否已经遍历过该点
int minLen, minCost;	//最短路程，最少花费
vector<int> ans, temp;	//ans代表最终的最短路程，temp用于暂存每次遍历的路程并计算出ans
void DFS(int s, int length, int pay)
{
	if (s == D)	//遍历到出问题的站点
	{
		if (length < minLen || (length == minLen && pay < minCost) )	//满足题目中给出的最短路径条件
		{
			ans = temp;	//记录当前经过的路程为结果路程
			minCost = pay;
			minLen = length;	//更新各项指标
		}
		return;
	}
	for (int i = 0; i < N; i++)
	{
		if (reach[i] == false && dist[s][i] != 0)  //没有遍历过i点且s和i有路连接
		{
			reach[i] = true;
			temp.push_back(i);	//将i点计入路程经过的点
			DFS(i, length + dist[s][i], pay+cost[s][i]);  //对i点进行深度遍历
			reach[i] = false;   //遍历完成后删除i点的访问记录
			temp.pop_back();	//弹出当前经过路径中的i点，准备遍历下一个点
		}
	}
}

int main()
{
	cin >> N >> M >> S >> D;
	dist.assign(N, vector<int>(N, 0));
	cost.assign(N, vector<int>(N, 0));
	reach.assign(N, false);
	for (int i = 0; i < M; i++)
	{
		int c1, c2, dis, cos;
		cin >> c1 >> c2 >> dis >> cos;
		dist[c2][c1] = dist[c1][c2] = dis;
		cost[c2][c1] = cost[c1][c2] = cos;
	}
	minLen = minCost = 100000000;
	DFS(S, 0, 0);
	cout << S << ' ';
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << ' ';
	}
	cout << minLen<<' '<<minCost;
}