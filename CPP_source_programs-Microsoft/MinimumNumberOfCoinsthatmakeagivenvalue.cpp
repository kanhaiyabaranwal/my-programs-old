#include<iostream>
#include<algorithm>
using namespace std;
//Find minimum number of coins that make a given value

FindMin(int coins[],int m,int V)
{
	int table[V+1];
	sort(coins,coins+4);
	for(int i=0;i<m;i++)
		cout<<coins[i]<<",";
	cout<<endl;
	for(int i=1;i<=V;i++)
	{
		table[i]=INT_MAX;
	}
	
	table[0]=0;
	for(int i=1;i<=V;i++)
	{
		for(int j=0;j<m;j++)
		{
			
			if(coins[j]<=i )
			{
				if(table[i-coins[j]]+1<table[i])
					table[i]=table[i-coins[j]]+1;
				
			}
			else 
				break;
		}
	}
	cout<<"min coins required:"<<table[V]<<endl;
}

int main()
{
	int coins[] =  {9, 6, 5, 1}; 
	int m=sizeof(coins)/sizeof(coins[0]);
	int V=11;
	FindMin(coins,m,V);
	return 0;
}
