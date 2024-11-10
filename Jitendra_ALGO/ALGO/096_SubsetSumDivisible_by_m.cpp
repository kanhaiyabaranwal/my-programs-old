/*
https://www.geeksforgeeks.org/subset-sum-divisible-m/
Given a set of non-negative distinct integers, and a value m, determine if there is a subset of the given set with sum divisible by m.
Input Constraints
Size of set i.e., n <= 1000000, m <= 1000

Examples:

Input : arr[] = {3, 1, 7, 5};
m = 6;
Output : YES

Input : arr[] = {1, 6};
m = 5;
Output : NO
*/
#include<iostream>
#include <algorithm>
using namespace std;

namespace NS_96
{
	bool subsetSumDivisiableBy_DP_wrong(int* arr, int size, int m) // this function wont work, need to comment why
	{
		std::sort(arr, arr + size);
		bool** dp = new bool*[m];
		for (int i = 0; i < m; i++)
			dp[i] = new bool[size + 1];
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j <= size; j++)
			{
				if (j == 0)
				{
					dp[i][j] = false;
					continue;
				}
				if (i == 0)
				{
					dp[i][j] = true;
					continue;
				}
				int divider = i + 1;
				int reminder = arr[j - 1] % divider;
				int x = divider - reminder - 1;
				dp[i][j] = (reminder == 0) || dp[i][j - 1] || dp[x][j - 1];
			}
		}
		bool res = dp[m - 1][size];
		for (int i = 0; i < size; i++)
			delete[] dp[i];
		delete[] dp;
		return res;
	}

	bool subsetSumDivisiableBy_DP(int* arr, int size, int m)
	{
		if (size > m) return true; //--> to do how? https://www.geeksforgeeks.org/discrete-mathematics-the-pigeonhole-principle/

		bool* dp = new bool[m]; bool* temp = new bool[m];
		for (int i = 0; i < m; i++)
			dp[i] = false;

		for (int i = 0; i < size && dp[0] != true; i++)
		{
			int reminder = arr[i] % m;

			for (int j = 0; j < m; j++)
				temp[j] = false;			

			for (int j = 0; j < m; j++)
			{
				if (dp[j] == true)
				{
					temp[(j + reminder) % m] = true;
				}
			}

			for (int j = 0; j < m; j++)
				dp[j] = dp[j] || temp[j];

			dp[reminder] = true;
		}

		bool result = dp[0]; // at any point if we find a number whose reminder is zero
		delete[] dp; delete[] temp;
		return result;
	}

	void test()
	{
		int arr[] = { 1, 1, 2, 1 };
		int size = sizeof(arr) / sizeof(arr[0]);
		int m = 5;
		bool res = subsetSumDivisiableBy_DP(arr, size, m);
		if (res)
			cout << "Yes\n";
		else
			cout << "No\n";
	}
}
int main_96()
{
	NS_96::test();
	return 0;
}