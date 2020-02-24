#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

int main()
{
	int N;
	map<int, bool> u;
	vector<int> order;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		order.push_back(num);
		if (u.find(num) == u.end())
		{
			u[num] = true;
		}
		else
		{
			u[num] = false;
		}
	}
	for (int num : order)
	{
		if (u[num])
		{
			cout << num;
			return 0;
		}
	}
	cout << "None";
	return 0;
}