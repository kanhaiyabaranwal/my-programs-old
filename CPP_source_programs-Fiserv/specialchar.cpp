#include<iostream>

using namespace std;

int singleQuote(char *input,char* output)
{
	char *pch=input;
	while(*input)
	{
		*output++=*input++;
		if(*input=='\'')
			*output++='\'';
	}
	*output=NULL;
	return 0;
}
int main()
{
	char str[25];
	cout<<"Enter string->"<<endl;
	cin>>str;
	char *out=new char[2*strlen(str)];
	singleQuote(str,out);
	cout<<"input is "<<str<<" and output string is "<<out<<endl;
	return 0;
}
