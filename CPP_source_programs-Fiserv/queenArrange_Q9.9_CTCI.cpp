#include<iostream>
#include<cmath>
using namespace std;
#define ROW 8
#define COL 8
//Q[i] is column position where queen can be placed in i th row.
int Q[ROW];

int nextQueen(int row)
{
	static int count;
	for(int col=0;col<COL;col++)	//try populating in each column
	{
		int i;
		for(i=0;i<row;i++)		//check for each previously visited row
		{
			if(Q[i]==col || abs(Q[i]-col)==abs(i-row))		//if row difference and column difference has same absolute value, they are on diagonal
				break;
		}
		if(i==row)
		{
			Q[i]=col;
			//cout<<"Queen["<<row<<"]="<<col<<endl;
			if(i==ROW-1)
			{
				cout<<"Possible combinations of queens are ->";
				for(int m=0;m<ROW;m++)
					cout<<Q[m]<<",";
				cout<<endl;
				count++;
			}
			else
				nextQueen(row+1);
		}
	}
	return count;
}



int main()
{
	cout<<"Algo putting 8 queens on the chess board"<<endl;
	for(int row=0;row<ROW;row++)
		Q[row]=-1;					//not positioned initially
	int count=nextQueen(0);
	cout<<"Nbr of Possible solutions are "<<count<<endl;
	return 0;
}
