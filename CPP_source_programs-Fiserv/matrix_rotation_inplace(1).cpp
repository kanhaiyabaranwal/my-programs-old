//Inplace matrix rotation by 90 degree
#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
#define NBR 5
int main()
{
	int matrix[NBR][NBR];
	srand(time(NULL));
	int val;
	cout<<"Inplace matrix rotation by 90 degree\n";
	cout<<"Original matrix\n";
	for(int i=0;i<NBR;i++)
	{
		for(int j=0;j<NBR;j++)
		{
			matrix[i][j]=rand()%10;
			cout<<matrix[i][j]<<"\t";
		}
		cout<<endl;
	}
	cout<<"reversed matrix\n";
	int lastcolIndex=NBR-1;
	for(int j=0;j<NBR/2;j++)
	{
		for(int i=j;i<lastcolIndex-1;i++)
		{
			int nextrow=i;
			int nextcol=i;
			int startcell=matrix[i][i];
			int curcell=startcell;
			int currow=i;
			do{
				nextrow=nextcol;
				nextcol=lastcolIndex-currow;	
				int temp=matrix[nextrow][nextcol];	//keep next cell for comparison
				matrix[nextrow][nextcol]=curcell;
				curcell=temp;
				currow=nextrow;
			}while(curcell!=startcell);
		}
	}
	for(int i=0;i<NBR;i++)
	{
		for(int j=0;j<NBR;j++)
			cout<<matrix[i][j]<<"\t";
		cout<<endl;
	}

}
