#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	vector<int> c;
	vector<int> p;
	int a;
	int back = 0;
	cin >> a;
	for (int i = 0; i < a; i++)
	{
		int num;
		cin >> num;
		c.push_back(num);
	}
	int b;
	cin >> b;
	for (int i = 0; i < b; i++)
	{
		int num;
		cin >> num;
		p.push_back(num);
	}
	sort(c.begin(), c.end());
	sort(p.begin(), p.end());
	int p1 = 0, p2 = 0;
	while (p1 < c.size() && p2 < p.size() && c[p1] < 0 && p[p2] < 0)
	{
		back += c[p1] * p[p2];
		p1++; p2++;
	}
	int q1 = c.size() - 1, q2 = p.size() - 1;
	while (q1 >= 0 && q2 >= 0 && c[q1] > 0 && p[q2] > 0)
	{
		back += c[q1] * p[q2];
		q1--; q2--;
	}
	cout << back;
	return 0;
}