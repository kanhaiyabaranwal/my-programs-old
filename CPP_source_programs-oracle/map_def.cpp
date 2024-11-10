#include<iostream>
#include <map>
using namespace std;

int main()
{
	map<int,int> imap;
	imap[1]=2;
	imap[2]=4;
	typedef map<int,int>::const_iterator iterator;
	iterator iter=imap.begin();
	while(iter!=imap.end())
	{
		cout<<iter->first<<" , "<<iter->second<<endl;
		iter++;
	}
	cout<<"Map reloaded"<<endl;
	return 0;
	
}

