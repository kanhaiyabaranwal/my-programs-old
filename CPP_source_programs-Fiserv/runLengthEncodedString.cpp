//Given an input string, write a function that returns the Run Length Encoded string for the input string.
//For example, if the input string is “wwwwaaadexxxxxx”, then the function should return “w4a3dex6?.
#include<iostream>
#include<string.h>

using namespace std;

int main()
{
	char str[]="wwwwaaadexxxxxx";
	char *pstr=str;
	int len;
	cout<<*pstr;
	char prev_ch=*pstr;
	pstr++;
	len=1;
	while(*pstr)
	{
		if(*pstr!=prev_ch)
		{
			if(len==1)
				cout<<*pstr;
			else
				cout<<len<<*pstr;
			len=1;
			prev_ch=*pstr;
		}
		else
			len++;
		pstr++;
	}
	cout<<len;
	cout<<endl;
	
}
