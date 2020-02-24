#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
using namespace std;
bool cmp(string a, string b)
{
	return a + b < b + a;
}
int main()
{
	vector<string> numbers;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string num;
		cin >> num;
		numbers.push_back(num);
	}
	sort(numbers.begin(), numbers.end(), cmp);
	string result="";
	for (int i = 0; i < numbers.size(); i++)
	{
		result+=numbers[i];
	}
	bool flag = false;
	for (int i = 0; i < result.size(); i++)
	{
		if (result[i] == '0' && !flag)
		{
			if (i == result.size() - 1)	//一直到最后一个还是只有0
				cout << 0;
			else
				continue;
		}
		else
		{
			flag = true;
			cout << result[i];
		}
	}
	return 0;
}

//测试点2只有0，必须输出一个0