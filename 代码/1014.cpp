#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct cInfo
{
	int cNum;	//顾客编号
	int pTime;	//需要处理的时间
	int beginTime, endTime;
};
int main()
{
	int N, M, K, Q;
	cin >> N >> M >> K >> Q;
	vector<queue<cInfo> > lines(N+1);
	queue<cInfo> outWait;	//在黄线外等待的顾客
	vector<int> hTime(N + 1, 0);	//队列队首处理完毕后的时间（自8点算起）
	vector<int> tTime(N + 1, 0);	//队列队尾处理完毕后的时间
	vector<cInfo> customers(K+1);	//每位顾客处理完毕后的时间
	for (int i = 0; i < K; i++)
	{
		int pTime, lNum;
		lNum = (i % N) + 1;
		cin >> pTime;
		cInfo customer;
		customer.cNum = i + 1;
		customer.pTime = pTime;
		if (i < M * N)	//队列还有空位
		{
			if (i < N)
				hTime[lNum] = pTime;	//每个队列添加第一个顾客，确定队首处理完毕后的时间
			lines[lNum].push(customer);
			customer.beginTime = tTime[lNum];	//开始时间为前一个队尾结束的时间
			//customers[i + 1].beginTime = tTime[lNum];	
			tTime[lNum] += pTime;	//更新当前队尾
			customer.endTime = tTime[lNum];
			customers[i + 1] = customer;	//结束时间为更新后的队尾时间
		}
		else	//队列全部已满
		{
			outWait.push(customer);
		}
	}
	while (outWait.size() != 0)	//在黄线外等待的不为空
	{
		int min=hTime[1], num = 1;
		for (int i = 2; i < N + 1; i++)
		{
	
			if (hTime[i] < min)
			{
				min = hTime[i];
				num = i;
			}
		}
		lines[num].pop();
		cInfo c = outWait.front();
		outWait.pop();
		lines[num].push(c);
		hTime[num] += lines[num].front().pTime;
		customers[c.cNum].beginTime = tTime[num];
		tTime[num] += c.pTime;
		customers[c.cNum].endTime = tTime[num];
	}
	for (int i = 0; i < Q; i++)
	{
		int cNum;
		cin >> cNum;
		if (customers[cNum].beginTime >= 540)
			cout << "Sorry" << endl;
		else
		{
			int hour, minute;
			hour = 8 + customers[cNum].endTime / 60;
			minute = customers[cNum].endTime % 60;
			if (hour < 10)
				cout << '0' << hour << ':';
			else
				cout << hour << ':';
			if (minute < 10)
				cout << '0' << minute << endl;
			else
				cout << minute << endl;
		}
	}
	return 0;
}