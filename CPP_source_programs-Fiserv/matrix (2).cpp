#include<iostream>

using namespace std;
//sort a M*N matrix completely where each row is sorted 
#define M 4	//Num of Rows
#define N 4	//Num of Columns

int a[M][N]={{7,9,12,17}, {3,5,16,19}, {2,6,9,13}, {9,15,18,20}};
static int step=0;
int showMatrix()
{
	for (int i=0; i<M; i++)
	{	for(int j=0; j<N; j++)
			cout<<a[i][j]<<'\t';
		cout<<endl;
	}
	return 0;
}
int swapNSort ( int i,int j,int lowr)
{
	cout<<"Step "<<++step<<endl;
	int lower=a[lowr][0];
	int k;
	
	a[lowr][0]=a[i][j];
	a[i][j]=lower;		//correctly positioned
	//sort rth row
	lower=a[lowr][0];	//new low value of the row
	for(k=1;k<N;k++)
	{
		if(lower > a[lowr][k])
			a[lowr][k-1] = a[lowr][k];
		else
			break;
	}
	a[lowr][k-1]=lower;
	showMatrix();
	return 0;
}

int main()
{
	int lowest,lowr;
	cout<<"Program to sort a M*N matrix completely where each row is sorted"<<endl;

	//show matrix
	showMatrix();


	//sort completely
	for(int i=0;i<M; i++)
	{
		for(int j=0;j<N; j++)
		{
			lowest=a[i][j];
			//put correct value at this position
			//look at each row at 0th column from next row onwards, 
			//since each row is sorted, just need to look at first column value only
			for (int k=i+1;k<M; k++)
			{
				if (a[k][0] < lowest )
					{ lowest = a[k][0];lowr=k;}
			}
			//lower value found, swap and sort that row
			if(lowest < a[i][j])
				swapNSort(i,j,lowr);	
		}
	}
	return 0;
}

