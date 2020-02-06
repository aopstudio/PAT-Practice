#include <iostream>
#include <vector>

using namespace std;
vector<vector<int> > graph;

int maxDepth = 0;
vector<int> deepestRoot;
vector<int> reached;
int findDeepest(int root, int N, int depth);
int main()
{
	int N;
	cin >> N;
	graph.resize(N + 1);
	reached.assign(N + 1, 0);
	bool isTree = true;
	int connected = 1;
	for (int i = 0; i < N - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		if (reached[a] == 1 && reached[b] == 1)	//两个点之前都已经访问过
		{
			isTree = false;
			connected++;
		}
		else
		{
			reached[a] = reached[b] = 1;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
	}
	if (isTree == false)	//不是树
		cout << "Error: " << connected << " components";
	else
	{
		int deepst = 0;
		for (int i = 1; i <= N; i++)
		{
			maxDepth = 0;
			reached.assign(N + 1, 0);
			int temp = findDeepest(i, N, 0);
			if (temp > deepst)
			{
				deepst = temp;
				deepestRoot.clear();
				deepestRoot.push_back(i);
			}
			else if (temp == deepst)
			{
				deepestRoot.push_back(i);
			}
		}
		for (int i = 0; i < deepestRoot.size(); i++)
		{
			cout << deepestRoot[i] << endl;
		}
	}
	return 0;
}
int findDeepest(int root, int N, int depth)
{
	reached[root] = 1;
	depth++;
	if (depth > maxDepth)
		maxDepth = depth;
	for (int i = 0; i < graph[root].size(); i++)
	{
		int t = graph[root][i];
		if (reached[t] == 0)	//有通路且没有被访问过
		{
			findDeepest(t, N, depth);
		}
	}
	return maxDepth;
}