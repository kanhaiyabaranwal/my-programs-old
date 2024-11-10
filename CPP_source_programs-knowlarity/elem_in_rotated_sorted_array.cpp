//find elem_in_rotated_sorted_array
#include<iostream>
using namespace std;


int elem_in_rotated_sorted_array(int arr[],int s, int e, int key)
{
	int mid=s+(e-s)/2;
	if(arr[mid]==key)
		return mid;
	if(s+1==e && arr[e]==key)
		return e;
	if(s==mid)
		return -1;
	if(arr[s]<=arr[mid-1])
	{
		if(key>=arr[s] && key<arr[mid])
			return elem_in_rotated_sorted_array(arr,s,mid-1,key);
		else
			return elem_in_rotated_sorted_array(arr,mid+1,e,key);
	}
	else
	{
		if(key>arr[mid] && key<=arr[e])
			return elem_in_rotated_sorted_array(arr,mid+1,e,key);
		else
			return elem_in_rotated_sorted_array(arr,s,mid-1,key);
	}
}
int main()
{
	int arr[]={4,5,6,7,1,2,3};
	int sz=sizeof(arr)/sizeof(arr[0]);
	int key=5;
	cout<<"Element found at index= "<<elem_in_rotated_sorted_array(arr,0,sz-1,key)<<endl;
	return 0;
}
