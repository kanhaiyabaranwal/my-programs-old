//matrix rotation by 90 degree
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
	cout<<"matrix rotation by 90 degree\n";
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
	int rmatrix[NBR][NBR];
	for(int i=0;i<NBR;i++)
	{
		for(int j=0;j<NBR;j++)
		{
			rmatrix[i][j]=matrix[j][NBR-1-i];
			cout<<rmatrix[i][j]<<"\t";
		}
		cout<<endl;
	}

}
