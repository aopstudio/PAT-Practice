#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <set>
using namespace std;
struct user
{
	string name;
	string password;
};

int main()
{
	vector<user> users;
	vector<user> result;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		user u;
		cin >> u.name >> u.password;
		users.push_back(u);
	}
	for (int i = 0; i < users.size(); i++)
	{
		user u = users[i];
		int flag = 0;
		for (int j = 0; j < u.password.length(); j++)
		{
			if (u.password[j] == '1')
			{
				u.password[j] = '@';
				flag = 1;
			}
			if (u.password[j] == '0')
			{
				u.password[j] = '%';
				flag = 1;
			}
			if (u.password[j] == 'l')
			{
				u.password[j] = 'L';
				flag = 1;
			}
			if (u.password[j] == 'O')
			{
				u.password[j] = 'o';
				flag = 1;
			}
		}
		if (flag == 1)
			result.push_back(u);
	}
	if (result.size() > 0)
	{
		cout << result.size() << endl;
		for (int i = 0; i < result.size(); i++)
		{
			cout << result[i].name << ' ' << result[i].password << endl;
		}
	}
	else
	{
		if (N == 1)
			cout << "There is 1 account and no account is modified";
		else
			cout << "There are " << N << " accounts and no account is modified";
	}
	return 0;
}