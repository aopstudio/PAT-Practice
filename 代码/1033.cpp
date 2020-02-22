#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
struct station
{
	double price;
	double dis;
};
bool cmp(station s1, station s2)
{
	return s1.dis < s2.dis;
}
int main()
{
	vector<station> stations;
	double sumCost = 0.0;
	int n;
	double d, cm, da;
	double volumn = 0;	//当前油量
	cin >> cm >> d >> da >> n;
	double maxRun = cm * da;	//最大续航里程
	for (int i = 0; i < n; i++)
	{
		station s;
		cin >> s.price >> s.dis;
		stations.push_back(s);
	}
	station s;
	s.dis = d;
	stations.push_back(s);
	sort(stations.begin(), stations.end(), cmp);
	if (stations[0].dis != 0)
	{
		cout << "The maximum travel distance = 0.00";
		return 0;
	}
	int p = 0;
	while (p < stations.size())
	{
		double loc = stations[p].dis;
		double price = stations[p].price;
		if ((loc + maxRun < d&&p == stations.size() - 1) || loc + maxRun < stations[p + 1].dis) //在最后一个加油站跑不到目的地，或者在之前的加油站跑不到下一个加油站
		{
			double far = loc + maxRun;
			cout << "The maximum travel distance = ";
			printf("%.2f", far);
			return 0;
		}
		//在当前加油站加满油的情况下，寻找是否有加油站的价格低于当前加油站，找到最近的那个，并将油加至刚好能行驶到那里
		//如果找不到价格更低的，就寻找一个价格最低的，并加满油，行驶到那个加油站

		int next = -1;
		double temp = 200.0;	//初始油价
		for (int i = p + 1; i <= n; i++)  //查找能到达的所有加油站的最低价格
		{
			if (stations[i].dis > loc + maxRun)	//超出续航里程范围
				break;
			if (stations[i].price < stations[p].price)
			{
				temp = stations[i].price;
				next = i;
				break;
			}
			if (stations[i].price < temp) 
			{
				temp = stations[i].price;
				next = i;
			}
		}
		if (next == n)	//最后一个加油站
		{
			sumCost += ((d - loc) / da - volumn)*price;
			printf("%.2f", sumCost);
			return 0;
		}
		if (temp <= price)	//有比当前价格更低的价格
		{
			p = next;	//记录下一站
			double dist = stations[p].dis - loc;
			sumCost += (dist / da - volumn) * price;	//需要的油量减去当前剩余油量，再乘以油价
			volumn = 0;	//到达下一个加油站时油量为0
			continue;
		}
		else
		{
			p = next;
			double dist = stations[p].dis - loc;
			sumCost += (cm - volumn) * price;	//加满油需要的油量乘以油价
			volumn = cm - dist / da;	//到达下一个加油站时油量为满油量减去到下个加油站需要的油量
			continue;
		}
	}
	return 0;
}