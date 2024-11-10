//Largest subarray with 0 sum
#include<iostream>
#include<unordered_map>

using namespace std;

int MaxLen(int *arr,int n)
{
	int sum=arr[0];
	unordered_map<int,int> umap;		//sum,index
	int maxLen=0;
	umap[arr[0]]=0;
	for(int i=1;i<n;i++)
	{
		sum+=arr[i];
		if(umap.find(sum)!=umap.end())
		{
			if(i-umap[sum]>maxLen)
				maxLen=i-umap[sum];
		}
		else
			umap[sum]=i;
	}
	return maxLen+1;
}

int main()
{
	int arr[]={15,-2,2,-8,1,7,10,23};
	int len=sizeof(arr)/sizeof(*arr);
	int maxLen = MaxLen(arr,len);
	cout<<"maxLen having largest subarray with 0 sum:"<<maxLen<<endl;
}
