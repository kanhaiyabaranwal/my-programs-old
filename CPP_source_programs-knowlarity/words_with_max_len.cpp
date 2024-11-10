#include<iostream>
using namespace std;

int max_len(char str[])
{
	char *ptr=str;
	int maxlen=0,curlen=0;
	while(*ptr!='\0')
	{
		if(*ptr==' ' || *ptr== '\t')
		{
			if(curlen>maxlen)
				maxlen=curlen;
			curlen=0;
		}
		else
			curlen++;
		ptr++;
	}
	return maxlen;
}

void print_words_of_len(char str[],int len)
{
	char *ptr=str;
	int curlen=0;
	char *word=new char[len+1];
	do
	{
		if(*ptr==' ' || *ptr== '\t' || *ptr=='\0')
		{
			if(curlen==len)
			{
				word[curlen]='\0';
				cout<<"word is "<<word<<endl;
			}
			for(int i=0;i<curlen;i++)
				word[i]='\0';
			curlen=0;
		}
		else
		{
			word[curlen]=*ptr;
			curlen++;
		}
	}
	while(*ptr++!='\0');
	return ;
}
int find_words_with_max_len(char str[])
{
	int maxlen=max_len(str);
	cout<<"Max length of word in the string is "<<maxlen<<endl;
	cout<<"Now printing words of length "<<maxlen<<endl;
	print_words_of_len(str,maxlen);
	return 0;
}

int main()
{
	char str[]="This is a word";
	find_words_with_max_len(str);
	return 0;
}
