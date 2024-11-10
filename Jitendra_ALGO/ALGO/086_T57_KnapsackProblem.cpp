/*
https://www.youtube.com/watch?v=8LusJS5-AGo
http://www.geeksforgeeks.org/knapsack-problem/

0/1 Knapsack Problem Dynamic Programming
Dynamic Programming | Set 10 ( 0-1 Knapsack Problem)
------------------------------------------------------
Given weights and values of n items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
In other words, given two integer arrays val[0..n-1] and wt[0..n-1] which represent values and weights associated with n items respectively.
Also given an integer W which represents knapsack capacity,
find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W.
You cannot break an item, either pick the complete item, or don’t pick it (0-1 property).
*/
#include<iostream>
#include<algorithm>
using namespace std;

namespace NS86
{
	int knapSack(int maxWeight, int* weights, int* values, int n)
	{
		int** dp = new int*[n];
		for (int i = 0; i < n; i++)
			dp[i] = new int[maxWeight + 1];

		for (int i = 0; i < n; i++)
		{
			dp[i][0] = 0; //i.e. if weight is zero
			for (int w = 1; w <= maxWeight; w++)
			{
				int excluding = (i == 0) ? 0 : dp[i - 1][w];
				if (w >= weights[i])
				{
					int remaining = (i == 0) ? 0 : dp[i - 1][w - weights[i]];
					int includeing = values[i] + remaining;
					dp[i][w] = std::max(includeing, excluding);
				}
				else
				{
					dp[i][w] = excluding;
				}
			}
		}
		int res = dp[n - 1][maxWeight];
		for (int i = 0; i < n; i++)
			delete dp[i];
		delete[] dp;
		return res;
	}
	void test()
	{
		int values[] = { 60, 100, 120 };
		int weights[] = { 10, 20, 30 };
		int  maxWeight = 50;
		int n = sizeof(values) / sizeof(values[0]);
		int maxVal = knapSack(maxWeight, weights, values, n);
		cout << "Max value = " << maxVal << endl;
	}
}

int main_86()
{
	NS86::test();
	return 0;
}
