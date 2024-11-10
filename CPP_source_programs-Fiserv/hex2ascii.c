#include<stdio.h>

int hex2ascii(char *hex,char* ascii)
{
        printf("hex value is %s\n",hex);
	char *ch=hex;
	int x;
	while(*ch != '\0' && *(ch+1)!= '\0' )
	{
		x=atoi(*ch)*16 + atoi(*ch);
		printf("*ch=%c,(*ch+1)=%c, decimal value is %d and Ascii value is %c\n",*ch,*(ch+1),x,x);
		//*ascii=*ch*16 + *ch;	
		ch+=2;
	}
        return 0;
}

int main()
{
        char hex[]="37363035";
        char ascii[20]={0};
	char c='3';
	char d='7';
	int x=atoi(c);
	printf("c=%d,c=%c",c,c);
	
        //int rc=hex2ascii(hex,ascii);
        return 0;
}

