#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	getline(cin, s);
	int maxLength = 1;
	for (int i = 1; i < s.size(); i++)
	{
		if (s[i] == s[i - 1])
		{
			int length = 2;
			int a = i+1, b = i-2;
			while (a < s.size() && b >= 0 && s[a] == s[b])
			{
				length+=2;
				a++; b--;
			}
			if (length > maxLength)
			{
				maxLength = length;
			}
		}
		if (s[i + 1] == s[i - 1])
		{
			int length = 3;
			int a = i + 2, b = i - 2;
			while (a < s.size() && b >= 0 && s[a] == s[b])
			{
				length+=2;
				a++; b--;
			}
			if (length > maxLength)
			{
				maxLength = length;
			}
		}
	}
	cout << maxLength;
	return 0;
}