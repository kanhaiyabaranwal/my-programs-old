/*
https://www.youtube.com/watch?v=TWHytKnOPaQ
http://www.geeksforgeeks.org/dynamic-programming-set-15-longest-bitonic-subsequence/
*/

#include<iostream>
#include<algorithm>
using namespace std;

int LongestBitonicSubsequence(int* A, int n)
{
	if(n <= 2) return n; //Base case, why?

	// max increase subsequence left to right
	int* lToR = new int[n]; std::fill(lToR,lToR+n, 1);
	// max increase subsequence right to left
	int* rToL = new int[n]; std::fill(rToL,rToL+n, 1);

	//populate left to right array
	for(int i=1; i<n; i++)
	{
		for(int j=0; j<i; j++)
		{
			if(A[j] > A[i] && lToR[j] >= lToR[i])
				lToR[i] = lToR[j]+1;
		}
	}

	//populate right to left array
	for(int i=n-1; i>=0; i--)
	{
		for(int j=n-1; j>i; j--)
		{
			if(A[j] > A[i] && lToR[j] >= lToR[i])
				lToR[i] = lToR[j]+1;
		}
	}

	//find result: which max of sum of lToR and rToL
	int result = lToR[0] + rToL[0] -1; // -1 because index is calulated twice
	for(int i=1; i<n; i++)
	{
		result = max(result, (lToR[i] + rToL[i] -1));
	}

	delete[] lToR; delete[] rToL;
	return result;
}

int main_48_T_7_LongestBitonicSubsequence()
{
	int arr[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5,
		13, 3, 11, 7, 15};
	int n = sizeof(arr)/sizeof(arr[0]);
	int res = LongestBitonicSubsequence( arr, n );
	printf("Length of LongestBitonicSubsequence is %d\n",  res);
	return 0;
}