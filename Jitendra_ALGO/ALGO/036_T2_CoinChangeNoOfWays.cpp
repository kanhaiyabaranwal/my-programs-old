/*
http://www.geeksforgeeks.org/dynamic-programming-set-7-coin-change/
https://www.youtube.com/watch?v=_fgjrs570YE
*/
#include<iostream>
using namespace std;

/*
Recurssion method
*/
int numberOffWaysCoinChangeRecursion(int* coins, int coin_size, int sum)
{
	// base cases
	if(sum < 0) return 0; // if total value is less than zeor then no solution
	if(sum == 0) return 1; // if total =0, then there is only one solution that is dont pick any coin

	if( coin_size < 0)
		return 0; // if tehre is no coins then there is no solution as sum is greater than zero

	//retun total number of ways including coins and excluding coins
	int total_excluding_last_coin = numberOffWaysCoinChangeRecursion( coins, coin_size-1, sum);
	int total_including_last_coin = numberOffWaysCoinChangeRecursion( coins, coin_size, sum - coins[coin_size-1]);

	return total_excluding_last_coin + total_including_last_coin;
}

/*
Dynamic Programming
*/
int numberOffWaysCoinChangeDP(int* coins, int coin_size, int sum)
{
	if(sum == 0) return 1;
	if(coin_size < 0) return 0;

	int** table =  new int*[coin_size+1];
	for(int i=0; i<= coin_size; i++)
	{
		table[i] = new int[sum+1];
		memset(table[i],0, sizeof(int) * (sum+1));
		table[i][0] = 1;
	}

	for(int i=1; i<= coin_size; i++)
	{
		for(int j=1; j<= sum; j++)
		{
			if( j < coins[i-1]) // coin is bigger than sum so we have to exclusde it
				table[i][j] = table[i-1][j]; // copy from previous row
			else // coin is smaller so there is possible to include it
				table[i][j] = table[i-1][j] + table[i][j-coins[i-1]];
		}
	}

	int result = table[coin_size][sum];
	for(int i=0; i<= coin_size; i++) delete[] table[i];
	delete[] table;
	return result;
}

/*
Dynamic Programming with space improvents
*/
int numberOffWaysCoinChangeDP2(int* coins, int coin_size, int sum)
{
	if(sum == 0) return 1;
	if(coin_size < 0) return 0;

	int* table = new int[sum+1];
	memset(table, 0, sizeof(int) * (sum+1));
	table[0] = 1;

	for(int i=1; i <= coin_size; i++)
	{
		for(int j=coins[i-1]; j<= sum; j++)
			table[j] += table[j-coins[i-1]];
	}
	int result = table[sum];
	delete[] table;
	return result;
}


int main_36_T_2_CoinChangeNoOfWays()
{
	//int sum = 4;
	//int coins[] = {1, 2, 3};
	int sum = 10;
	int coins[] = {2, 5, 3, 6};
	int coin_size = sizeof(coins)/sizeof(coins[0]);	
	//call recurssive method
	int total_no_ways_recursion = numberOffWaysCoinChangeRecursion(coins, coin_size, sum);
	//call dynamic programming with space complexcity O(N^2)
	int total_no_ways_dp = numberOffWaysCoinChangeDP(coins, coin_size, sum);
	//call dynamic programming with space complexcity O(N) 
	int total_no_ways_dp2 = numberOffWaysCoinChangeDP2(coins, coin_size, sum);

	return 0;
}