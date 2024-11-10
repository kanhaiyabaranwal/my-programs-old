//power set - printing all subsets of a set
#include<iostream>
#include<vector>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;

int subsetutil(string parent,string child)
{
	static int count;
	int len=child.length();
	//cout<<"{"<<parent<<"},";
	//count++;+
	for(int i=0;i<len;i++)
	{
		cout<<"{"<<parent+child.substr(i,1)<<"},";
		count++;
		string newparent=parent+child.substr(i,1);
		string newchild;
		if(i)
			newchild=child.substr(0,i-1)+child.substr(i+1,len-i-1);
		else
			newchild=child.substr(1,len);
		subsetutil(newparent,newchild);
	}
	return count;
}

void subset(string str)
{
	int len=str.length();
	int total=0,i;
	for(i=0;i<len;i++)
	{
		cout<<"{"<<str.substr(i,1)<<"},";
		string parent=str.substr(i,1);
		string child=str.substr(i+1,len-i-1);
		int total=subsetutil(parent,child);
		cout<<"Number of subsets until beginning "<<parent<<" ="<<total+i+1<<endl;
	}
	//cout<<"Total number of subsets="<<total+len<<endl;
	cout<<"{"<<str.substr(i,1)<<"},";
	return;
}

int main()
{
	string str="abcd";
	subset(str);
	return 0;
}
