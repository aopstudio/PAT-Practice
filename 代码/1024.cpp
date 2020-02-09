#include <iostream>
#include <stack>
#include <string>
using namespace std;
stack<int> reverse(stack<int> num);
stack<int> addReverse(stack<int> num);
bool equal(stack<int> num, stack<int> rev);
int main()
{
	string N;	//题中要求N小于等于10的10次方，int值已经无法满足
	int K;
	stack<int> num;	//题中要求K小于等于100，也就是最多加它的倒置100次，long long也不够，只能逐位处理。使用stack方便倒置
	stack<int> rev;	//倒置后的数
	stack<int> addRev;	//原数和倒置数相加的结果
	cin >> N >> K;
	for (int i = 0; i < N.size(); i++)
	{
		num.push(N[i]-'0');	//逐位读入
	}
	for (int i = 0; i < K; i++)
	{
		rev = reverse(num);
		if (equal(num, rev))
		{
			while (!num.empty())
			{
				cout << num.top();
				num.pop();
			}
			cout << endl << i;
			return 0;
		}
		else
		{
			num = addReverse(num);
		}
	}
	while (!num.empty())
	{
		cout << num.top();
		num.pop();
	}
	cout << endl << K;
	return 0;
}
stack<int> reverse(stack<int> num)
{
	stack<int> r;
	while(!num.empty())
	{
		r.push(num.top());
		num.pop();
	}
	return r;
}
stack<int> addReverse(stack<int> num)
{
	stack<int> r = reverse(num);
	stack<int> result;
	result.push(0);
	while (!num.empty())
	{
		int x = result.top() + num.top() + r.top();
		result.top() = x % 10;
		result.push(x / 10);
		num.pop();
		r.pop();
	}
	if (result.top() == 0)
		result.pop();
	return result;
}
bool equal(stack<int> num, stack<int> rev)
{
	bool flag = true;
	while (!num.empty())
	{
		if (num.top() != rev.top())
		{
			flag = false;
			break;
		}
		num.pop();
		rev.pop();
	}
	return flag;
}