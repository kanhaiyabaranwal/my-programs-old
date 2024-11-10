#include<iostream>
#include<unordered_set>
using namespace std;

int duplicate_within_k_distance(int *arr,int sz,int k)
{
	unordered_set<int> umap;
	for(int i=0;i<sz;i++)
	{
		if(umap.find(arr[i])!=umap.end())
		{
			cout<<"Element "<<arr[i]<<" found within distance "<<k<<endl;
			return 0;
		}
		if(i-k>=0)
		{
			umap.erase(umap.find(arr[i-k]));
		}
		umap.insert(arr[i]);
	}
	cout<<"No duplicate found within distance "<<k<<endl;
	return 0;
}

int main()
{
	int arr[] = {1, 2, 3, 4, 4};
	int sz=sizeof(arr)/sizeof(arr[0]);
	int k=3;
	duplicate_within_k_distance(arr,sz,k);
	return 0;
}
