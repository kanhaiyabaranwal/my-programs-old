#include<iostream>
using namespace std;


int matrix_rotation(int a[][4],int R,int C)
{
	int r=0,c=0;
	R--,C--;
	while(r<R)
	{
		for(int i=c;i<=C;i++)
			cout<<a[r][i]<<" ";
		r++;
		cout<<endl;
		for(int i=r;i<=R;i++)
			cout<<a[i][C]<<" ";
		C--;
		cout<<endl;
		for(int i=C;i>=c;i--)
			cout<<a[R][i]<<" ";
		R--;
		cout<<endl;
		for(int j=R;j>=r;j--)
			cout<<a[j][c]<<" ";
		c++;
		cout<<endl;
	}
	return 0;
}
int main()
{
	int mat[][4]=   {{1,2,3,4},
			{5,6,7,8},
			{9,10,11,12},
			{13,14,15,16}};
	matrix_rotation(mat,4,4);
	return 0;
}	
