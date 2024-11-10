#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

typedef unordered_map<char,int> UMAP;		//hash map of character and index

int first_non_repeated_char(string str)
{
	UMAP umap;
	int sz=str.size();
	int *count=new int[sz];
	for(int i=0;i<sz;i++)
	{
		count[i]=1;
		UMAP::const_iterator iter=umap.find(str[i]);
		if(iter!=umap.end())
		{
			count[iter->second]++;
		}
		else
			umap[str[i]]=i;
	}
	UMAP::const_iterator iter=umap.begin();
	int i=0;
	while(iter!=umap.end())
	{
		cout<<"Current character is "<<iter->first<<" and its index is "<<iter->second<<" and its count is "<<count[iter->second]<<endl;
		iter++;
		i++;
	}
	iter=umap.begin();
	int ind=0, min_ind=100;
	for(int i=0;iter!=umap.end();iter++,i++)
	{
		ind=iter->second;
		if(count[ind]==1 && min_ind>ind)
			min_ind=ind;
	}
	cout<<"First non-repetitive character is "<<str[min_ind]<<endl;
	return 0;	
}
int main()
{
	string str="attached";
	first_non_repeated_char(str);
	return 0;
}
