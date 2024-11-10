/*
Median of two sorted arrays of same size
Binary Search : Median of two sorted arrays of different sizes.
Median of two sorted arrays of different sizes

https://www.youtube.com/watch?v=LPFhl65R7ww
http://www.geeksforgeeks.org/median-of-two-sorted-arrays/
http://www.geeksforgeeks.org/median-of-two-sorted-arrays-of-different-sizes/
*/
#include<iostream>
#include<algorithm>
using namespace std;

namespace NS_61
{
	const int P_INF = 50000; // positive infinite
	const int N_INF = -5000; // negative infinite
	int _getMedianUtil(int* arr, int size)
	{
		if(size % 2 == 0)
			return (arr[size/2] + arr[size/2 -1])/2;
		return arr[size/2];
	}
	int findMedianSameSize(int* arr1, int* arr2, int size)
	{
		//base cases --
		if(size <= 0) return -1;
		if(size == 1) return (arr1[0] + arr2[0])/2;
		if(size == 2)
			return (max(arr1[0],arr2[0]) + min(arr1[1],arr2[1]))/2;

		int m1 = _getMedianUtil(arr1, size);
		int m2 = _getMedianUtil(arr2, size);

		if(m1 == m2) return m1;

		if( m1 > m2 )
		{
			return findMedianSameSize(arr1, arr2+(size-1)/2, size-(size-1)/2);
		}
		else
		{
			return findMedianSameSize(arr1+(size-1)/2, arr2, size-(size-1)/2);
		}
		return -1; // dead code
	}



	//TODO- We are asuming size1 <= size2, but it doesnot matter
	// TEST again -- this is not working
	float findMedian(int* arr1, int size1, int* arr2, int size2)
	{
		if( size1 <= 0 || size2 <= 0) return -1;
		int n1 = size1 -1;
		int n2 = size2 -1;
		bool isOdd = (size1+size2)%2 == 1 ? true : false;

		int s1 = 0; int e1 = n1;
		int s2 = 0; int e2 = n2;
		while(true)
		{
			int i1 = s1 >=0 ? (s1+e1)/2 : -1;
			i1 = (e1 < n1) ? (s1+e1)/2 : size1;

			//toDO
			int i1_size = i1+1;
			if(i1 < 0) i1_size = 0;
			if(i1 > n1) i1_size = size1;

			int lv1 =  (s1 <= e1 && i1 >= s1 && i1 <=e1) ? arr1[i1] : N_INF;
			int rv1 =  (s1 <= e1 && i1+1 >= s1 && i1+1 <=e1) ? arr1[i1+1] : P_INF;


			int i2 = (size1 + size2 + 1)/2 - i1_size -1; 

			int lv2 =  (s2 <= e2 && i2 >= s2 && i2 <=e2) ? arr2[i2] : N_INF;
			int rv2 =  (s2 <= e2 && i2+1 >= s2 && i2+1 <=e2) ? arr2[i2+1] : P_INF;

			if( lv1 <= rv2 && lv2 <= rv1 )
			{
				if(isOdd)
					return (float)max(lv1,lv2);
				else
					return (float)(max(lv1, lv2) + min(rv1, rv2))/2;
			}
			else if(lv1 > rv2)
				e1 = i1-1;
			else
				s1 = i1;
		}
		return -1; // dead code
	}
}

int main_61()
{
	int A[] = {900};
	int B[] = {5, 8, 10, 20};
	//int A[] = {1, 2};
	//int B[] = {2, 3, 7, 9, 11, 12, 14, 15, 17, 19, 20};
	int N = sizeof(A) / sizeof(A[0]);
	int M = sizeof(B) / sizeof(B[0]);
	float res = NS_61::findMedian( A, N, B, M );
	cout << "Median(different size) = " << res << endl;

	int arr1[] = {1, 2, 3, 6};
	int arr2[] = {4, 6, 8, 10}; //should be same size as above
	int n = sizeof(arr1)/sizeof(arr1[0]);
	int res_sameSize = NS_61::findMedianSameSize(arr1, arr2, n );
	cout << "Median(same size) = " << res_sameSize;

	return 0;
}