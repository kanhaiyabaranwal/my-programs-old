#include<stdio.h>

int main()
{

	char ch[5]={0};
	ch[0]=0;
	ch[1]=4;
	ch[2]=127;
	ch[3]=161;
	ch[4]=NULL;
	long l=*(long*)ch;
	printf("long l=%ld\n",l);
	return 0;
}
	
