//Longest Increasing Sequence(LIS) in a sequence of integers
#include<iostream>
using namespace std;

 
int LIS_recursive(int arr[],int len)
{
	if(len==1)			//terminating condition. when array of integers is of size , LIS is also 1.
		return 1;
	//for every integer in the array at index j< len, find LIS and assign maximum.
	int max_lis=1;
	int temp_lis;
	for(int i=0;i<len-1;i++)		//LIS calculation from index 0 to n. last number is used for comparison, so n-1 comparisons only.
	{
		temp_lis=LIS_recursive(arr,i+1);		//length is 1 more than index
		if(arr[i]<=arr[len-1] && temp_lis+1>max_lis)
			max_lis=temp_lis+1;
	}
	return max_lis;
}

int *LIS;
int LIS_DP(int arr[],int len)		//top-down approach
{
	if(LIS[len-1]>1)
		return LIS[len-1];
	int max_lis=1;
	int temp_lis;
	for(int i=0;i<len-1;i++)		//LIS calculation from index 0 to n. last number is used for comparison, so n-1 comparisons only.
	{
		temp_lis=LIS_DP(arr,i+1);		//length is 1 more than index
		if(arr[i]<=arr[len-1] && temp_lis+1>max_lis)
			max_lis=temp_lis+1;
	}
	return max_lis;
	
}
int main()
{
	int arr[]={10,22,9,33,21,30,50,41,60,80};
	int len=sizeof(arr)/sizeof(arr[0]);
	int lis_length=LIS_recursive(arr,len);		//LIS from recursive
	
	cout<<"Longest Increasing Sequence from Recursive method is of length "<<lis_length<<endl;
	LIS=new int[len];
	for(int i=0;i<len;i++)
		LIS[i]=1;
	lis_length=LIS_DP(arr,len);					//LIS from DP
	cout<<"Longest Increasing Sequence from Dynamic Programming method is of length "<<lis_length<<endl;
	return 0;
}
