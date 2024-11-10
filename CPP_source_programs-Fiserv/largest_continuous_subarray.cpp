#include<iostream>
#include<unordered_map>
#include<map>
using namespace std;
using namespace std::tr1;
#define NUM 3


int largest_continuous_subarray(int *arr,int len)
{
	unordered_map<int,int> umap;	//integer,index
	map<int,int> mmap;		//index,integer
	int curlen=0;	
	int maxlen=0;
	int starti,endi,gstart;
	for(int i=0;i<len;i++)
	{
		if(umap.find(arr[i])==umap.end())	//integer not found
		{
			if(umap.size()>=NUM)	//full size, remove oldest indexed integer
			{
				int ind=mmap.begin()->second;	//get value that needs to be removed
				cout<<"Size full, erase index:"<<mmap.begin()->first<<";value:"<<ind<<endl;
				mmap.erase(mmap.begin());	//remove oldest index item
				umap.erase(umap.find(ind));
			}
			cout<<"Inserting element "<<arr[i]<<" at index "<<i<<endl;
			umap.insert(make_pair(arr[i],i));
			mmap.insert(make_pair(i,arr[i]));
			if(mmap.size())
				curlen=i-mmap.begin()->first+1;
			else
				curlen=1;
			gstart=mmap.begin()->first;
		}
		else
		{
			curlen+=1;
			cout<<"Element found, curlen "<<curlen<<" and changing index in map"<<endl;
			int ind=umap[arr[i]];
			cout<<"Old index "<<ind<<" of "<< arr[i]<<" is removed"<<endl;
			mmap.erase(mmap.find(ind));
			mmap.insert(make_pair(i,arr[i]));
			umap[arr[i]]=i;
		}
		if(curlen>maxlen)
		{
			maxlen=curlen;
			map<int,int>::const_iterator iter=mmap.begin();
			starti=gstart;
			while(iter!=mmap.end())
			{
				endi=iter->first;
				iter++;
			}
			cout<<"New maxlen is "<<maxlen<<" gstart="<<gstart<<", endi="<<endi<<endl;
		}
			
	}
	cout<<"Longest subarray is of length "<<endi-starti<<endl;
	cout<<"Letters are ";
	while(starti<=endi)
		cout<<arr[starti++]<<",";
	cout<<endl;
	return 0;
}
int main()
{
	int arr[]={1,2,3,1,4,3,4,1,2};
	largest_continuous_subarray(arr,9);
	return 0;
}	
