#include <iostream>
#include <set>
#include <map>
#include <string>
using namespace std;

int main()
{
	map<string, set<string> > search;
	int N, M;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string ID, title, author, keyword, publisher, year;
		cin >> ID;
		getchar();
		getline(cin, title);
		search[title].insert(ID);
		getline(cin, author);
		search[author].insert(ID);
		while (cin >> keyword)
		{
			search[keyword].insert(ID);
			if (cin.get() == '\n')
				break;
		}
		getline(cin, publisher);
		search[publisher].insert(ID);
		cin >> year;
		search[year].insert(ID);
	}
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		string num, word;
		cin >> num;
		getchar();
		getline(cin, word);
		cout << num << ' ' << word<<endl;
		if (search.find(word) != search.end())
		{
			for (set<string>::iterator it = search[word].begin(); it != search[word].end(); it++)
			{
				cout << *it << endl;
			}
		}
		else
		{
			cout << "Not Found" << endl;
		}
	}
	return 0;
}
