#include<iostream>
using namespace std;

#define NUM_OF_ROWS 5
#define NUM_OF_COLS 4
#define DEST_ROW 2
#define DEST_COL 2

int *matrix[NUM_OF_ROWS];

int findPath(int row,int col)
{
	if(row==DEST_ROW && col==DEST_COL)
	{
		cout<<"Path found@"<<DEST_ROW<<","<<DEST_COL<<endl;
		//cout<<matrix[DEST_ROW][DEST_COL]<<"  ";
		return 1;
	}
	int found=0;
	if(matrix[row][col+1]==1)	//explore path in next column
	{
		found=findPath(row,col+1);
		if(found)
		{
			cout<<row<<","<<col+1<<"  ";
			return 1;
		}
	}
	if(matrix[row+1][col]==1)	//explore path in next column
	{
		found=findPath(row+1,col);
		if(found)
		{	
			cout<<row+1<<","<<col<<"  ";
			return 1;
		}
	}
	return found;

}

int main()
{
	//allocate and initialize matrix elements
	for(int i=0;i<NUM_OF_ROWS;i++)
	{
		matrix[i]=new int[NUM_OF_COLS];
		for(int j=0;j<NUM_OF_COLS;j++)
			matrix[i][j]=0;
	}
	matrix[0][0]=1;
	matrix[0][2]=1;
	matrix[1][0]=1;
	matrix[1][1]=1;
	matrix[1][3]=1;
	matrix[2][0]=1;
	matrix[2][1]=1;
	matrix[2][2]=1;
	matrix[2][3]=1;
	matrix[3][0]=1;
	matrix[4][1]=1;
	//Display 2D matrix
	for(int i=0;i<NUM_OF_ROWS;i++)
	{
		for(int j=0;j<NUM_OF_COLS;j++)
			cout<<matrix[i][j]<<"  ";
		cout<<endl;
	}
	int startRow=0,startCol=0;
	int found=findPath(startRow,startCol);
	if(found)
		cout<<"Path found"<<endl;
	else
		cout<<"Path not found"<<endl;
	return 0;
	
}
