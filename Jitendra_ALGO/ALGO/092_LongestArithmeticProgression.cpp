/*
https://www.geeksforgeeks.org/length-of-the-longest-arithmatic-progression-in-a-sorted-array/
Dynamic Programming | Set 35 (Longest Arithmetic Progression)
Given a set of numbers, find the Length of the Longest Arithmetic Progression (LLAP) in it.
Example:-
set[] = {1, 7, 10, 15, 27, 29}
output = 3
The longest arithmetic progression is {1, 15, 29}

set[] = {5, 10, 15, 20, 25, 30}
output = 6
The whole set is in AP
*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

namespace NS_092
{
	int lenghtOfLongestAP_BruteForce(int* arr, int n)
	{
		if (n <= 2) return n;
		int res = 2;
		for (int first = 0; first < n; first++)
		{
			for (int second = first + 1; second < n; second++)
			{
				int diff = arr[second] - arr[first];
				int count = 2;
				int next = arr[second] + diff;
				for (int third = second + 1; third < n; third++)
				{
					if (arr[third] == next)
					{
						count++; next = arr[third] + diff;
					}
				}
				res = std::max(res, count);
			}
		}
		return res;
	}

	int lenghtOfLongestAP(int* arr, int n)
	{
		if (n <= 2) return n;
		//sort the arry
		//std::sort(arr, arr + n);
		int res = 2;
		int** dp = new int*[n];
		for (int i = 0; i < n; i++)
			dp[i] = new int[n];
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
				dp[i][j] = 2;
		}

		for (int second = n - 2; second >= 1; second--)
		{
			int first = second - 1;
			int third = second + 1;
			while (first >= 0 && third <= n - 1)
			{
				int sum = arr[first] + arr[third];
				int dbl = arr[second] * 2;
				if (sum == dbl)
				{
					dp[first][second] = dp[second][third] + 1;
					res = std::max(res, dp[first][second]);
					first--; third++;
					continue;
				}
				if (sum > dbl)
				{
					first--; continue;
				}
				if (sum < dbl)
				{
					third++; continue;
				}
			}
		}

		for (int i = 0; i < n; i++)
			delete[] dp[i];
		delete[] dp;
		return res;
	}

	void test()
	{

		int set1[] = { 1, 7, 10, 13, 14, 19 };
		int n1 = sizeof(set1) / sizeof(set1[0]);
		cout << "Dymanic Programming = " << lenghtOfLongestAP(set1, n1) << "\t";
		cout << "Brute Froce = " << lenghtOfLongestAP_BruteForce(set1, n1) << endl;

		int set2[] = { 1, 7, 10, 15, 27, 29 };
		int n2 = sizeof(set2) / sizeof(set2[0]);
		cout << "Dymanic Programming = " << lenghtOfLongestAP(set2, n2) << "\t";
		cout << "Brute Froce = " << lenghtOfLongestAP_BruteForce(set2, n2) << endl;

		int set3[] = { 2, 4, 6, 8, 10 };
		int n3 = sizeof(set3) / sizeof(set3[0]);
		cout << "Dymanic Programming = " << lenghtOfLongestAP(set3, n3) << "\t";
		cout << "Brute Froce = " << lenghtOfLongestAP_BruteForce(set3, n3) << endl;
	}

	int kthsmallest(const vector<int> &A, int B) {
		priority_queue<int, vector<int>, std::less<int> > pq;
		int n = A.size();
		for (int i = 0; i<n; i++)
		{
			pq.push(A[i]);
			while (pq.size() > B)
				pq.pop();
		}
		return pq.top();
	}

	void test2()
	{
		vector<int> v = {8, 16, 80, 55, 32, 8, 38, 40, 65, 18, 15, 45, 50, 38, 54, 52, 23, 74, 81, 42, 28, 16, 66, 35, 91, 36, 44, 9, 85, 58, 59, 49, 75, 20, 87, 60, 17, 11, 39, 62, 20, 17, 46, 26, 81, 92};
		std::sort(v.begin(), v.end());
		for each (int x in v)
		{
			cout << x << "   ";
		}
		cout << endl;
		int res = kthsmallest(v, 9);
	}
}
int main_092()
{
	NS_092::test2();
	return 0;
}