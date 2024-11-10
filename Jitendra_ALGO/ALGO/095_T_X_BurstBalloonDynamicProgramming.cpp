/*
https://www.youtube.com/watch?v=IFNibRVgFBo
https://leetcode.com/problems/burst-balloons/description/
https://careercup.com/question?id=5719829237465088

Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums.
You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins.
Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.
Find the maximum coins you can collect by bursting the balloons wisely.
Note:
(1) You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
(2) 0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100
Example:
Given [3, 1, 5, 8]
Return 167
nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167
*/

#include <iostream>
#include <vector>
using namespace std;

namespace NS95
{
	struct Node
	{
		int sum;
		int index;
		Node(int _sum = 0, int _index = -1) :sum(_sum), index(_index) {}
	};

	void populate_path(Node** dp, vector<int>& path, int start, int end)
	{
		if (start > end) return;
		int index = dp[start][end].index;
		populate_path(dp, path, start, index - 1);
		populate_path(dp, path, index + 1, end);
		path.push_back(index);
	}


	int brustBallon(int* arr, int n)
	{
		Node** dp = new Node*[n];
		for (int i = 0; i < n; i++)
			dp[i] = new Node[n];

		for (int lenght = 1; lenght <= n; lenght++)
		{
			for (int i = 0; i + lenght <= n; i++)
			{
				int j = i + lenght - 1;

				int left = i > 0 ? arr[i - 1] : 1;
				int right = j < n - 1 ? arr[j + 1] : 1;

				int maxSum = INT_MIN;
				int lastIndex = -1;
				for (int k = i; k <= j; k++)
				{
					int leftSum = k > i ? dp[i][k - 1].sum : 0;
					int rightSum = k < j ? dp[k + 1][j].sum : 0;
					int sum = leftSum + (left * arr[k] * right) + rightSum;
					if (sum > maxSum)
					{
						maxSum = sum;
						lastIndex = k;
					}
				}
				dp[i][j].sum = maxSum;
				dp[i][j].index = lastIndex;
			}
		}
		//backup of result
		int res = dp[0][n - 1].sum;
		//print the sequence
		vector<int> path;
		populate_path(dp, path, 0, n - 1);
		cout << "Sequence of blasting = ";
		for each (int index in path)
		{
			cout << arr[index] << "  ";
		}
		cout << endl;
		//cleanup
		for (int i = 0; i < n; i++)
			delete[] dp[i];
		delete[] dp;
		//return the result
		return res;
	}
	void test()
	{
		int arr[] = { 3, 1, 5, 8 };
		int n = sizeof(arr) / sizeof(arr[0]);
		int res = brustBallon(arr, n);
		cout << "Maximum coins you can collect = " << res << endl;
	}
}
int main_95()
{
	NS95::test();
	return 0;
}
