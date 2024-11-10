/*
Maximum Sum Increasing Subsequence 
Dynamic Programming | Set 14 (Maximum Sum Increasing Subsequence)
Printing Maximum Sum Increasing Subsequence

https://www.youtube.com/watch?v=99ssGWhLPUE

http://www.geeksforgeeks.org/dynamic-programming-set-14-maximum-sum-increasing-subsequence/

http://www.geeksforgeeks.org/printing-maximum-sum-increasing-subsequence/
*/


#include<iostream>
using namespace std;

namespace NS_58
{
	void printMaxSumIncreasingSubsequence(int* arr, int n)
	{
		int* maxSumArr = new int[n];
		int* parentArr = new int[n];

		int lastIndex = 0;
		for(int i=0; i<n; i++)
		{
			maxSumArr[i] = arr[i]; // max sum is element itself
			parentArr[i] = -1; // and its parent is null
			for(int j=0; j<i; j++)
			{
				if(arr[j] < arr[i] && maxSumArr[i] < maxSumArr[j] + arr[i])
				{
					maxSumArr[i] =  maxSumArr[j] + arr[i];
					parentArr[i] = j;
				}
			}
			if( maxSumArr[i] > maxSumArr[lastIndex])
				lastIndex = i;
		}
		//print results
		cout << "Max Sum Increasing Subsequence = " << maxSumArr[lastIndex] << endl;
		cout << "Increasing Subsequence(reverse order) = ";
		while(lastIndex != -1)
		{
			cout << arr[lastIndex] << "  ";
			lastIndex = parentArr[lastIndex];
		}
		cout << endl;
	}
}
//TODO other methods
int main_59_T_22_MaximumSumIncreasingSubsequence()
{
	int arr[] = { 3, 2, 6, 4, 5, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);
	NS_58::printMaxSumIncreasingSubsequence(arr, n);
	return 0;
}