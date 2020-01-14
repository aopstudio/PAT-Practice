#include <iostream>
#include <string>
using namespace std;
int main()
{
	int total;
	/*int unlockHour,unlockMinute,unlockSecond,lockHour, lockMinute, lockSecond;
	int inHour, inMinute, inSecond, outHour, outMinute, outSecond;*/
	char c;
	string unlocker, locker, nowPerson, unlockTime, lockTime, inTime, outTime;
	cin >> total;

	for (int i = 0; i < total; i++)
	{
		if (i == 0)	//初始化
		{
			cin >> unlocker >> unlockTime >> lockTime;
			locker = unlocker;
			//scanf_s("%d:%d:%d %d:%d:%d", &unlockHour, &unlockMinute, &unlockSecond, &lockHour, &lockMinute, &lockSecond);	//C语言风格
			//cin >> unlockHour >> c >> unlockMinute >> c >> unlockSecond >> lockHour >> c >> lockMinute >> c >> lockSecond;	//C++风格
		}
		else
		{
			cin >> nowPerson >> inTime >> outTime;
			if (inTime < unlockTime)
			{
				unlockTime = inTime;
				unlocker = nowPerson;
			}
			if (outTime > lockTime)
			{
				lockTime = outTime;
				locker = nowPerson;
			}
		}
	}
	cout << unlocker << ' ' << locker;
	return 0;
}