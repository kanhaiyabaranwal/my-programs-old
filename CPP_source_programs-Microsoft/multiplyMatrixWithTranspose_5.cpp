#include<iostream>
using namespace std;


void MultiplyMatrixWithTranspose(int s,int rows, int cols)
{
	int **m=new int*[rows];
	for(int i=0;i<rows;i++)
		m[i]=new int[cols];
	
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<cols;j++)
		{
			m[i][j]=s;
			s++;
			cout<<m[i][j]<<",";
		}
		cout<<endl;
			
	}
	cout<<"Transposed matrix"<<endl;
	int trows=cols;
	int tcols=rows;
	int **tm=new int*[trows];
	for(int i=0;i<trows;i++)
		tm[i]=new int[tcols];
	
	for(int i=0;i<trows;i++)
	{
		for(int j=0;j<tcols;j++)
		{
			tm[i][j]=m[j][i];
			
			cout<<tm[i][j]<<",";
		}
		cout<<endl;
			
	}
	
	//multiply matrix with transpose
	cout<<"Multiplied Matrix is "<<endl;
	int mmrows=rows;
	int mmcols=rows;
	int **mm=new int*[mmrows];
	for(int i=0;i<mmrows;i++)
		mm[i]=new int[mmcols];
	for(int i=0;i<mmrows;i++)
	{
		for(int j=0;j<mmcols;j++)
		{
			int col=0;
			int val=0;
			while(col<cols)
			{
				val+=m[i][col]*tm[col][j];
				col++;
			}
			mm[i][j]=val;
			cout<<mm[i][j]<<",";
		}
		cout<<endl;
	}
	
	
		
		
	
}

int main()
{
	MultiplyMatrixWithTranspose(3,4,2);
	cout<<"Hello World"<<endl;
	return 0;
}
