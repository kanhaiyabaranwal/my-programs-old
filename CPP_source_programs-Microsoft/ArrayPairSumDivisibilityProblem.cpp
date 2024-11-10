//Array Pair Sum Divisibility Problem
#include<iostream>
#include<unordered_map>
using namespace std;

bool ArrayPairSumDivisibilityProblem(int arr[], int n,int mod)
{
	unordered_map<int,int> umap;	//umap of modus operandi and count
	for(int i=0;i<n;i++)
	{
		umap[arr[i]%mod]++;
	}
	unordered_map<int,int>::const_iterator iter=umap.begin();
	while(iter!=umap.end())
	{
		cout<<"hmap values:"<<iter->first<<" and "<<iter->second<<endl;
		if(iter->second%2!=0)
			return false;
		iter++;
	}
	return true;
	
}

int main()
{
	int arr[]={9,7,5,3,14,19};
	int mod=4;
	int n=sizeof(arr)/sizeof(*arr);
	bool result= ArrayPairSumDivisibilityProblem(arr,n,mod);
	cout<<"result"<<result<<endl;
	return 0;
}
