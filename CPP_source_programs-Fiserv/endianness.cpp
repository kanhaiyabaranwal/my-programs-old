#include<stdio.h>

int main()
{
	int i=0x32FF3433;
	char ch=*((char*)&i);
	printf("ch=%c\n",ch);
	return 0;
}
