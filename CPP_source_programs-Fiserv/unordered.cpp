#define __IBMCPP_TR1__ 1
#include<iostream>
#include<unordered_map>
#include<map>
#include<string>
using namespace std;
using namespace std::tr1;

int main()
{
	//unordered_map<string,int> umap;
	unordered_map<string,int> umap;
	umap.insert(make_pair("1",2));
	umap.insert(make_pair("4",2));
	unordered_map<string,int>::const_iterator iter=umap.begin();
	cout<<"values in unordered map are " <<endl;
	while(iter!=umap.end())
	{
		cout<<iter->first<<","<<iter->second<<endl;
		iter++;
	}
	
	return 0;
}
