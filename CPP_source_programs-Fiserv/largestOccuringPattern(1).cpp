#include<iostream>
#include<map>
#include<string>
#include<algorithm>
using namespace std;

int main()
{

	string str("mynameiskanhaiyaandiliveinnoidanamemyhometownisdssmywifesnameissnenamehasheisnehafromspjwife");
	//string str("mynmyyn");
	map<string,int> map1;
	int len=str.length();
	string str1;
	for(int i=0;i<len;i++)
	{
		for(int j=0;j<=i;j++)
		{
			
			str1=str.substr(j,i-j+1);
			map1[str1]++;
		}
	}
	cout<<"elements in map="<<map1.size()<<endl;
	//for(map<string,int>::iterator it=map1.begin(); it != map1.end(); it++ )
	//	cout<<"first->"<<it->first<<" second->"<<it->second<<endl;

	int maxocr=0;
	for(map<string,int>::iterator it=map1.begin(); it != map1.end(); it++ )
	{
		if(it->first.length()>1 && maxocr < it->second)
			maxocr=it->second;	
	}
	cout<<"Max occuring subsequences are of length "<<maxocr<<endl;
	for(map<string,int>::iterator it=map1.begin(); it != map1.end(); it++ )
		if(it->second==maxocr && it->first.length()>1)
			cout<<it->first<<"\n";
	
	
	return 0;
	cout<<"done showing all subsequences"<<endl;
}
