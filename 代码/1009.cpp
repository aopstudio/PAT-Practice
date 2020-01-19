#include <iostream>
#include <vector>
using namespace std;
struct poly
{
	int exp;	//指数
	double coe;	//系数
};
int main()
{
	int num1, num2;	//分别代表两个多项式所含元素的个数
	int max1, max2, min1, min2;	//记录两个多项式最大指数项对应的系数和最小指数项对应的系数
	vector<poly> poly1;	//第一个多项式
	vector<poly> poly2;	//第二个多项式
	vector<double> result;	//存储结果
	int resultSize;	//result的预留长度
	int realSize = 0;	//result中非零元素的个数
	int bias;	//result下标的偏移量
	int index;	//相乘后的结果在result中对应的下标
	cin >> num1;
	for (int i = 0; i < num1; i++)
	{
		poly p;
		cin >> p.exp >> p.coe;
		poly1.push_back(p);
		if (i == 0)
			max1 = p.exp;
		if (i == num1 - 1)
			min1 = p.exp;
	}
	cin >> num2;
	for (int i = 0; i < num2; i++)
	{
		poly p;
		cin >> p.exp >> p.coe;
		poly2.push_back(p);
		if (i == 0)
			max2 = p.exp;
		if (i == num2 - 1)
			min2 = p.exp;
	}
	bias = min1 + min2;
	resultSize = max1 + max2 - bias + 1;
	result.resize(resultSize);
	for (int i = 0; i < num1; i++)
	{
		for (int j = 0; j < num2; j++)
		{
			index = poly1[i].exp + poly2[j].exp - bias;
			if(result[index] == 0)
				realSize++;
			result[index] += poly1[i].coe * poly2[j].coe;
			if(result[index] == 0)
				realSize--;
		}
	}
	/*for (int i = 0; i < result.size(); i++)	//统计结果集中非零项个数
	{
		if (result[i] != 0.0)
			realSize++;
	}*/
	cout << realSize;
	for (int i = resultSize-1; i >= 0; i--)
	{
		if (result[i] != 0.0)
			printf(" %d %.1f", i + bias, result[i]);
	}
	return 0;
}