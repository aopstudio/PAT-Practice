#include <iostream>
#include <vector>
using namespace std;
void print(vector<int> baseNum);
int main()
{
	int decNum, base;
	bool flag = true;   //判断结果
	vector<int> baseNum;    //存储转换进制后的数
	cin >> decNum >> base;
	while (decNum / base != 0)  //转换进制
	{
		baseNum.push_back(decNum%base);
		decNum /= base;
	}
	baseNum.push_back(decNum);
	for (int i = 0; i < baseNum.size()/2; i++)  //比较首尾数字是否相等
	{
		if (baseNum[i] != baseNum[baseNum.size() - 1 - i])  //如果存在不相等的
		{
			flag = false;   //置flag为false
			break;
		}
	}
	if (flag == false)
	{
		cout << "No" << endl;
		print(baseNum);
	}
	else
	{
		cout << "Yes" << endl;
		print(baseNum);
	}
	return 0;
}
void print(vector<int> baseNum)
{
	for (int i = baseNum.size() - 1; i >= 0; i--)
	{
		if (i == 0)
			cout << baseNum[i];
		else
			cout << baseNum[i] << ' ';
	}
}