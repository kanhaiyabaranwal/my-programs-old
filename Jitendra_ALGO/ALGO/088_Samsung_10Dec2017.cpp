/*
Problem statements : -
Given a set of positive numbers, we have to split into two sets with below conditions
1) Sum of all numbers in the new two sets are same.
2) Few/All numbers can left in master sets
3) We have to splits numbers such that Sum is maximum
*/

#include<iostream>
#include<algorithm>
using namespace std;

#define DEBUG_NS88 true

namespace NS88
{
	struct DPNode
	{
		bool include;
		bool exclude;
	};

	bool isPathOverlapping(DPNode** dp, int dpRowSize, int dpColSize, int* arr, int row1,  int row2, int sum)
	{
		bool* path = new bool[dpRowSize];
		for (int i = 0; i < dpRowSize; i++)
			path[i] = false;
		int sum1 = sum;
		int sum2 = sum;
		while (sum1 > 0 && row1 > 0) //back tracking for path1
		{
			if (dp[row1][sum1].include)
			{
				path[row1] = true;
				sum1 = sum1 - arr[row1 - 1];
			}
			row1--;
		}
		while (sum2 > 0 && row2 > 0) //back tracking for path2
		{
			if (dp[row2][sum2].include && !path[row2])
			{
				sum2 = sum2 - arr[row2 - 1];
			}
			row2--;
		}
		bool res = false;
		if (sum2 > 0)
			res = true;
		delete[] path;
		return res;
	}

	int getMaxSum_AfterSplit(int* arr, int n)
	{
		//sort the array
		std::sort(arr, arr + n);

		int totalSum = 0;
		for (int i = 0; i < n; i++)
			totalSum += arr[i];

		int sum = totalSum / 2;
		if (sum == 0) return 0;

		//create DP
		DPNode** dp = new DPNode*[n + 1]; // rows for each number
		for (int i = 0; i <= n; i++)
			dp[i] = new DPNode[sum + 1]; // column for each sum
		//now populate the dp
		for (int i = 0; i <= n; i++) // i = each coins
		{
			for (int j = 0; j <= sum; j++) // j = sum
			{
				DPNode& node = dp[i][j];
				if (j == 0) // sum ==0 so everything possiable
				{
					node.include = node.exclude = true;
					continue;
				}
				if (i == 0) // if no coins then nothing possiabe apart from when sum == 0
				{
					node.include = node.exclude = false;
					continue;
				}
				if (j < arr[i - 1]) // if sum is less than current number then include not possiable
				{
					node.include = false;
					node.exclude = dp[i - 1][j].include || dp[i - 1][j].exclude;
					continue;
				}
				//for rest of cases
				node.exclude = dp[i - 1][j].include || dp[i - 1][j].exclude;
				int j_remain = j - arr[i - 1];
				node.include = dp[i - 1][j_remain].include || dp[i - 1][j_remain].exclude;
			}
		}
#if DEBUG_NS88
		cout << "   ";
		for (int j = 0; j <= sum; j++)
		{
			cout << "( " << j << " ) ";
			if (j < 10)
				cout << " ";
		}
		cout << endl;
		for (int i = 0; i <= n; i++)  //print DP for debug
		{
			for (int j = 0; j <= sum; j++)
			{
				if (j == 0)
				{
					if (i != 0)
					{
						cout << arr[i - 1];
						if (arr[i - 1] < 10)
							cout << " ";
					}
					else
					{
						cout << "  ";
					}
					cout << " ";
				}
				cout << "(" << dp[i][j].include << "," << dp[i][j].exclude << ")  ";
			}
			cout << endl;
		}
#endif
		int res = 0;
		int dpRowSize = n + 1;
		int dpColSize = sum + 1;
		bool notFound = true;
		while (sum > 0 && notFound)
		{
			for (int i = 1; i < dpRowSize; i++)
			{
				const DPNode& node = dp[i][sum];
				if (node.exclude && node.exclude)
				{					
					if (isPathOverlapping(dp, dpRowSize, dpColSize, arr, i, i - 1, sum) == false)
					{
						res = sum;
						notFound = false;
						break;
					}
				}
			}
			sum--;
		}
		//clean-up
		for (int i = 0; i <= n; i++)
			delete[] dp[i];
		delete[] dp;

		return res;
	}
}

int main_88()
{
	//int arr[] = { 1,2,3,6 };
	//int arr[] = { 1, 3, 3, 4, 6, 6 };
	//int arr[] = { 2, 3, 4, 5, 6, 7, 7 };
	//int arr[] = { 4, 4, 10, 18, 22 };
	int arr[] = { 2, 3, 4, 5, 7 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int max = NS88::getMaxSum_AfterSplit(arr, n);
	cout << "Max sum = " << max << endl;
	return 0;
}