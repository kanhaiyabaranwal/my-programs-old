#include<iostream>
#include<string>
#include<map>
#include<sstream>
using namespace std;

void compress(string s)
{
	map<int,int> smap;
	int ind=0,newind=0;
	int num1=0,num2=0;
	string str;
	int dash=0,flag=0;;
	stringstream ss;
	while(true)
	{
		newind=s.find(',',ind);
		if(newind==string::npos)
			flag=1;
		str=s.substr(ind,newind-ind);
		cout<<str<<endl;
		int dash=str.find('-');
		if(dash==string::npos)
		{
			ss<<str;
			ss>>num1;
			//cout<<"str="<<str<<",num1="<<num1<<endl;
			smap.insert(pair<int,int>(num1,num1));
		}
		else
		{
			
			string str1=str.substr(0,dash);
			string str2=str.substr(dash+1,str.size()-dash+1);
			//cout<<"str1="<<str1<<", str2"<<str2<<endl;
			ss<<str1;
			ss>>num1;
			ss.clear();
			ss<<str2;
			ss>>num2;
			smap.insert(pair<int,int>(num1,num2));
		}
		if(flag)
			break;
		ind=newind+1;
		ss.clear();
	}
	cout<<"iterating through the map"<<endl;
	for(map<int,int>::const_iterator iter=smap.begin();iter!=smap.end();iter++)
		cout<<iter->first<<","<<iter->second<<endl;
	cout<<"compressed string "<<endl;
	int init=0,start=0,cur=0;
	for(map<int,int>::const_iterator iter=smap.begin();iter!=smap.end();iter++)
	{
		//cout<<iter->first<<","<<iter->second<<endl;
		if(!start && !init)
		{
			init=iter->first;
			start=iter->second;
			continue;
		}
		cur=iter->first;
		if(cur==start+1)
			start=iter->second;
		else if(init!=start)
		{
			cout<<init<<'-'<<start<<",";
			init=iter->first;
			start=iter->second;
		}
		else
		{
			cout<<init<<',';
			init=iter->first;
			start=iter->second;
		}
	}
	if(init!=start)
		cout<<init<<'-'<<start<<endl;
	else
		cout<<init<<endl;
}

int main()
{
	string s="2,4,5-6,8,9-11,13,14-17,19,20-22,23-26,27,28,30";
	compress(s);
	return 0;
}
		

