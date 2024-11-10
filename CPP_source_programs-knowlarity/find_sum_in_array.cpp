#include<iostream>
#include<unordered_set>
using namespace std;

int print_pair(int arr[],int len,int sum)
{
	unordered_set<int> hset;
	for(int i=0;i<len;i++)
	{
		if(hset.find(sum-arr[i])!=hset.end())
			cout<<"Pair found are "<<arr[i]<<" and "<<sum-arr[i]<<endl;
		hset.insert(arr[i]);
	}
	return 0;
}
int main()
{
	int arr[]={1,4,45,6,10,-8,12};
	print_pair(arr,7,16);
	return 0;
}
