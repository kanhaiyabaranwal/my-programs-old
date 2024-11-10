#include<iostream>
using namespace std;

int LIS(int arr[],int n)
{
	int lis[n];
	for(int i=0;i<n;i++)
		lis[i]=1;
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(arr[j]<arr[i] && lis[i]<lis[j]+1)
				lis[i]=lis[j]+1;
		}
	}
	int max=1;
	for(int i=0;i<n;i++)
	{
		if(lis[i]>max)
			max=lis[i];
	}
	cout<<"Max LIS length is "<<max<<endl;
	return 0;
}

int main()
{
	int arr[]={ 10, 22, 9, 33, 21, 50, 41, 60, 80 } ;
	LIS(arr,9);
	return 0;
} 	
