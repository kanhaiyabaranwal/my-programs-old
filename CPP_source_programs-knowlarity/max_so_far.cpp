#include<iostream>
using namespace std;

int max(int a,int b)
{
	return a>b?a:b;
}

int maxSubArray(int arr[],int n)
{
	int max_so_far=arr[0];
	int max_sum=arr[0];
	int global_max_index=0;
	int local_max_index=0;
	for(int i=1;i<n;i++)
	{
		//find max_until current index
		if(arr[i]>max_so_far+arr[i])
			local_max_index=i;
		max_so_far=max(arr[i],arr[i]+max_so_far);
		//find max_global
		if(max_sum<max_so_far)
		{
			global_max_index=local_max_index;
			max_sum=max_so_far;
		}
	}
	cout<<"Max_sum starts at "<<arr[global_max_index]<<",at index "<<global_max_index<<endl;
	return max_sum;
}

int main()
{
	int a[] =  {-2, -3, -4, -1, -2, -1, -5, -3};
	int len=sizeof(a)/sizeof(a[0]);
	int max_num=maxSubArray(a,len);
	cout<<"max subarray:"<<max_num<<endl;
	return 0;
}
