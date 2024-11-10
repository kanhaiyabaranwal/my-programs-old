#include<iostream>
using namespace std;

void LargestNumberPossible(int N,int S)
{
	int n=0,result=0,toAdd=0,i=0;
	while(n<N)
	{
		toAdd=S>9?9:S;
		result=result*10+toAdd;
		S-=toAdd;
		n++;
	}
	cout<<"LargestNumberPossible:"<<LargestNumberPossible<<endl;
	
}

int main()
{
	int N=4,S=20;
	LargestNumberPossible(N,S);
	cout<<"main:"<<main<<endl;
	return 0;
}
