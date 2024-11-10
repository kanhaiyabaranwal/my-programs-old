/*
http://www.geeksforgeeks.org/longest-increasing-subsequence/
http://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/	
https://www.youtube.com/watch?v=CE2b_-XfVDk
https://www.youtube.com/watch?v=1RpMc3fv0y4
*/
#include<iostream>
using namespace std;

int longestIncreaseSubSequence_orderOf_nSquare(int* A,int n)
{
	if(n<1) return 0; // empty array
	int* tempArray = new int[n];
	int max = 1;
	for(int i=0; i<n; i++)
	{
		//Initilize to one which is min length which is the element itself
		tempArray[i] = 1;
		// now check with back elements
		for(int j=0; j<i; j++)
		{
			// if element is bigger than previous value and 
			// length we found is smaller or equal
			if(A[i] > A[j] && tempArray[i] <= tempArray[j])
			{
				tempArray[i] = tempArray[j] +1;
			}
		}
		max = (max < tempArray[i]) ? tempArray[i] : max;
	}

	delete[] tempArray;
	return max;
}

#define value(i) arr[index_arr[i]] 

//TODO - do on paper again
int findCellingIndexBinary(int* arr, int* index_arr, int low, int high, int x)
{
	if(low > high) return -1;
	if(value(low) >= x) // first element itself is greter so return first element
		return low;
	if(value(high) < x) // last element is smaller so no result possiable
		return -1;  

	int half_offset = (high - low) / 2;
	if(half_offset == 0) // if only one or two elements present
		return high; //return high, becouse in we checked value is between low and high

	int mid = low + half_offset;	

	if(value(mid) == x)
	{
		return mid;
	}
	else if(value(mid) > x) // need to search left side of tree
	{
		// include mid here, as it may be be result
		return findCellingIndexBinary(arr, index_arr, low, mid, x);
	}
	else  // need to search right side of tree exclude mid here
	{
		//include mid here also as it may be result
		return findCellingIndexBinary(arr, index_arr, mid, high, x);
	}
}

int findCellingIndexBinaryIttretative(int* arr, int* index_arr, int low, int high, int x)
{
	if (low > high) return -1;
	if (value(low) >= x) // first element itself is greter so return first element
		return low;
	if (value(high) < x) // last element is smaller so no result possiable
		return -1;
	while (high-low >1)
	{
		int m = low + (high - low) / 2;
		if (value(m) >= x)
			high = m;
		else
			low = m;
	}
	return high;
}

//TODO - do in paper again
int longestIncreaseSubSequence_orderOf_nlogn(int* A,int n)
{
	if(n<1) return 0; // empty array
	int* tmpIndexArray = new int[n];
	int* parentIndexArray = new int[n];
	int lastIndex = 0; 
	tmpIndexArray[0] = 0;
	parentIndexArray[0] = -1;
	for(int i=1; i<n; i++)
	{
		if( A[i] > A[tmpIndexArray[lastIndex]])
		{
			parentIndexArray[i] = tmpIndexArray[lastIndex];
			tmpIndexArray[++lastIndex] = i;
		}
		else
		{
			int cell_index = findCellingIndexBinary(A,tmpIndexArray, 0, lastIndex, A[i]);
			cell_index = findCellingIndexBinaryIttretative(A, tmpIndexArray, 0, lastIndex, A[i]);
			if( cell_index != -1)
			{
				tmpIndexArray[cell_index] = i;
				parentIndexArray[i] = tmpIndexArray[cell_index-1];
			}
		}
	}

	int index = tmpIndexArray[lastIndex];
	cout << "Result in reverse order : ";
	while(index != -1)
	{
		cout << A[index] << "  ";
		index = parentIndexArray[index];
	}
	cout << endl;
	delete[] tmpIndexArray; delete[] parentIndexArray;

	return lastIndex+1;
}

int main_35()
{
	int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
	int n = sizeof(arr)/sizeof(arr[0]);
	int n1 = longestIncreaseSubSequence_orderOf_nSquare(arr,n);
	int n2 = longestIncreaseSubSequence_orderOf_nlogn(arr,n);
	cout << "longestIncreaseSubSequence_orderOf_n2 : " << n1 << endl; 
	cout << "longestIncreaseSubSequence_orderOf_nlogn : " << n2 << endl;
	return 0;
}