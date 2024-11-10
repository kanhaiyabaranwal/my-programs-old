#include<iostream>
#include<string>
#include<set>
using namespace std;
#define NBR_OF_PAIRS 6

set<string> validPairs(int n)
{
	set<string> news;
	if(n<1)
	{
		cout<<"Error!!!"<<endl;
		return news;
	}
	if(n==1)			//terminating condition
	{
		news.insert("()");
		return news;
	}
	set<string> prev=validPairs(n-1);
	set<string>::const_iterator iter=prev.begin();
	string temp;
	int len;
	for(;iter!=prev.end();iter++)
	{
		temp=*iter;
		len=temp.length();
		for(int i=0;i<len;i++)
		{
			string s=temp.substr(0,i)+"()"+temp.substr(i);
			news.insert(s);
		}	
	}
	return news;
}


int main()
{
	set<string> result=validPairs(NBR_OF_PAIRS);
	set<string>::const_iterator iter=result.begin();
	cout<<"showing set contents"<<endl;
	for(;iter!=result.end();iter++)
		cout<<*iter<<endl;	
	
	cout<<"set length="<<result.size()<<", set done"<<endl;
	return 0;
}
