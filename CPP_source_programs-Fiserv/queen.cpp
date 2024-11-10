//placing queen in an 8X8 board such that they are not on same row,column and diagonally do not cross.
#include<iostream>
#include<algorithm>
#include<vector>
#include<iomanip>
using namespace std;
#define ROW 8
#define COL 8

void display_queen(int *cell)
{
	int row;
	for(row=0;row<ROW-1;row++)
		cout<<cell[row]<<",";
	cout<<cell[row]<<endl;
}

bool validate_queen(int *cell, int row,int col)
{
	for(int r=0;r<row;r++)
	{
		if((cell[r]==col) ||
		  ( row-r<=col && col-cell[r]==row-r) || 
		  (row-r<=COL-col && cell[r]-col==row-r))
			return false;
	}
	cell[row]=col;
	return true;
}
bool place_queen(int *cell,int row=0)
{
	if(row>7)
	{
		cout<<"All queens placed successfully"<<endl;
		return true;
	}
	for(int col=0;col<COL;col++)
	{
		if(validate_queen(cell,row,col) && place_queen(cell,row+1))
			return true;
	}
	return false;
}
int main()
{
	cout<<"placing queen in an 8X8 board so that they don't attack each other"<<endl;
	int *cell=new int[ROW];
	for(int i=0;i<ROW;i++)
		cell[i]=-1;
	if(place_queen(cell))
	{
		cout<<"Queens successfully placed"<<endl;
		display_queen(cell);
	}
	else
		cout<<"Could not place queens"<<endl;
	return 0;
}
