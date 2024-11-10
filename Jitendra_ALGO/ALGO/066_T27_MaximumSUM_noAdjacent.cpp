/*
https://www.youtube.com/watch?v=UtGtF6nc35g
http://www.geeksforgeeks.org/maximum-sum-such-that-no-two-elements-are-adjacent/

Maximum Sum Subsequence Non-Adjacent
Maximum sum such that no two elements are adjacent
-------------------------------------------------
Given an array of positive numbers, find the maximum sum of a subsequence with the
constraint that no 2 numbers in the sequence should be adjacent in the array. 

Exapmple 1:-
So 3 2 7 10 should return 13 (sum of 3 and 10)  
Example 2:-
3 2 5 10 7 should return 15 (sum of 3, 5 and 7)
*/

#include<iostream>
#include<algorithm>
using namespace std;
namespace NS66
{
	int findMaxSum(int* arr, int n)
	{
		if(n<=0) return -1;
		int prev1 = 0;
		int prev2 = 0;
		int res = INT_MIN;

		for(int i=0; i<n; i++)
		{
			res = max(prev1, prev2+arr[i]);
			prev2 = prev1; prev1 = res;
		}
		return res;
	}
}
int main_66()
{
	int arr[] = {5, 5, 10, 100, 10, 5};
	int n = sizeof(arr) / sizeof(arr[0]);
	int res = NS66::findMaxSum(arr, n);
	return 0;
}