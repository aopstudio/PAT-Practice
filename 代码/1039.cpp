#include <iostream>
#include <algorithm>
#include <set>
#include <string>
#include <map>
using namespace std;
int hashname(string name) { //用散列值将name转换为int类型，否则会超时
	int sum = (name[0] - 'A') * 26 * 26 * 10 +
		(name[1] - 'A') * 26 * 10 +
		(name[2] - 'A') * 10 +
		(name[3] - '0');
	return sum;
}
int main()
{
	map<int, set<int> > stc;
	int N, K;
	cin >> N >> K;
	for (int i = 0; i < K; i++)
	{
		int index, stuNum;
		cin >> index >> stuNum;
		for (int j = 0; j < stuNum; j++)
		{
			string name;
			cin >> name;
			int sname = hashname(name);
			stc[sname].insert(index);
		}
	}
	for (int i = 0; i < N; i++)
	{
		string name;
		cin >> name;
		cout << name << ' ';
		int sname = hashname(name);
		if (stc.find(sname) == stc.end())
			cout << '0';
		else
		{
			set<int> courseList = stc[sname];
			cout << courseList.size()<< ' ';
			for (set<int>::iterator it=courseList.begin();it!=courseList.end();it++)
			{
				if (it == courseList.begin())
					printf("%d",*it);
				else
					printf(" %d", *it);
			}
		}
		printf("\n");
	}
	return 0;
}