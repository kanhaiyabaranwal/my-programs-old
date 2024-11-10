#include<iostream>

using namespace std;

static int nbrofpaths=0;
static int Row;
static int Column;

int count(int row,int column)
{
	if(row==Row && column==Column)
	{
		
		nbrofpaths++;
		cout<<"Path found "<<nbrofpaths<<endl;
		return 0;
	}
	
	if(row<Row)
		count(row+1,column);
	if(column<Column)
	count(row,column+1);
	return 0;
}


int main()
{
	cout<<"nbr of paths in the matrix\n";
	cout<<"No. of rows?\t";
	cin>>Row;
	cout<<"No. of columns?\t";
	cin>>Column;
	Row-=1;
	Column-=1;
	//int Column=2;
	
	count(0,0);
	cout<<"Total number of paths for "<<Row+1<<"X"<<Column+1<<"Matrix="<<nbrofpaths<<endl;
	return 0;
}
