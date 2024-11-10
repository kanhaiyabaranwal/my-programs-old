#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int max_len(char *str,int *pcount)
{
	int maxlen=0;
	int len=0;
	int count=0;
	char *pstr=str;
	while(*pstr)
	{
		if(*pstr==' ')
		{
			if(len>maxlen)
			{
				maxlen=len;
				count=1;
			}
			else if(len==maxlen)
				count++;
			len=0;
		}
		else
			len++;
		pstr++;
	}
	if(len>maxlen)
	{
		maxlen=len;
		count=1;
	}
	else if(len==maxlen)
		count++;
	*pcount=count;
	return maxlen;
}


char** max_words(char *str,int maxlen,int count)
{
	int i,j;
	char **words=malloc(sizeof(char**)*count);
	int len=0;
	char *start=str,*pstr=str;
	for(j=0;j<count;j++)
	{
		words[j]=malloc(sizeof(char*)*(maxlen+1));
		memset(words[j],'\0',maxlen+1);
	}
	
	i=0;
	while(*pstr)
	{
		if(*pstr==' ')
		{
			if(len==maxlen)
			{
				strncpy(words[i++],start,maxlen);
				count=1;
			}
			start=pstr+1;
			len=0;
		}
		else
			len++;
		pstr++;
	}
	if(len==maxlen)
		strncpy(words[i++],start,maxlen);
	return words;
}

int main()
{
	int j;
	printf("Kanhaiya");
	char str[]="This is a word of small people and a big animal on the earth. When you need me just remind mom.";
	printf("\nWord is: %s\n",str);
	int count=0;
	
	int len=max_len(str,&count);
	printf("\nMax Length of a word is :%d and number of words is %d\n",len,count);
	char **words=max_words(str,len,count);
	printf("\nWords are:\t");
	for(j=0;j<count;j++)
	{
		printf("%s\t",words[j]);
		
	}
	return 0;
}
