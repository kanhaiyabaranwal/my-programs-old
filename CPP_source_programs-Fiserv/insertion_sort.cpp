#include<iostream>
using namespace std;

inline void swap(int& i,int& j)
{
	i^=j;
	j^=i;
	i^=j;
	
}

int insert_sort(int *arr,int n)
{
	for(int i=0;i<n;i++)
		cout<<arr[i]<<",";
	cout<<endl;
	cout<<"insertion sort:"<<endl;
	for(int i=1;i<n;i++)
	{
		int j=i;
		while(j>0 && arr[j]<arr[j-1])
		{
			swap(arr[j],arr[j-1]);
			j--;
		}
	}
	for(int i=0;i<n;i++)
		cout<<arr[i]<<",";
	cout<<endl;
}

int main()
{
	int arr[]={7,3,9,5,4};
	insert_sort(arr,sizeof(arr)/sizeof(arr[0]));
	return 0;
}
