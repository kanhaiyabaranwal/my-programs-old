#include<iostream>
using namespace std;

int sieve(int n)
{
	int *arr=new int[n];
	for(int i=0;i<=n;i++)
		arr[i]=0;
	for(int i=2;i<=n;i++)
	{
		if(!arr[i])
		for(int j=2*i;j<=n;j+=i)
			arr[j]=1;
	}
	cout<<"All prime numbers upto n are:";
	for(int i=2;i<=n;i++)
		if(!arr[i])
			cout<<i<<",";
	cout<<endl;
	return 0;
}
int main()
{
	int n;
	cout<<"Enter number upto which Prime Numbers is to be calculated"<<endl;
	cin>>n;
	sieve(n);
	return 0;
}
