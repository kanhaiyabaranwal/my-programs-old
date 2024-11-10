#include<iostream>
using namespace std;

int xcelMapping(int num)
{
	int temp=num;
	int i=0;
	char ch[10];
	int index=26;
	while(temp>0)
	{
		int r=temp%26;
		if(r>0)
		{
			ch[i++]=r+64;
			temp-=r;
		}
		else
		{
			ch[i++]='Z';
			temp-=index;
		}
		temp/=index;
	}
	ch[i--]=NULL;
	cout<<"excel mapping is ";
	for(;i>=0;i--)
		cout<<ch[i];
	cout<<endl;
	
	return 0;
}
int main()
{
	cout<<"Excel mapping of a number"<<endl;
	cout<<"Number? " ;
	int num;
	cin>>num;	
	xcelMapping(num);
	return 0;
}
