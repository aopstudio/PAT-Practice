#include <iostream>
using namespace std;
int main()
{
	int num;	//数字个数
	int currentSum=0;	//记录子串之和
	int maxSum = -1;	//最大子串之和
	int subFirst, subLast;	//最大子串的第一个和最后一个数字
	int startFlag;	//用来预留在未来更新subFirst（也可能不需要更新）
	bool updateFlag = false;	//用来记录是否在下一次循环中更新startFlag
	int first, last;	//记录整个数字串的第一个和最后一个数字
	int currentNum;	//记录当前读取的数字
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		cin >> currentNum;
		if (i == 0)
			subFirst = subLast = startFlag = first = currentNum;	//初始化并确定first
		if (i == num-1)
			last = currentNum;
		currentSum += currentNum;	//计算当前的子串之和
		if (updateFlag == true)	//根据上一次循环的标记更新startFlag
		{
			startFlag = currentNum;
			updateFlag = false;
		}
		if (currentSum > maxSum)	//当前计算的子串之和大于已知的最大子串和，则更新最大子串和，同时更新最大子串的首元素和尾元素
		{
			subFirst = startFlag;	//更新最大子串的首元素
			subLast = currentNum;	//更新最大子串的尾元素
			maxSum = currentSum;	//更新最大子串和
		}
		if (currentSum < 0)	//当前计算的子串之和小于0，则重新从零开始计算子串之和，同时标记下一次循环中更新startFlag
		{
			currentSum = 0;		//重新从零开始计算currentSum
			updateFlag = true;		//记录下一次循环中更新startFlag
		}
	}
	if (maxSum == -1)	//全是负数
	{
		cout << 0 << ' ' << first << ' ' << last;
	}
	else
	{
		cout << maxSum << ' ' << subFirst << ' ' << subLast;
	}
	return 0;
}