//Dijkstra's algorithm to find shortest path from source vertex to every other vertex.
//using adjacency matrix
#include<iostream>
#include<iomanip>
using namespace std;
#define NBR_OF_VERTICES 5

int main()
{
	int matrix[NBR_OF_VERTICES][NBR_OF_VERTICES]={-1};
	cout<<"Adjacency Matrix is"<<endl; 
	//cout.setw(2);
	
	for(int row=0;row<NBR_OF_VERTICES;row++)
	{
		for(int col=0;col<NBR_OF_VERTICES;col++)
		{
			if(row==col)
				matrix[row][col]=0;
			else
				matrix[row][col]=-1;
			//cout<<setw(2)<<matrix[row][col]<<" ";
		}
		//cout<<endl;
	}
	//set adjacency matrix path
	matrix[0][1]=4;
	matrix[0][2]=1;
	matrix[1][4]=4;
	matrix[2][1]=2;
	matrix[2][3]=4;
	matrix[3][4]=4;
	cout<<"   A  B  C  D  E"<<endl;
	for(int row=0;row<NBR_OF_VERTICES;row++)
	{
		cout<<char(row+'A')<<" ";
		for(int col=0;col<NBR_OF_VERTICES;col++)
			cout<<setw(2)<<matrix[row][col]<<" ";
		cout<<endl;
	}
}
