#include<iostream>
#include<iomanip>
using namespace std;
#define ROW 6
#define COL 5
int matrix_spiral_order(int arr[ROW][COL])
{
	int Rstart=0,Rend=ROW-1,Cstart=0,Cend=COL-1;
	cout<<"Spiral order Matrix traversal"<<endl;
	while(Cstart<=Cend || Rstart <= Rend)
	{
		for(int i=Cstart;i<=Cend;i++)
			cout<<arr[Rstart][i]<<",";
		cout<<endl;
		Rstart++;
		for(int i=Rstart;i<=Rend;i++)
			cout<<arr[i][Cend]<<",";
		cout<<endl;
		Cend--;
		for(int i=Cend;i>=Cstart;i--)
			cout<<arr[Rend][i]<<",";
		cout<<endl;
		Rend--;
		for(int i=Rend;i>=Rstart;i--)
			cout<<arr[i][Cstart]<<",";
		cout<<endl;
		Cstart++;
	}
	return 0;
}

int main()
{
	int arr[6][5];
	int count=1;
	for(int i=0;i<ROW;i++)
	{
		for(int j=0;j<COL;j++)
		{
			arr[i][j]=count++;
			cout<<setw(4)<<arr[i][j];
		}
		cout<<endl;
	}
	matrix_spiral_order(arr);
	return 0;
}
