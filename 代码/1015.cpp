#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int num, radix, reverse;
	vector<int> result;	//1代表Yes，0代表No
	cin >> num;
	while (num >= 0)
	{
		reverse = 0;	//用于存储翻转后的数
		if (num < 2)	//1和0
		{
			result.push_back(0);
			cin >> num;
			continue;	//直接进入下一次循环
		}
		int flag = 1;
		cin >> radix;
		for (int i = 2; i < num; i++)	//判断原数是否为质数
		{
			if (num%i == 0)
			{
				flag = 0;
				break;
			}
		}
		vector<int> radixNum;
		while (num / radix > 0)
		{
			radixNum.push_back(num%radix);
			num /= radix;
		}
		radixNum.push_back(num);
		int exp = 1;
		for (int i = radixNum.size() - 1; i >= 0; i--)
		{
			reverse += radixNum[i] * exp;
			exp *= radix;
		}
		if (reverse < 2)	//1和0
		{
			result.push_back(0);
			cin >> num;
			continue;	//直接进入下一次循环
		}
		for (int i = 2; i < reverse; i++)	//判断翻转数是否为质数
		{
			if (reverse % i == 0)
			{
				flag = 0;
				break;
			}
		}
		result.push_back(flag);
		cin >> num;
	}
	for (int i = 0; i < result.size(); i++)
	{
		if (result[i] == 1)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}