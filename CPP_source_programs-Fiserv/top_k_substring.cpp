#include<iostream>
#include<unordered_map>
#include<map>
#include<queue>
#include<string>
using namespace std::tr1;
using namespace std;

typedef unordered_map<string,int> UMAP;
	
struct str_count{
	int count;
	string str;
	str_count(int c,string s):count(c),str(s) {}
	friend bool operator<(const str_count &str1,const str_count &str2)
	{
		return str1.count>str2.count;
	}
};

void top_k_substring(string *str,int n,int k,int top)
{
	UMAP umap;
	for(int i=0;i<n;i++)
	{
		//for each string, add/create into hash_map
		int len=str[i].length();
		cout<<"Processing string:"<<str[i]<<endl;
		for(int j=0;j<len-k+1;j++)
		{
			string str1=str[i].substr(j,k);		//substring of length
			umap[str1]++;
			cout<<"Next substring with count:"<<str1<<", "<< umap[str1]<<endl;
		}
	}
	UMAP::const_iterator iter=umap.begin();
	priority_queue<str_count> pqueue;
	int least_count=0;
	for(;iter!=umap.end();iter++)
	{
		cout<<"string is "<<iter->first<<", count is "<<iter->second<<endl;
		if(pqueue.size()< top)
			pqueue.push(str_count(iter->second,iter->first));
		else if( iter->second > pqueue.top().count)
		{
			pqueue.pop();
			pqueue.push(str_count(iter->second,iter->first));
		}
	}
	while(pqueue.size())
	{
		cout<<"Substring:"<<pqueue.top().str<<" and count="<<pqueue.top().count<<endl;
		pqueue.pop();
	}
}
			
int main()
{
	string str[]={"xyzabcdef","zabcd","yzabcd","abcd"};
	top_k_substring(str,4,3,3);
	return 0;
}
			
		
		
