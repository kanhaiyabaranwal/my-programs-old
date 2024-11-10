#include<iostream>
#include<vector>
#include<algorithm>
#include<ctime>
#include<cstdlib>
using namespace std;

#define NUM 6

int moore_voting(int *arr,int sz)
{
	int i=1;int count=1;int e=arr[0];
	while(i<sz)
	{
		if(arr[i]==e)
			count++;
		else 
		{
			count--;
			if(!count)
				e=arr[i],count=1;
		}
		i++;
	}	
	cout<<"Max occuring element is "<<e<<" count at the end is "<<count<<endl;
	return e;
}
		


int main()
{
	int arr[]={4,4,2,3,4,5,2,3,4,4,4,4,2};
	int size=sizeof(arr)/sizeof(arr[0]);
	cout<<"nbr of elements:"<<size<<endl;
	for(int i=0;i<size;i++)
		cout<<arr[i]<<",";
	cout<<endl;
	int max=moore_voting(arr,size);
	return 0;
}
	
