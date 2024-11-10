#include<iostream>
#include<queue>
#include<vector>
using namespace std;

#define Kth 5

int heap_sort(int *arr,int sz,int K)
{
	cout<<"Heap sorting"<<endl;
	priority_queue<int,vector<int>,less<int> > iheap;
	
	for(int i=0;i<K;i++)
		iheap.push(arr[i]);
	cout<<"Largest element is "<<iheap.top()<<endl;
	for(int i=K;i<sz;i++)
	{
		if(iheap.top()>arr[i])
		{
			iheap.pop();
			iheap.push(arr[i]);
		}
	}
	cout<<K<<"th Largest element is "<<iheap.top()<<endl;
	return 0;
	
}

int bubble_sort(int *arr,int sz)
{
	cout<<"Before bubble sorting"<<endl;
	for(int i=0;i<sz;i++)
		cout<<arr[i]<<",";
	cout<<endl;
	for(int i=0;i<sz;i++)
		for(int j=0;j<sz-1;j++)
			if(arr[j]>arr[j+1])
			{
				arr[j]=arr[j]+arr[j+1];
				arr[j+1]=arr[j]-arr[j+1];
				arr[j]=arr[j]-arr[j+1];
			}
	cout<<"After bubble sorting"<<endl;
	for(int i=0;i<sz;i++)
		cout<<arr[i]<<",";
	cout<<endl;
	return 0;
}

int selection_sort(int arr[],int sz)
{
	for(int i=0;i<sz;i++)
	{
		int min=arr[i];
		int pos=i;
		for(int j=i;j<sz;j++)
		{
			if(arr[j]<min)
			{
				min=arr[j];
				pos=j;
			}
		}
		if(pos!=i)
		{
			arr[pos]=arr[i];
			arr[i]=min;
		}
	}
	cout<<"After Selection sorting"<<endl;
	for(int i=0;i<sz;i++)
		cout<<arr[i]<<",";
	cout<<endl;
	return 0;
}


int main()
{
	int arr[]={1, 23, 12, 9, 30, 2, 50,43,5,17};
	int sz=sizeof(arr)/sizeof(arr[0]);
	//bubble_sort(arr,sz); 
	selection_sort(arr,sz); 
	heap_sort(arr,sz,Kth); 
	return 0;
}
