/*
http://www.geeksforgeeks.org/find-the-smallest-positive-number-missing-from-an-unsorted-array/
Find the smallest positive number missing from an unsorted array
----------------------------------------------------------------
You are given an unsorted array with both positive and negative elements.
You have to find the smallest positive number missing from the array in O(n) time using constant extra space.

*/
#include<iostream>
#include<algorithm>
using namespace std;

namespace NS76
{
	inline void swap(int& a, int& b)
	{
		int t = a; a = b; b = t;
	}
	void find_the_missing_number()
	{
		
		int arr[] = { -26, -40, 14, -12, -27, 43, -16, -24,
			-49, -5, -25, 44, 16, -44, 39, 6, -3, 45, -24,
			34, -47, 10, -10, 32, 5, 23, -2, 45, 40, -45, -4, 16,
			17, 13, -46, 40, -42, 40, 18, 11, -15, 43, 5, -49,
			1, -6, -40, 1, 41, 38, -15, -3 };
			
		//int arr[] = { 1,2,3,4,5 };
		int n = sizeof(arr) / sizeof(arr[0]);
		//step: 1
		//push all negatibe number to right side
		int i = 0, j = n - 1;
		while (i < j)
		{
			while (i < j && arr[i] > 0) i++;
			while (i < j && arr[j] <= 0) j--;
			if (i < j)
			{
				swap(arr[i], arr[j]); i++; j--;
			}
		}
		//total positive number
		int size = arr[j] > 0 ? j + 1 : j;
		//step: 2
		//set the index negative
		for (int i = 0; i < size; i++)
		{
			int index = abs(arr[i]) - 1;
			if (index < size)
				arr[index] = -(abs(arr[index]));
		}
		//step: 3
		//iterate over the arrary to find which is the first index missing/postive number
		int index = 0;
		int missing_number = size + 1;
		while (index < size)
		{
			if (arr[index] > 0)
			{
				missing_number = index + 1;
				break;
			}
			index++;
		}
		cout << "The missing number is : " << missing_number << endl;
	}
}
int main_76()
{
	NS76::find_the_missing_number();
	return 0;
}




