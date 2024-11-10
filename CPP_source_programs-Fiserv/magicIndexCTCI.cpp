//finding magic index where i=a[i] in O(logn)
#include<iostream>
using namespace std;

void magic_index(int arr[],int start, int end)
{
	if(start<0 || start>end)
		return;
	int mid=(start+end)/2;
	
	if(mid==arr[mid])
		cout<<"magic index at "<<mid<<" is "<<arr[mid]<<endl;
	else if(mid<arr[mid])
		magic_index(arr,start,mid-1);
	else
		magic_index(arr,mid+1,end);
	return;
}

int main()
{
	int arr[]={-5,1,3,4,5,6,9};
	magic_index(arr,0,sizeof(arr)/sizeof(arr[0])-1);
	cout<<"magic index search over"<<endl;
	return 0;
}
