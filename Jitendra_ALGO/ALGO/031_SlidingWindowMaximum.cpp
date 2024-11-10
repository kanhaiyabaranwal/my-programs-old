/*
http://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/
*/


#include<iostream>
#include<deque>
using namespace std;

//Add comment
void printKMax(int A[], int n, int k)
{
	if(n < k) return;
	deque<int> dq; // we are storing index not actual value
	int i;
	for(i=0; i<k;i++)
	{
		while(!dq.empty() && A[dq.front()] <= A[i])
			dq.pop_front();
		dq.push_front(i);
	}
	cout << A[dq.back()] << " "; 
	for(i=k; i<n; i++)
	{
		//check if back/left-side is out of side window
		while(!dq.empty() && dq.back() <= (i-k))
			dq.pop_back();
		//check for smaller elements
		while(!dq.empty() && A[dq.front()] <= A[i])
			dq.pop_front();
		dq.push_front(i);
		cout << A[dq.back()] << " ";
	}
	cout << endl;
}


int main_31_SlidingWindowMaximum()
{
	//int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int arr[] = {12, 1, 78, 90, 57, 89, 56};
	int n = sizeof(arr)/sizeof(arr[0]);
	int k = 3;
	printKMax(arr, n, k);
	return 0;
}