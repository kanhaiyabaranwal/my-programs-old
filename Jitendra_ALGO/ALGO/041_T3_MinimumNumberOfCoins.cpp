/*
https://www.youtube.com/watch?v=Y0ZqKpToTic
http://www.geeksforgeeks.org/find-minimum-number-of-coins-that-make-a-change/
*/
#include<iostream>
#include<limits>
using namespace std;


const int INF = INT_MAX;
inline int _sum(int x, int y)
{
	if(x == INF || y == INF) return INF;
	return x + y;
}

inline int _min(int x, int y)
{
	return x < y ? x : y;
}

/*
TODO - recurssion method
*/






/*
DP solotion
*/
int minCoinsDP(int* conins, int n, int value)
{
	int** table =  new int*[n+1];
	for(int i=0; i<= n; i++)
	{
		table[i] = new int[value+1];
		table[i][0] = 0;
		if(i==0)// first row initilize to infinite
		{ for(int j=1; j<=value; j++) {table[i][j] = INF;} }
	}
	for(int i=1; i<= n; i++)
	{
		for(int j=1; j<=value; j++)
		{
			if( j >= conins[i-1])
			{
				int currentCoinIncluded = _sum(1 , table[i-1][j-conins[i-1]]);
				int currentCoinExcluded = table[i-1][j];
				table[i][j] = _min(currentCoinIncluded, currentCoinExcluded);
			}
			else
			{
				table[i][j] = table[i-1][j];
			}
		}
	}
	int result = table[n][value];
	for(int i=0; i<= n; i++) delete[] table[i];
	delete[] table;
	return result;
}

/*
TODO - DP solition with space optimization 
*/

void printResult(int res)
{
	if(res == INF)
		cout << "Not possiable" << endl;
	else
		cout << res << endl;
}
int main_41_T_3_MinimumNumberOfCoins()
{
	int coins[] =  {1, 5, 6, 8};
	int n = sizeof(coins)/sizeof(coins[0]);
	int V = 11;
	int min_dp = minCoinsDP(coins, n, V);
	cout << "DP solotion : Minimum coins required is :  "; printResult(min_dp);
	return 0;
}