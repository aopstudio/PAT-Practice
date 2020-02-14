#include <iostream>
#include <vector>
using namespace std;
char transfer(int num);
void calculateAndOutput(int num);
int main()
{
	int dr, dg, db;
	cin >> dr >> dg >> db;
	cout << '#';
	calculateAndOutput(dr);
	calculateAndOutput(dg);
	calculateAndOutput(db);
}
char transfer(int num)
{
	if (num < 10)
		return '0' + num;
	else if (num == 10)
		return 'A';
	else if (num == 11)
		return 'B';
	else if (num == 12)
		return 'C';
}
void calculateAndOutput(int num)
{
	vector<int> r;
	while (num / 13 != 0)
	{
		r.push_back(num % 13);
		num /= 13;
	}
	r.push_back(num);
	for (int i = 1; i >= 0; i--)
	{
		cout << transfer(r[i]);
	}
}