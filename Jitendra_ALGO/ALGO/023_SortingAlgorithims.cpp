#include<iostream>
using namespace std;

inline void my_swap_23(int& a, int& b)
{ int tmp = a; a=b; b=tmp; }
inline void print(int A[], int n)
{ for(int i=0;i<n;i++) cout << A[i] << "  "; cout << endl;}

/* Heap Sort Start */
void heapify(int A[], int n, int root)
{
	if(n <=0 || root >= n || root < 0) return;
	int left = 2*root +1; int right = 2*root +2;
	int max = root;
	if(left < n && A[max] < A[left])
		max = left;
	if(right < n && A[max] < A[right])
		max = right;
	if(max != root)
	{
		my_swap_23(A[root],A[max]);
		heapify(A, n, max);
	}
}
void heapSort(int A[], int n)
{
	//Build-Heap from floor n/2 till root node(0)
	for(int i=(n/2)-1; i>=0; i--)
		heapify(A,n,i);
	//Exchange top element and decrement the size
	while(n > 0)
	{
		my_swap_23(A[0], A[n-1]);
		n--; heapify(A,n,0);
	}
}
/* Heap Sort End */

int main_23_SortingAlgorithims()
{
	int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]); 
	cout << "Unsortned array is \n";
    print(arr, n);
    heapSort(arr, n);
	cout << "Sorted array is \n";
    print(arr, n);
	return 0;
}
