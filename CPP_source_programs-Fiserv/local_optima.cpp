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
void local_minima(int *arr,int sz)
{
	int i=1;
	int flag=0;
	while(i<sz-1)
	{
		if(arr[i]>arr[i+1])
		{
			i++;
			flag=1;
		}
		else
			if(flag)
			{
				cout<<arr[i]<<" ";
				flag=0;
				i+=2;	
			}
			else if(arr[i]<arr[i-1])
			{
				cout<<arr[i]<<" ";
				flag=1;
				i+=2;
			}
	}
	if(i==sz-1 && arr[i]>=arr[i-1])
		cout<<arr[i]<<endl;
	else
		cout<<endl;
}


int main()
{
	int arr[]={19,7,3,18,5,5,6,1,4};
	int val;
	cout<<"Printing all local minima:"<<endl;
	int sz=sizeof(arr)/sizeof(arr[0]);
	local_minima(arr,sz);
	return 0;	
}	
