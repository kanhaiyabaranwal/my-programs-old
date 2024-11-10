#include<iostream>
#include<unordered_map>
using namespace std;

void zero_sum_subarray(int *arr,int sz)
{
	unordered_map<int,int> umap;	//sum and index
	int sum=0;
	for(int i=0;i<sz;i++)
	{
		sum+=arr[i];
		
		if(umap.find(sum)!=umap.end())
		{
			cout<<"sum zero found from index "<<umap[sum]+1<<" to "<<i<<endl;
			break;
		}
		else
		{
			umap.insert(make_pair(sum,i));
		}
	}
	unordered_map<int,int>::const_iterator iter=umap.begin();
	cout<<"Value in hash map are "<<endl;
	while(iter!=umap.end())
	{
		cout<<iter->first<<","<<iter->second<<endl;
		iter++;
	}
}

int main()
{
	int arr[]={4,2,-3,1,6};
	zero_sum_subarray(arr,5); 
	return 0;
}

