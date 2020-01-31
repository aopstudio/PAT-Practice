#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct record
{
	int time, process;	//time代表到达时间，为从00:00:00开始经过的秒数
};
bool compare(record a, record b)
{
	return a.time < b.time;
}
int main()
{
	const int EIGHT = 8 * 3600;	//八点代表的秒数
	const int SEVENTEEN = 17 * 3600;	//十七点代表的秒数
	int N, K;
	double totalTime = 0.0;	//所有顾客的等待时间
	cin >> N >> K;
	vector<record> records;	//存储所有记录
	for (int i = 0; i < N; i++)
	{
		record newRecord;
		int hour, minute, second;
		scanf("%d:%d:%d %d", &hour, &minute, &second, &newRecord.process);
		newRecord.time = hour * 3600 + minute * 60 + second;
		if (newRecord.time > SEVENTEEN)	//如果晚于17：00则不计入
			continue;
		newRecord.process *= 60;	//分钟转换为秒
		records.push_back(newRecord);	//添加新记录
	}
	sort(records.begin(), records.end(), compare);
	vector<int> linesTime(K, EIGHT);	//每个窗口完成当前接待的时间,初始化都为8点
	for (int i = 0; i < records.size(); i++)
	{
		int min = linesTime[0], index = 0;
		for (int i = 1; i < K; i++)	//找出最早完成前一个处理的窗口
		{
			if (linesTime[i] < min)
			{
				min = linesTime[i];
				index = i;
			}
		}
		record r = records[i];
		if (linesTime[index] <= r.time)	//来的时间晚于窗口完成前一个处理的时间
		{
			linesTime[index] = r.time + r.process;	//到达时间加处理时间为窗口完成当前处理的时间，等待时间为0，无需更新
		}
		else //来的时间早于窗口完成前一个处理的时间
		{
			totalTime += linesTime[index] - r.time;	//等待时间加上窗口完成当前处理的时间减到达时间
			linesTime[index] += r.process;	//窗口完成当前处理的时间为完成前一个处理的时间加处理时间
		}
	}
	if (records.size() == 0)	//没有符合的条件，直接输出0.0，因为0不能作除数
		cout << 0.0;
	else
	{
		double average = totalTime / 60.0 / records.size();	//计算平均等待时间（单位为分钟）
		printf("%.1lf", average);
	}
	return 0;
}