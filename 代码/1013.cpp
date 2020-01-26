#include <iostream>
#include <vector>
using namespace std;
void updateReached(int start);
vector<int> reached;
vector<int> cWay;
vector<vector<int> > ways;
int main()
{
	int N, M, K;
	cin >> N >> M >> K;
	cWay.assign(N + 1, 0);
	ways.assign(N + 1, cWay);
	vector<int> result;
	for (int i = 0; i < M; i++)
	{
		int c1, c2;
		scanf("%d %d",&c1,&c2);
		ways[c1][c2] = 1;
		ways[c2][c1] = 1;
	}
	for (int i = 0; i < K; i++)
	{
		int newWayNum = -1;
		reached.assign(N + 1, 0);
		int checked;
		scanf("%d",&checked);
		reached[checked] = 1;
		for (int j = 1; j < N+1; j++)
		{
			if (reached[j] == 0)
			{
				updateReached(j);
				newWayNum++;
			}
		}
		printf("%d\n",newWayNum);
	}
}
void updateReached(int start)	//更新start可达的城市到reach列表
{
	reached[start] = 1;
	for (int i = 1; i < reached.size(); i++)
	{
		if (ways[start][i] == 1 && reached[i] == 0)	//有路通且还没加入reached列表
		{
			updateReached(i);
		}
	}
	return;
}