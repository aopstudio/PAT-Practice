#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main()
{
	map<int, int> nex;
	vector<int> list1, list2;
	int fa1, fa2, N;
	cin >> fa1 >> fa2 >> N;
	for (int i = 0; i < N; i++)
	{
		int add, next;
		char data;
		cin >> add >> data >> next;
		nex[add] = next;
	}
	while (fa1 != -1)
	{
		list1.push_back(fa1);
		fa1 = nex[fa1];
	}
	while (fa2 != -1)
	{
		list2.push_back(fa2);
		fa2 = nex[fa2];
	}
	int a = list1.size() - 1, b = list2.size() - 1;
	if (a<0||b<0||list1[a] != list2[b])
		cout << -1;
	else
	{
		while (a >= 0 && b >= 0 && list1[a] == list2[b])
		{
			a--; b--;
		}
		printf("%05d", list1[a + 1]);
	}
	return 0;
}