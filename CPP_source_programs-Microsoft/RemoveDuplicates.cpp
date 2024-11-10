#include<iostream>
#include<string>
using namespace std;
//Recursively remove all duplicates from string
//Input: geeksforgeek
//output:gksforgk


string RemoveDuplicates(string str)
{
	int cur=0,nav=0;
	int len=str.length();
	//char newstr[len] {'\0'};
	string newstr;
	
	while(nav<len)
	{
		if(nav==len-1)
			newstr[cur]=str[nav];
		int i=nav+1;

		while(str[i]==str[nav])
		{
			i++;
		}
		if(i==nav+1)
		{
			//newstr[cur]=str[nav];
			newstr.append(1,str[nav]);
			cur++;
			nav++;
		}
		else
			nav=i;
	}
	//newstr[cur]='\0';
	cout<<"newstr="<<newstr<<endl;
	return newstr;
}

int main()
{
	string str="geeksforgeek";
	string newstr = RemoveDuplicates(str);
	cout<<"new str="<<newstr<<endl;
	return 0;
}

