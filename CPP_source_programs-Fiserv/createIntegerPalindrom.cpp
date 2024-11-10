#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int createIntegerPalindrom(int num)
{
	char str[20];
	sprintf(str,"%d",num);
	int len=strlen(str);
	int leftmid,rightmid;
	//works in both cases odd and even
	leftmid=len/2-1;
	bool changed=0;
	if(len%2==0)	//if even, next is rightmid
		rightmid=leftmid+1;
	else
	{
		rightmid=leftmid+2;
		if(str[leftmid]<str[rightmid])
		{
			str[leftmid+1]+=1;
			str[rightmid]=str[leftmid];
		}
		else
		{
			str[leftmid+1]='0';
			str[rightmid]=str[leftmid];
		}
		leftmid--;rightmid++;
		changed=1;
	}
	while(leftmid>=0 && rightmid <len)
	{
		if(str[leftmid]==str[rightmid])
			continue;
		else if(str[leftmid]<str[rightmid])
		{
			if(changed)
				str[rightmid]=str[leftmid];
			else
			{
				str[leftmid]+=1;
				str[rightmid]=str[leftmid];
			}
		}
		else 	//str[leftmid]>str[rightmid]
		{
			str[rightmid]=str[leftmid];
		}
		leftmid--,rightmid++;
	}
	cout<<"Next largest palindrome is "<<str<<endl;
	return 0;
}

int main()
{
	int num;
	cout<<"Creates Palindrom. Enter Base Number->";
	cin>>num;
	createIntegerPalindrom(num);
	return 0;
}
