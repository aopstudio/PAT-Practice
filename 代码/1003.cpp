// PATVS.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//


#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int main()
{
	int cityNum, roadNum, depa, dest;
	cin >> cityNum >> roadNum >> depa >> dest;
	vector<vector<int> > adjMatrix(cityNum, vector<int>(cityNum,INT_MAX));	//邻接矩阵
	vector<int> dist(cityNum,INT_MAX);	//记录到各个城市的最短距离
	vector<int> pathSum(cityNum);	//到各个城市的最短路径数量
	vector<int> teamSum(cityNum);	//到各个城市能集合到的救援队数量
	vector<bool> reach(cityNum);	//记录计算过程中是否以最短路径到各个城市
	vector<int> teams(cityNum);	//每个城市救援队数量
	for (int i = 0; i < cityNum; i++)
	{
		adjMatrix[i][i] = 0;
	}
	for (int i = 0; i < cityNum; i++)
	{
		int tnum;
		cin >> tnum;
		teams[i]=tnum;
	}
	for (int i = 0; i < roadNum; i++)
	{
		int from, to, weight;
		cin >> from >> to >> weight;
		adjMatrix[from][to] = weight;
		adjMatrix[to][from] = weight;
		if (from == depa)	//根据出发点的相邻路径更新相关信息
		{
			dist[to] = weight;
			teamSum[to] = teams[from] + teams[to];
			pathSum[to] = 1;
		}
	}
	dist[depa] = 0;
	teamSum[depa] = teams[depa];
	pathSum[depa] = 1;
	reach[depa] = true;
	//注意，只有当reach[i]为true时，dist[i]才是出发点到它真正的最短路径长度，否则就还得更新
	for (int i = 0; i < cityNum; i++)
	{
		int min = INT_MAX, u=-1;
		for (int j = 0; j < cityNum; j++)
		{
			if (reach[j] == false && dist[j] < min)
			{
				min = dist[j];
				u = j;
			}
		}
		if (min == INT_MAX)
			break;
		reach[u] = true;
		for (int j = 0; j < cityNum; j++)
		{
			if (reach[j] == false && adjMatrix[u][j]!=INT_MAX && dist[u] + adjMatrix[u][j] < dist[j])	
				//若adjMatrix[u][j]==INT_MAX就直接排除掉，如果没有判断，那么当它为INT_MAX的时候，dist[u]+adjMatrix[u][j]会反转变成负数，这样反而会符合<dist[j]的要求
			{
				dist[j] = dist[u] + adjMatrix[u][j];	//更新最短距离
				pathSum[j] = pathSum[u];	//更新可达的最短路径总数
				teamSum[j] = teamSum[u] + teams[j];		//更新可以集合到的救援队总数
			}
			else if (reach[j] == false && (dist[u] + adjMatrix[u][j]) == dist[j])	//如果有另一条最短距离相同的路径
			{
				pathSum[j] += pathSum[u];	//增加可达的最短路径总数
				if (teamSum[j] < teamSum[u] + teams[j])	//如果这条路径可以集合到的救援队数量更多
					teamSum[j] = teamSum[u] + teams[j];	//更新可以集合到的救援队数量
			}
		}
	}
	cout << pathSum[dest] << ' ' << teamSum[dest];
}




// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
