#include <iostream>
#include <vector>
using namespace std;
char transfer(int j);
int main()
{
	double maxNums[3];
	char results[3];
	double profit;
	for (int i = 0; i < 3; i++)
	{
		double max = 0.0, num;
		for (int j = 0; j < 3; j++)
		{
			cin >> num;
			if (num > max)
			{
				max = num;
				results[i] = transfer(j);
			}
		}
		maxNums[i] = max;
	}
	profit = (maxNums[0] * maxNums[1] * maxNums[2] * 0.65 - 1) * 2;
	for (int i = 0; i < 3; i++)
		cout << results[i] << ' ';
	printf("%.2lf", profit);
}
char transfer(int j)
{
	switch (j)
	{
	case 0:
		return 'W';
	case 1:
		return 'T';
	case 2:
		return 'L';
	}
}