//Algorithm to find largest element in a sequence where numbers are ascending and then in descending order.
#include<iostream>
using namespace std;

int largest_element(int *arr,int l,int u)
{
	int mid,flag=0;
	while(l<=u)
	{
		mid=l+(u-l)/2;
		while(arr[mid]==arr[mid-1])
		{
			mid++;
			flag=1;
		}
		if(flag)
		{
			--mid;
			if (arr[mid]>arr[mid+1])
				return mid;
			else
				l=mid+1;
			flag=0;
			continue;
		}
			
		if(arr[mid]>arr[mid-1])
			if(arr[mid]>arr[mid+1])
				return mid;
			else
				l=mid;
		else 
			u=mid;
	}
	return -1;
}


int main()
{
	//int arr[]={4,5,5,5,6,6,7,8,9,5,4,3,2,1,1,1};
	int arr[]={5,5,6,6,7,8,9,10,11,11,5,4,3,2,1,1,1};
	int sz=sizeof(arr)/sizeof(arr[0]);
	//int index=BS(arr,0,sz-1,val);
	int index=largest_element(arr,0,sz-1);
	if(index!=-1)
		cout<<"Largest Value "<<arr[index]<<" found at index "<<index<<endl;
	else
		cout<<"-1"<<endl;
	return 0;	
}	
