#include<iostream>
#include<utility>
using namespace std;

pair<int,int> max_subarray(int *arr,int len)
{
	int min_idx=-1,min=0,max=0,sum=0;
	int max_idx=0;
	pair<int,int> range(0,0);
	for(int i=0;i<len;i++)
	{
		sum+=arr[i];
		if(sum<min)
		{
			min=sum; min_idx=i;
		}
		if(sum-min>max)
		{
			max=sum-min;max_idx=i;
			//need to keep indexex of range of max value found until now
			range=make_pair(min_idx+1,i);
		}
	}
	return range;
}
	


int main()
{
	int arr[]={904,40,523,12,-335,-385,-124,1481,-31};
	int len=9;
	pair<int,int> range= max_subarray(arr,len);
	cout<<"max subarray at index "<<range.first<<","<<range.second<<endl;
	int sum=0;
	for(int i=range.first;i<range.second;i++)
		sum+=arr[i];
	cout<<"Sum is "<<sum<<endl;
	return 0;
}

