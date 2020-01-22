#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
char numToCourse(int num);
struct result
{
	int bestRank;	//-1代表不存在
	char bestCourse;
};
int main()
{
	int stuNum, rankNum;	//学生总数，要排名的总数
	cin >> stuNum >> rankNum;
	vector<vector<int> > grade;	//成绩矩阵
	map<string,int> index;	//学生ID和在成绩矩阵中的编号对应信息
	vector<result> results;
	for (int i = 0; i < stuNum; i++)
	{
		string id;
		int sum = 0;
		vector<int> stuGrade(4);
		cin >> id;
		index[id] = i;
		for (int j = 1; j < 4; j++)
		{
			int g;
			cin >> g;
			sum += g;
			stuGrade[j] = g;
		}
		stuGrade[0] = sum / 3;
		grade.push_back(stuGrade);
	}
	for (int i = 0; i < rankNum; i++)
	{
		string id;
		cin >> id;
		if (index.find(id) != index.end())	//需要排序的编号在所有学生编号中
		{
			int bestRank = stuNum+1;
			char bestCourse;
			for (int i = 0; i < 4; i++)
			{
				int in = index[id];	//该ID学生对应在grade中的下标
				int g = grade[in][i];	//每次循环时依次为A,C,M,E的成绩
				int gRank = 1;	//g对应的排名
				for (int j = 0; j < stuNum; j++)	//查看当前科目成绩在所有学生中的成绩排名
				{
					if (grade[j][i] > g)
						gRank++;
				}
				if (gRank < bestRank)	//有更高的排名
				{
					bestRank = gRank;	//更新最高排名
					bestCourse = numToCourse(i);
				}
			}
			result r;
			r.bestRank = bestRank;
			r.bestCourse = bestCourse;
			results.push_back(r);
		}
		else //找不到这个编号
		{
			result r;
			r.bestRank = -1;
			results.push_back(r);
		}
	}
	for (int i = 0; i < rankNum; i++)
	{
		if (results[i].bestRank != -1)
			cout << results[i].bestRank << ' ' << results[i].bestCourse << endl;
		else
			cout << "N/A" << endl;
	}
	return 0;
}
char numToCourse(int num)
{
	switch (num)
	{
	case 0:
		return 'A';
	case 1:
		return 'C';
	case 2:
		return 'M';
	case 3:
		return 'E';
	default:
		break;
	}
}