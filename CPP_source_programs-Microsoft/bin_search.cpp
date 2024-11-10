#include<iostream>
using namespace std;


int bin_search(int *arr,int s,int e,int key)
{
	if(e<s)
		return -1;
	if(e==s)
		return arr[e]==key?e:-1;
	int mid=s+(e-s)/2;
	if(arr[mid]==key)
		return mid;
	if(key<arr[mid])
		return bin_search(arr,s,mid-1,key);
	else
		return bin_search(arr,mid+1,e,key);
	
}

int main()
{
	int arr[] {1,2,3,4,5};
	int index=bin_search(arr,0,4,2);
	cout<<"element found at "<<index<<endl;
	
}
