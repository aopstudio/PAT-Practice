#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	vector<int> count(10,0);
	char c;
	vector<int> num;
	vector<int> dbNum;
	bool flag = true;
	while ((c = cin.get()) != '\n')
	{
		int digit = c - '0';
		count[digit]++;
		num.push_back(digit);
	}
	dbNum.assign(num.size() + 1, 0);
	for (int i = num.size()-1; i >= 0; i--)
	{
		int digit = num[i];
		int index = num.size() - 1 - i;
		dbNum[index] += digit * 2 % 10;
		dbNum[index + 1] += digit * 2 / 10;
	}

	for (int i = dbNum.size() - 1; i >= 0; i--)
	{
		if (i == dbNum.size() - 1 && dbNum[i] == 0)
			continue;
		int digit = dbNum[i];
		count[digit]--;
	}
	for (int i = 0; i < 10; i++)
	{
		if (count[i] != 0)
		{
			flag = false;
			break;
		}
	}
	if (flag)
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
	for (int i = dbNum.size() - 1; i >= 0; i--)
	{
		if (i == dbNum.size() - 1 && dbNum[i] == 0)
			continue;
		int digit = dbNum[i];
		cout << digit;
	}
	return 0;
}
