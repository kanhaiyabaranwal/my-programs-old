#include<stdio.h>

void funct()
{
	printf("Inside func\n");
}

int main()
{
	atexit(funct);
	printf("I am in main\n");
	return 0;
}
