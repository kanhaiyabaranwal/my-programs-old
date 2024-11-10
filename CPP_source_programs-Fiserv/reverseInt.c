#include<stdio.h>

void main()
{
	int num=12345;
	int revNum,temp;
	temp=num;
	revNum=0;
	while(temp>0)
	{
		revNum=revNum*10+temp%10;
		temp/=10;
	}
	printf("reverse of %d is %d\n",num,revNum);
}
