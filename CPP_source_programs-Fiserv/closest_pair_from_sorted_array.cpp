#include<iostream>
#include<cmath>
using namespace std;

int closest_pair(int *arr1,int len1,int *arr2,int len2,int num)
{

	int diff=1000,closest_diff=1000;
	int gi,gj;
	for(int i=0;i<len1;i++)
	{
		diff=num-arr1[i];
		int min_diff=closest_diff;
		int minj=0;
		for(int j=0;j<len2;j++)
		{
			int arr2diff=arr2[j]-diff;
			if(abs(arr2diff)<abs(min_diff))
			{
				min_diff=arr2diff;
				minj=j;
			}
		}
		if(abs(closest_diff)>abs(min_diff))
		{
			closest_diff=num-(arr1[i]+arr2[minj]);
			gi=i,gj=minj;
		}
	}
	cout<<"Closest pair to sum "<<num<<" are "<<arr1[gi]<<" and "<<arr2[gj]<<endl;
	return 0;
}
int closest_pair2(int *arr1,int len1,int *arr2,int len2,int sum)
{
	int l=0,r=len2-1;
	int diff=1000;
	int minl,minr;
	while(l<len1 && r>0)
	{
		if(abs(arr1[l]+arr2[r]-sum)<diff)
		{
			diff=abs(arr1[l]+arr2[r]-sum);
			minl=l,minr=r;
		}
		if(arr1[l]+arr2[r]<sum)
			l++;
		else
			r--;
	}
	cout<<"Minimum difference is "<<diff<<" and values are "<<arr1[minl]<<" and "<<arr2[minr]<<endl;
	return 0;
}
		
int main()
{
	int arr1[]={1,4,5,7};
	int arr2[]={10,20,30,40};
	int num;
	cout<<"Enter closest sum value:";
	cin>>num;
	//closest_pair(arr1,4,arr2,4,num);
	closest_pair2(arr1,4,arr2,4,num);
	return 0;
}
