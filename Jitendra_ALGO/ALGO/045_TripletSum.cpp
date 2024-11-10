/*
Find triplet that sum to a given value
http://www.geeksforgeeks.org/find-a-triplet-that-sum-to-a-given-value/
*/
#include<iostream>
#include<algorithm>
using namespace std;

void find3Numbers(int* A, int size, int triplateSum)
{
	sort(A, A+(size-1));

	for(int i=0; i<size;i++)
	{
		int balance = triplateSum - A[i];
		int s = i+1;
		int e = size-1;
		while(e > s)
		{
			int sum = A[s] + A[e];
			if( sum == balance)
			{
				cout << "Triplate : " << A[i] << "  " << A[s] << " "  << A[e] << endl;
				s++; e --;
			}
			else if ( sum > balance)
			{
				e--;
			}
			else
			{
				s++;
			}
		}
	}
}


int main_45_TripletSum()
{
    int A[] = {1, 4, 45, 6, 10, 8};
    int sum = 22;
    int arr_size = sizeof(A)/sizeof(A[0]);
 
    find3Numbers(A, arr_size, sum);
 
    return 0;
}