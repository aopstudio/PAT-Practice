#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

long long transfer(char c);
long long calculate(string n, long long radix);
long long countMax(string n);
long long binary(string n, long long l, long long r, long long tagValue);
int main()
{
	string n1, n2;
	int tag;
	long long radix, tagValue;	//用十进制表示的数值
	long long l = 2, r, mid;
	cin >> n1 >> n2 >> tag >> radix;
	if (tag == 2)
		swap(n1, n2);
	tagValue = calculate(n1, radix);
	l = countMax(n2)+1;
	r = tagValue;
	l = binary(n2, l, r, tagValue);
	if (calculate(n2, l) == tagValue)
		cout << l;
	else
		cout << "Impossible";
	return 0;
}

long long transfer(char c)	//字符数字转换器
{
	if (c >= '0' && c <= '9')
		return c - '0';
	if (c >= 'a' && c <= 'z')
		return c - 'a' + 10;
	return -1;	//输入其他字符，错误
}

long long calculate(string n, long long radix)	//将特定进制下的数转换为十进制的数值
{
	long long decValue = 0;
	long long exp = 1;
	for (int i = n.length() - 1; i >= 0; i--)
	{
		decValue += transfer(n[i]) * exp;
		exp *= radix;
		if (decValue < 0 || exp < 0)
			return -1;
	}
	return decValue;
}

long long countMax(string n)	//查找字符串中最大的数字,即最低进制-1
{
	long long max = 0;
	for (int i = 0; i < n.length(); i++)
	{
		if (transfer(n[i]) > max)
			max = transfer(n[i]);
	}
	return max;
}

long long binary(string n2, long long l, long long r, long long tagValue)	//二分法比较
{
	long long mid;
	long long value;
	while (l <= r)
	{
		mid = (l + r) / 2;
		value = calculate(n2, mid);
		if (value >= tagValue || value < 0)	//可能进制过大导致value溢出
			r = mid - 1;
		else if (value < tagValue)	
			l = mid + 1;
	}
	return l;
}