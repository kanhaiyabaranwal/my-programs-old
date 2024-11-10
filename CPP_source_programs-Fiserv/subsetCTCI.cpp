//power set - printing all subsets of a set
#include<iostream>
#include<vector>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;

void subset(char arr[])
{
	int len=strlen(arr);
	int power=pow(2,len);
	cout<<"len="<<len<<",power="<<power<<endl;
	for(int i=0;i<power;i++)
	{
		cout<<"{";
		for(int j=0;j<len;j++)
		{
			if(i & (1<<j))			//if jth bit is set, display that character
				cout<<arr[j];
		}
		cout<<"},";
	}
	
	return;
}

int main()
{
	char arr[]={"abc"};
	subset(arr);
	return 0;
}
