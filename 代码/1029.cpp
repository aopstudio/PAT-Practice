#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<long> seq1,seq2;
	int m,n,k;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int num;
		cin >> num;
		seq1.push_back(num);
	}
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		seq2.push_back(num);
	}
	k = m + n;
	int count=0,p1=0,p2=0,median;
	while (p1 < m&&p2 < n)
	{
		count++;
		if (count == (k+1) / 2)
		{
			median = seq1[p1] < seq2[p2] ? seq1[p1] : seq2[p2];
			break;
		}
		if (seq1[p1] < seq2[p2])
		{
			p1++;
		}
		else
		{
			p2++;
		}
	}
	while (count != (k + 1) / 2 && p1 == m)
	{
		count++;
		if (count == (k + 1) / 2)
		{
			median = seq2[p2];
		}
		p2++;
	}
	while (count != (k + 1) / 2 && p2 == n)
	{
		count++;
		if (count == (k + 1) / 2)
		{
			median = seq1[p1];
		}
		p1++;
	}
	cout << median;
    return 0;
}