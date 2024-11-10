#include<iostream>

using namespace std;
#define N 40

void sieve(int *p)
{
	p[0]=p[1]=0;
	for(int i=2;i<N;i++)
	{
		int j=2;
		if(p[i])
		{
			
			while(j*i<N)
			{
				p[j*i]=0;
				j++;
			}
				
		}
		
	}
	cout<<"Prime numbers are: ";
	for(int i=2;i<N;i++)
	{
		if(p[i])
			cout<<i<<",";
		
	}
	cout<<endl;
}

void special_prime_numbers()
{
	int p[N]={1};
	for(int i=0;i<N;i++)
		p[i]=1;
	sieve(p);
	
	int i=5;
	cout<<"special prime numbers are "<<endl;
	while(i<N)
	{
		while(i<N && p[i]==0)
			i++;
		int first=i;
		i++;
		while(i<N && p[i]==0)
			i++;
		int second=i;
		if(first+second+1>N)
			return;
		if(p[first+second+1]==1)
			cout<<"first:"<<first<<","<<second<<","<<first+second+1<<endl;
			
	}
	
	
}

int main()
{
	special_prime_numbers();
	return 0;
	
}
