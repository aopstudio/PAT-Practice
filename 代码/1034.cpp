#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <set>
using namespace std;
struct head
{
	string name;
	int number;
};
set<head> heads;
map<string, vector<string> > relation;
map<string, int> weight;
map<string, bool> flag;
int gangNum, gangWeight;
string headName;


bool operator<(const head &a, const head &b)
{
	return a.name < b.name;
}

void dfs(string str)
{
	flag[str] = true;	//设为已访问
	gangWeight += weight[str];	//统计团伙权重值

	if (weight[str] >weight[headName]) headName = str;	//如果当前结点的权值比之前设定的头目结点还大，则将当前结点设为头目结点
	for (int i = 0; i < relation[str].size(); i++)
	{
		if (!flag[relation[str][i]])	//对连接当前结点且未被访问的结点进行深度遍历
		{
			dfs(relation[str][i]);
		}
	}
	gangNum++;
}

int main()
{
	int n, k;
	cin >> n >> k;
	//map<int, string> reindex;
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		string n1, n2;
		int time;
		cin >> n1 >> n2 >> time;
		if (weight.find(n1) == weight.end())	//没有该名字的记录
		{
			weight[n1] = time;
			count++;
		}
		else
		{
			weight[n1] += time;
		}
		if (weight.find(n2) == weight.end())	//没有该名字的记录
		{
			weight[n2] = time;
			count++;
		}
		else
		{
			weight[n2] += time;
		}
		relation[n1].push_back(n2);
		relation[n2].push_back(n1);
		flag[n1] = false;
		flag[n2] = false;
	}
	for (auto it = flag.begin(); it != flag.end(); it++)
	{
		if (it->second == false)
		{
			gangNum = 0;
			gangWeight = 0;
			headName = it->first;
			dfs(headName);
			if (gangNum > 2 && gangWeight / 2 > k)	//如果是团伙，且权值超出阈值。统计的是每个结点的权值之和，实际上应该统计每条边的权值之和，因此结果必须除以二去和阈值比较
				heads.insert({ headName,gangNum });	//则在结果集中插入头目结点名和团伙成员数量
		}
	}
	cout << heads.size() << endl;
	for (auto &h : heads)
	{
		cout << h.name << ' ' << h.number<<endl;
	}
	return 0;
}