//Find an element in a sorted circular array in order logn.
#include<iostream>
using namespace std;
int circular_array_find(int *arr,int start,int end,int elem)
{
	int mid=start+(end-start)>>1;
	if(arr[mid]==elem)
		return mid;
	if(end==start)
		return -1;	
	if(arr[start]<arr[mid] )		//first half is sorted in increasing order and element lies in it
		if(elem>=arr[start] && elem<arr[mid])
			circular_array_find(arr,start,mid-1,elem);	//search in first half
		else
			circular_array_find(arr,mid+1,end,elem);	//search in second half
	else if(arr[mid+1]<arr[end])		//first half is not sorted, contains pivot element, second half is sorted
		if(elem>arr[mid] && elem<=arr[end])
			circular_array_find(arr,mid+1,end,elem);	//search in second half
		else
			circular_array_find(arr,start,mid-1,elem);
	else 
		cout<<"Bad input array"<<endl;
	return -1;

}

int find_pivot_element(int *arr,int start,int end)
{
	if(end==start)
		return start;
	int mid=start+((end-start)>>1);
	if(arr[mid]>arr[mid+1])		//pivot element found
		return mid;
	if(arr[mid]<arr[end])	//second half is sorted, pivot is in first
		return find_pivot_element(arr,start,mid-1);
	else
		return find_pivot_element(arr,mid+1,end);
}
	

int main()
{
	int a[]={4,5,6,7,8,9,1,2};
	int len=8;
	int start=0;
	int elem;
	for(int i=0;i<len;i++)
		cout<<a[i]<<",";
	cout<<endl;
	int pivot=find_pivot_element(a,start,len-1);
	cout<<"Pivot element is "<<a[pivot]<<endl;
	cout<<"Enter element to search:";
	cin>>elem;
	int ind=circular_array_find(a,start,len-1,elem);
	if(ind)
		cout<<"Element found at index "<<ind<<" and element is "<<a[ind]<<endl;
	else
		cout<<"Element not found"<<endl;
	return 0;
}
