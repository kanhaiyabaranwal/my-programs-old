//Find element in o(logn) in a circular sorted list
#include<iostream>
using namespace std;

int find_in_circular_rotated_sorted_list(int *arr,int start,int end,int key)
{
	if(start>end)
		return -1;
	int mid=start+(end-start)/2;
	if(arr[mid]==key)
		return mid;
	if(arr[mid]>=arr[start])	//first part is sorted
	{
		if(key>=arr[start] && key<=arr[mid-1])
			return find_in_circular_rotated_sorted_list(arr,start,mid-1,key);
		else
			return find_in_circular_rotated_sorted_list(arr,mid+1,end,key);
	}
	else	//second part is sorted
	{
		if(key>=arr[mid] && key<=arr[end])
			return find_in_circular_rotated_sorted_list(arr,mid+1,end,key);
		else
			return find_in_circular_rotated_sorted_list(arr,start,mid-1,key);
	}
}

int main()
{
	//int arr[]={4, 5, 6, 7, 8, 9, 1, 2, 3};
	int arr[]={2,1};
	int f=find_in_circular_rotated_sorted_list(arr,0,1,1);
	cout<<"index of 1 is "<<f<<endl;
	return 0;
}
	
		
	
			
		
			
	
