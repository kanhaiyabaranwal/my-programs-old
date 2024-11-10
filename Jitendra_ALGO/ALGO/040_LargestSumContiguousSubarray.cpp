/*
http://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
*/
#include <iostream>
#include<limits.h>

using namespace std;

int LargestSumContiguousSubarray(int* A, int n)
{
	int globalSumMax = INT_MIN;
	int globalstartIndex=0;
	int globalEndIndex =0;

	int localStartIndex = 0;
	int localSumEndingHere = 0;

	for(int i=0; i<n; i++)
	{
		localSumEndingHere += A[i];
		if(localSumEndingHere > globalSumMax)
		{
			globalSumMax = localSumEndingHere;
			globalstartIndex = localStartIndex;
			globalEndIndex = i;
		}
		if(localSumEndingHere < 0)
		{
			localSumEndingHere = 0;
			localStartIndex = i+1;
		}
	}
	return globalSumMax;
}


int main__() {

	int A[] = {-1, -2, -3, -4};
	int n = sizeof(A) / sizeof(A[0]);
	int globalSumMax = LargestSumContiguousSubarray(A,n);
	cout << globalSumMax << endl;

	return 0;
}


