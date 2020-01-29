#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

struct record	//通话记录信息
{
	string name;	//通话客户名
	int month, day, hour, minute, time, status;	
	//time代表从当月0号0点0分开始（理论上的）开始经过的总时间，用于比较时间先后；status代表是接通还是挂断
};
bool compare(record a, record b)
{
	return a.name == b.name ? a.time < b.time : a.name < b.name;	//将记录先按客户名字典顺序，后按时间顺序排序
}
int dayToll = 0;	//一整天的费用
vector<int> tolls;	//存储每个小时的话费信息
double tollFromZero(record r);
int main()
{
	vector<string> index;	//姓名和对应的数组编号
	for (int i = 0; i < 24; i++)
	{
		int toll;
		cin >> toll;
		tolls.push_back(toll);
		dayToll += toll * 60;
	}
	int N;
	cin >> N;
	vector<record> records(N);	//存储所有通话记录
	for (int i = 0; i < N; i++)
	{
		cin >> records[i].name;
		scanf("%d:%d:%d:%d", &records[i].month, &records[i].day, &records[i].hour, &records[i].minute);
		string sta;
		cin >> sta;
		if (sta == "on-line")
			records[i].status = 1;
		else
			records[i].status = 0;
		records[i].time = records[i].day * 24 * 60 + records[i].hour * 60 + records[i].minute;
	}
	sort(records.begin(), records.end(), compare);
	map<string, vector<record> > result;	//存储每个顾客对应的通话记录
	for (int i = 1; i < records.size(); i++)
	{
		if (records[i].name == records[i - 1].name&&records[i].status == 0 && records[i - 1].status == 1)
		{
			string name = records[i].name;
			result[name].push_back(records[i - 1]);
			result[name].push_back(records[i]);
		}
	}
	for (auto it : result)
	{
		vector<record> temp = it.second;
		cout << it.first << ' ';
		printf("%02d\n", temp[0].month);
		double total = 0.0;	//总费用
		for (int i = 0; i < temp.size(); i += 2)
		{
			double onceToll;	//单次通话费用
			onceToll = tollFromZero(temp[i + 1]) - tollFromZero(temp[i]);
			printf("%02d:%02d:%02d ", temp[i].day, temp[i].hour, temp[i].minute);
			printf("%02d:%02d:%02d ", temp[i + 1].day, temp[i + 1].hour, temp[i + 1].minute);
			printf("%d ", temp[i + 1].time - temp[i].time);
			printf("$%.2lf\n", onceToll);
			total += onceToll;
		}
		printf("Total amount: $%.2lf\n", total);
	}
	return 0;
}
double tollFromZero(record r)
{
	double sumToll = dayToll * r.day + tolls[r.hour] * r.minute;	//把当月前几天的费用和当前小时分钟数的费用算了
	for (int i = 0; i < r.hour; i++)	//再算当天前几个小时的费用
	{
		sumToll += tolls[i] * 60;
	}
	return sumToll / 100;	//单位从分转换为元
}