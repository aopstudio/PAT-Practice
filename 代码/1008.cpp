#include <iostream>
using namespace std;
int main()
{
	int requestSum;	//请求总数
	int currentFloor = 0;	//当前楼层
	int nextFloor;	//接下来要前往的楼层
	int totalTime = 0;	//总时长
	cin >> requestSum;
	for (int i = 0; i < requestSum; i++)
	{
		cin >> nextFloor;
		if (nextFloor > currentFloor)
		{
			totalTime += 6 * (nextFloor - currentFloor);
			currentFloor = nextFloor;
		}	
		else if (nextFloor < currentFloor)
		{
			totalTime += 4 * (currentFloor - nextFloor);
			currentFloor = nextFloor;
		}
		totalTime += 5;
	}
	cout << totalTime;
	return 0;
}