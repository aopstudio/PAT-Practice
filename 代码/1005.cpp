#include <iostream>
#include <vector>
#include <string>
using namespace std;
string transfer(int digit);
int main()
{
	char c;
	int num,sum=0;
	vector<int> result;
	while ((c = cin.get()) != EOF && c!=10)
	{
		num = c - '0';
		sum += num;	//累加计算总和
	}
	if (sum == 0)	//考虑总和为0的情况，此时直接输出zero
	{
		cout << "zero";
		return 0;
	}
	while (sum != 0)
	{
		result.push_back(sum % 10);	//从个位开始一位位往vector中添加数字
		sum /= 10;
	}
	for (int i = result.size() - 1; i >= 0; i--)	//倒序输出vector
	{
		if (i == result.size() - 1)
			cout << transfer(result[i]);
		else
			cout << ' ' << transfer(result[i]);
	}
	return 0;
}
string transfer(int digit)	//阿拉伯数字和英文转换器
{
	switch (digit)
	{
	case 0:
		return "zero";
		break;
	case 1:
		return "one";
		break;
	case 2:
		return "two";
		break;
	case 3:
		return "three";
		break;
	case 4:
		return "four";
		break;
	case 5:
		return "five";
		break;
	case 6:
		return "six";
		break;
	case 7:
		return "seven";
		break;
	case 8:
		return "eight";
		break;
	case 9:
		return "nine";
		break;
	default:
		break;
	}
	return "NaN";	//用不到，但函数必须得有返回值
}