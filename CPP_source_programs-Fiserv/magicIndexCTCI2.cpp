//finding magic index where i=a[i] in O(logn) and numbers might be repeated
#include<iostream>
using namespace std;

void magic_index(int arr[],int start, int end)
{
	if(start<0 || start>end)
		return;
	int mid=(start+end)/2;
	if(start==end)
	{
		if(mid==arr[mid])
			cout<<"magic index at "<<mid<<" is "<<arr[mid]<<endl;
		return ;
	}
	if(mid==arr[mid])
	{
		cout<<"magic index at "<<mid<<" is "<<arr[mid]<<endl;
	}
	int leftindex=mid>arr[mid]?arr[mid]:mid-1;
	magic_index(arr,start,leftindex);
	int rightindex=mid<arr[mid]?arr[mid]:mid+1;
	magic_index(arr,rightindex,mid+1);
	return;
}

int main()
{
	int arr[]={-5,1,3,4,5,6,6,6,9};
	magic_index(arr,0,sizeof(arr)/sizeof(arr[0])-1);
	cout<<"magic index search over"<<endl;
	return 0;
}
