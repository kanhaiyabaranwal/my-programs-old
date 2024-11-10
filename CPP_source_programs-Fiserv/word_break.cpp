#include<iostream>
#include<map>
#include<string>
using namespace std;
typedef multimap<char,string> mmap;
mmap mymap;
typedef multimap<char,string>::const_iterator miter;
int strmatch(string str,string *match,int nbr=0)
{
	static int tcount=0;
	if(str=="")					//terminating condition
	{
		if(nbr!=0)
		{
			cout<<"word break up["<<tcount++<<"]=";
			for(int i=0;i<nbr;i++)
				cout<<match[i]<<" ";
			cout<<endl;
			delete [] match;
		}
		else
			cout<<"No string match found"<<endl;
		return tcount;
	}
	char ch=*(char*)str.substr(0,1).c_str();
	miter iter=mymap.find(ch);
	int count=mymap.count(ch);
	for(int i=0;i<count;i++,iter++)
	{
		int sz=(iter->second).length();
		if(str.substr(0,sz)==iter->second)		//if match found, call with new string included 
		{
			string *newmatch=new string[nbr+1];
			int j=0;
			for(j=0;j<nbr;j++)
				newmatch[j]=match[j];
			newmatch[j]=iter->second;
			strmatch(str.substr(sz),newmatch,nbr+1);
		}
	}
	return tcount;
}
int main()
{
	//string str="ilikesamsung";
	string str="samsungandmango";
	//string strarr[]={"i", "like", "sam", "sung", "samsung", "mobile", "ice", "cream", "icecream", "man", "go", "mango"};
	string strarr[]={"mobile","samsung","sam","sung","man","mango","icecream","and","go","i","like","ice","cream"};
	
	int len=sizeof(strarr)/sizeof(strarr[0]);
	cout<<"sizeof string array="<<len<<",size of array="<<sizeof(strarr)<<endl;
	char ch;
	cout<<"Traversing through the multimap"<<endl;
	for(int i=0;i<len;i++)
	{
		ch=*(char*)strarr[i].substr(0,1).c_str();
		cout<<strarr[i]<<",";
		mymap.insert(make_pair(ch,strarr[i]));
	}
	cout<<endl<<"string is "<<str<<endl;
	miter iter=mymap.begin();
	string *match=0;
	int tcount=strmatch(str,match);	
	cout<<"Total number of matches found="<<tcount<<endl;
	return 0;
}
