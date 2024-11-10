#include<iostream>
using namespace std;

void mul(int F[2][2],int M[2][2])
{
	int x=F[0][0]*M[0][0]+F[0][1]*M[1][0];
	int y=F[0][0]*M[0][1]+F[0][1]*M[1][1];
	int z=F[1][0]*M[0][0]+F[1][1]*M[1][0];
	int t=F[1][0]*M[0][1]+F[1][1]*M[1][1];
	F[0][0]=x;
	F[0][1]=y;
	F[1][0]=z;
	F[1][1]=t;
}

int fib(int F[2][2],int n)
{
	int M[2][2]={{1,1},{1,0}};
	for(int i=0;i<n;i++)
		mul(F,M);
	return F[0][0];
}

int main()
{
	int F[2][2]={{1,1},{1,0}};
	int n;
	cout<<"Enter number whose fibonacci is required\n";
	cin>>n;
	int f=fib(F,n-1);
	cout<<"Fibonacci number="<<f<<endl;
	return 0;
}

