/*
http://www.geeksforgeeks.org/special-prime-numbers/
Special prime numbers
----------------------
Given two numbers n and k, find whether there exist at least 
k special prime numbers or not from 2 to n inclusively.

A prime number is said to be Special prime number if 
it can be expressed as the sum of three integer numbers: 
two neighboring prime numbers and 1. 

For example, 19 = 7 + 11 + 1, or 13 = 5 + 7 + 1.
*/
#include<iostream>
using namespace std;
namespace NS72
{
	int specialPrimeNumbers(int n)
	{
		bool* primes = new bool[n+1];
		for(int i=0; i<=n; i++)
			primes[i] = true;
		primes[0] = false;
		primes[1] = false;

		for(int i=2; i<=n; i++)
		{
			if(primes[i])
			{
				for(int k=2; k*i <= n; k++)
					primes[k*i] = false;
			}
		}
		int count =0;
		int currPrime = 2;
		while(true)
		{
			int nextPrime = currPrime +1;
			while(!primes[nextPrime] && nextPrime <= n)
				nextPrime++;

			if(!primes[nextPrime])
				break; // no more soln possiable

			int sum = currPrime + nextPrime + 1;
			if(sum > n)
				break; // no more solution possiable

			if(primes[sum])
				count++;
			currPrime = nextPrime;
		}
		return count;
	}
}

int main_72()
{
	int n = 45, k = 2;
	int res = NS72::specialPrimeNumbers(n);
	if ( res >= k)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}
