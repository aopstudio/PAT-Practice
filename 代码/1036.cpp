#include <iostream>
#include <string>
using namespace std;
struct stu
{
	string name,id;
	int grade;
};

int main()
{
	stu boy;
	stu girl;
	int high = 0, low = 100;
	bool fb = false, fg = false;	//确定有没有男生或女生
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		stu s;
		char g;
		cin >> s.name >> g >> s.id >> s.grade;
		if (g == 'M')
		{
			fb = true;
			if (s.grade <= low)
			{
				boy = s;
				low = s.grade;
			}
		}
		else
		{
			fg = true;
			if (s.grade >= high)
			{
				girl = s;
				high = s.grade;
			}
		}
	}
	if (!fg || !fb)
	{
		if (!fg)	//女生缺席
			cout << "Absent" << endl;
		else
			cout << girl.name << ' ' << girl.id << endl;
		if (!fb)	//男生缺席
			cout << "Absent" << endl; 
		else
			cout << boy.name << ' ' << boy.id << endl;
		cout << "NA";
	}
	else
	{
		cout << girl.name << ' ' << girl.id << endl;
		cout << boy.name << ' ' << boy.id << endl;
		cout << girl.grade - boy.grade;
	}
	return 0;
}