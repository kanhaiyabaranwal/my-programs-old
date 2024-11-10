//Find non-common characters from 2 list of characters a[] and b[]
#include<iostream>
#include<map>
using namespace std;

int main()
{
	char a[]={'a','b','c','d'};
	char b[]={'b','c','e'};
	map<char,int> map1;
	int lenA=sizeof(a)/sizeof(a[0]);
	int lenB=sizeof(b)/sizeof(b[0]);
	for(int i=0;i<lenA;i++)
		map1[a[i]]++;
	for(int i=0;i<lenB;i++)
		map1[b[i]]++;
	cout<<"list of non-common characters"<<endl;
	for(map<char,int>::const_iterator it=map1.begin();it!=map1.end(); it++)
		if(it->second ==1)
			cout<<it->first<<"\t";
	return 0;
}
	

