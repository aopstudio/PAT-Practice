#include <iostream>
#include <list>
#include <string.h>
#include <algorithm>
using namespace std;
struct student
{
	char id[7];
	char name[9];
	int grade;
};
bool id(student a, student b)
{
	return strcmp(a.id, b.id) < 0;
}
bool name(student a, student b)
{
	return strcmp(a.name, b.name) == 0 ? strcmp(a.id, b.id) < 0 : strcmp(a.name, b.name) < 0;
}
bool grade(student a, student b)
{
	return a.grade == b.grade ? strcmp(a.id, b.id) < 0 : a.grade < b.grade;
}
int main()
{
	int N, C;
	scanf("%d %d", &N, &C);
	list<student> students;
	for (int i = 0; i < N; i++)
	{
		student stu;
		scanf("%s%s%d", stu.id,stu.name,  &stu.grade);
		students.push_back(stu);
	}
	switch (C)
	{
	case 1:
		students.sort(id);
		break;
	case 2:
		students.sort(name);
		break;
	case 3:
		students.sort(grade);
		break;
	default:
		break;
	}
	for (auto &stu:students)
	{
		printf("%s %s %d\n", stu.id, stu.name, stu.grade);
	}
	return 0;
}