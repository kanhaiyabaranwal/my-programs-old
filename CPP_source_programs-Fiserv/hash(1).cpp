#include<iostream>
#include<ctime>
#include<stdlib.h>
using namespace std;

int main()
{
	int *htable[10];	//table of 10 hash keys
	for(int i=0;i<10;i++)
	{
		htable[i]=new int[5];	//accept at the most 5 values
		for(int j=0;j<5;j++)
			htable[i][j]=0;
	}
	srand(time(NULL));
	int hash;
	for(int i=0;i<30;i++)
	{
		int val=rand();
		cout<<"val="<<val<<"\t";
		hash=val%10;
		int j;
		for(j=0;j<5;j++)
			if(!htable[hash][j])
			{
				htable[hash][j]=val;
				break;
			}
		if(j==5)
			cout<<"\nOops! Hash table is full for key "<<hash<<".Couldn't insert "<<val<<endl;
	}
	cout<<endl;
	for(int i=0;i<10;i++)
	{
		cout<<"Hash values for key "<<i<<"->\t";
		for(int j=0;j<5;j++)
			if(htable[i][j])
				cout<<htable[i][j]<<"\t";
		cout<<endl;
	}

	
	return 0;
}
	
