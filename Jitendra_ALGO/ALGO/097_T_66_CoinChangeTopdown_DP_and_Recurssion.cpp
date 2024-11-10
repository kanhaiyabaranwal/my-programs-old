/*
https://www.youtube.com/watch?v=Kf_M7RdHr1M
https://www.geeksforgeeks.org/dynamic-programming-set-7-coin-change/

Dynamic Programming | Set 7 (Coin Change)
3.7
Given a value N, if we want to make change for N cents, and we have infinite supply of each of S = { S1, S2, .. , Sm} valued coins,
how many ways can we make the change? The order of coins doesn’t matter.

For example, for N = 4 and S = {1,2,3}, there are four solutions: {1,1,1,1},{1,1,2},{2,2},{1,3}.
So output should be 4. For N = 10 and S = {2, 5, 3, 6}, there are five solutions: {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}.
So the output should be 5.
*/
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

namespace NS_97
{
	const int NoSoln = INT_MAX;
	std::map<int, int> resultCache;
	int minCoinTopDown(int* arr, int n, int sum)
	{
		if (sum == 0) return 0;

		int res = NoSoln;
		for (int i = 0; i < n; i++)
		{
			if (sum >= arr[i])
			{
				int leftOver = sum - arr[i];
				int sub_res = NoSoln;
				if (resultCache.find(leftOver) == resultCache.end())
					sub_res = minCoinTopDown(arr, n, sum - arr[i]);
				else
					sub_res = resultCache[leftOver];
				if (sub_res != NoSoln)
					res = std::min(sub_res + 1, res);
			}
		}
		resultCache[sum] = sum;
		return res;
	}

	void test() //TODO-- test again
	{
		int arr[] = { 1, 2, 3 };
		int n = sizeof(arr) / sizeof(arr[0]);
		int sum = 5; resultCache.clear();
		int min_coins = minCoinTopDown(arr, n, sum);
		cout << min_coins << endl;
	}
}
int main_97()
{
	NS_97::test();
	return 0;
}
