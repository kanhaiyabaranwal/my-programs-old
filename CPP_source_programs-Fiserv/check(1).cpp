#include <iostream.h>
#include <stdio.h>
using namespace std;

struct s{
	int num;
} sp;

int& fun(s &s1, int num)
{
	s1.num=num;
	printf("s1.num=%d inside func\n",s1.num);
	return s1.num;
}
int main()
{
	pid_t pid;
	int i,num=8;
	const int x=num;
	struct s s1;
	s1.num=4;
	printf("s1.num=%d before func\n",s1.num);
	fun(s1, num) =5;
	printf("s1.num=%d after func\n",s1.num);
	
	return 01;
}
		
