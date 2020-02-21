#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	string sentence;
	cin >> sentence;
	int N = sentence.length();
	int n1 = (N + 2) / 3;
	int n2 = N + 2 - 2 * n1;
	for (int i = 0; i < n1-1; i++)
	{
		cout << sentence[i];
		for (int j = 0; j < n2 - 2; j++)
			cout << ' ';
		cout << sentence[N - 1 - i]<<endl;
	}
	for (int i = n1 - 1; i < n1 - 1 + n2; i++)
	{
		cout << sentence[i];
	}
	return 0;
}