#include<iostream>

using namespace std;

int BS(int *arr,int l,int u,int val)
{
	if(l>u)
		return -1;
	int mid=l+(u-l)/2;
	int index;
	if(arr[mid]==val)
		return mid;
	else if(arr[mid]>val)
		return BS(arr,l,mid-1,val);	
	else if(val<=arr[u])
		return BS(arr,mid+1,u,val);	
	else
		return -1;
}
int BS_iteration(int *arr,int l,int u,int val)
{
	int mid;
	while(l<=u)
	{
		mid=l+(u-l)/2;
		if(arr[mid]==val)
			return mid;
		else if(arr[mid]>val)
			u=mid-1;
		else if(val<=arr[u])
			l=mid+1;
	}
		return -1;
}


int main()
{
	int arr[]={-14, -10, 2, 108, 108, 243, 285, 285, 285, 401};
	int val;
	cout<<"Enter value to be searched: ";
	cin>>val;
	int sz=sizeof(arr)/sizeof(arr[0]);
	//int index=BS(arr,0,sz-1,val);
	int index=BS_iteration(arr,0,sz-1,val);
	if(index!=-1)
		cout<<"Value "<<val<<" found at index "<<index<<endl;
	else
		cout<<"Value "<<val<<" not found"<<endl;
	return 0;	
}	
