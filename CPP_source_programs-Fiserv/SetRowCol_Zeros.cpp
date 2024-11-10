//Setting row and column values with zeroes if the cell is zero
#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;
#define R 7
#define C 8

int main()
{
	int matrix[R][C];
	srand(time(NULL));
	int val;
	for(int i=0;i<R;i++)
	{
		for(int j=0;j<C;j++)
		{
			val=rand()%10;
			matrix[i][j]=val;
			cout<<matrix[i][j]<<"\t";
		}
		cout<<endl;
	}
	//after inversion
	int row=0,col=0;
	for(int i=0;i<R;i++)
	{
		for(int j=0;j<C;j++)
		{
			if(matrix[i][j]==0)
			{
				row|=(1<<i);
				col|=(1<<j);
			}
			
		}
		cout<<endl;
	}
	for(int i=0;i<R;i++)
		if(row&(1<<i))		//make all col values zero
		{
			for(int j=0;j<C;j++)
				matrix[i][j]=0;
		}
	for(int i=0;i<C;i++)
		if(col&(1<<i))		//make all col values zero
		{
			for(int j=0;j<R;j++)
				matrix[j][i]=0;
		}
	for(int i=0;i<R;i++)
	{
		for(int j=0;j<C;j++)
		{
			cout<<matrix[i][j]<<"\t";
		}
		cout<<endl;
	}
	
		
	return 0;
}
