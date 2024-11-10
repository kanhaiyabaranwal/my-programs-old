#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;
#define SUM 40

int find_sum_to_k(int k,vector<int>& ivec,int arr[],int sz)
{
	if(k==0)
	{
		//sort vector elements.Create string by concatenating all elements. 
		//If element is not in current hash_set, push it and print the elements otherwise skip printing.
		copy(ivec.begin(),ivec.end(),ostream_iterator<int> (cout,","));
		cout<<endl;
		return 0;
	}
	for(int i=0;i<sz;i++)
	{
		if(k-arr[i] >=0 && find(ivec.begin(),ivec.end(),arr[i])==ivec.end())
		{
			ivec.push_back(arr[i]);
			find_sum_to_k(k-arr[i],ivec,arr,sz);
			ivec.pop_back();
		}
	}
	return 0;
}
int main()
{
	//int arr[]={21,3,4,16,17,8,7,19,23,10,31,9,3,20,11};
	int arr[]={21,3,4,16,17,8};
	//int arr[]={21,19,23,10};
	int sz=sizeof(arr)/sizeof(arr[0]);
	cout<<"size of array is "<<sz<<endl;
	vector<int> ivec;
	cout<<"Finding numbers whos sum is "<<SUM<<endl;
	find_sum_to_k(SUM,ivec,arr,sz);
	return 0;
}

