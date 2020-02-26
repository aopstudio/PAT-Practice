#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	vector<string> cards(55);
	vector<int> newPos(55);
	int N;
	cin >> N;
	for (int i = 1; i < 55; i++)
	{
		string color;
		if (i < 14)
			color = "S";
		else if (i < 27)
			color = "H";
		else if (i < 40)
			color = "C";
		else if (i < 53)
			color = "D";
		else
			color = "J";
		string num = color + to_string((i - 1) % 13 + 1);
		cards[i] = num;
	}
	for (int i = 1; i < 55; i++)
	{
		int pos;
		cin >> pos;
		newPos[i] = pos;
	}
	for (int i = 0; i < N; i++)
	{
		vector<string> newCards(55);
		for (int j = 1; j < 55; j++)
		{
			int newLoc = newPos[j];
			newCards[newLoc] = cards[j];
		}
		cards = newCards;
	}
	for (int i = 1; i < 55; i++)
	{
		if (i == 1)
			cout << cards[i];
		else
			cout << ' ' << cards[i];
	}
	return 0;
}