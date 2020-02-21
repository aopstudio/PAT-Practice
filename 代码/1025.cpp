#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
struct info
{
	string rNum;
	int score, fRank, lNum, lRank;
};
bool compare(info i1, info i2)
{
	return i1.score == i2.score ? i1.rNum<i2.rNum : i1.score>i2.score;	//先按分数从高到低排，如果分数相等按注册号从小到大排
}
int main()
{
	vector<vector<info> > lLists;
	vector<info> fList;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		vector<info> lList;
		int K;
		cin >> K;
		for (int j = 0; j < K; j++)
		{
			string rNum;
			int score;
			cin >> rNum >> score;
			info nInfo;
			nInfo.rNum = rNum;
			nInfo.score = score;
			nInfo.lNum = i + 1;
			lList.push_back(nInfo);
		}
		sort(lList.begin(), lList.end(), compare);
		int hScore = lList[0].score, hRank = 1;
		for (int j = 0; j < lList.size(); j++)
		{
			if (lList[j].score == hScore)
				lList[j].lRank = hRank;
			else
			{
				hScore = lList[j].score;
				lList[j].lRank = j + 1;
				hRank = j + 1;
			}
		}
		lLists.push_back(lList);
	}
	for (int i = 0; i < lLists.size(); i++)
	{
		vector<info> list = lLists[i];
		for (int j = 0; j < list.size(); j++)
			fList.push_back(list[j]);
	}
	cout << fList.size() << endl;
	sort(fList.begin(), fList.end(), compare);
	int hScore = fList[0].score, hRank = 1;
	for (int i = 0; i < fList.size(); i++)
	{
		if (fList[i].score == hScore)
			fList[i].fRank = hRank;
		else
		{
			hScore = fList[i].score;
			fList[i].fRank = i + 1;
			hRank = i + 1;
		}
		cout << fList[i].rNum << ' ' << fList[i].fRank << ' ' << fList[i].lNum << ' ' << fList[i].lRank << endl;
	}
	return 0;
}