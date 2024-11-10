#include<stdio.h>

int convert(char *str,int sz)
{
	char *initStr=str;
	int initSz=sz*5;
	char *arr=(char*)malloc(initSz);	//assuming expansion by factor of 5
	printf("sizeofstr=%d\n",sizeof(str));
	int count=0;int flag=0;
	char ch;
	while(*str)
	{
		if(flag)
		{
			printf("Wrong sequence of input\n");
			return -1;
		}	
		if(*str>='a' && *str<='z')
		{
			flag=1;
			//ch=arr[count++]=*str;
			ch=*str;
			//count++;
			str++;
		}
		else
		{
			printf("Error at %c\n",*str);
			return -1;
		}
		
		int p=0;
		while(*str>=48 && *str<=57)
		{
			if(!flag)
			{
				printf("Wrong sequence of input\n");
				return -1;
			}
			
			p=p*10+(int)(*str)-48;
			str++;
		}
		flag=0;
		if(initSz<=count+p+2)
		{
			initSz*=2;
			arr=realloc(arr,initSz);
		}
		int i;
		for(i=0;i<p;i++)
		{
			arr[count++]=ch;
		}
	}
	arr[count]='\0';
	printf("Old string: %s;\nconverted string: %s\n",initStr,arr);
	return 0;
}

int main()
{
	char str[]="1a2m0n11b5c5d3f010";
	int num=sizeof(str);
	//sizeof(*str);
	//printf("sizeofstr=%d\n",sizeof(str));
	//printf("num=%d\n",num);
	convert(str,num);
	return 0;
}
