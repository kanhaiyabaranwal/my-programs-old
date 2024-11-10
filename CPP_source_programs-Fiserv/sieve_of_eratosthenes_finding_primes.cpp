//Sieve_of_eratosthenes method for finding primes
#include<iostream>
using namespace std;

void find_prime(int n)
{
	int arr[n];
	for(int i=0;i<n;i++)
		arr[i]=1;
	for(int i=2;i<=n;i++)
	{
		int j=1;
		int p=j*i;
		if(arr[p])
			cout<<i<<",";
		else
			continue;
		while(p<n)
		{
			arr[p]=0;
			j++;
			p=i*j;
		}
	}
	cout<<endl;
	return;
}

int main()
{
	find_prime(20);
	return 0;
}
