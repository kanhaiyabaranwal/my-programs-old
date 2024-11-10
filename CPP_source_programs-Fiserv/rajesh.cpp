#include<iostream>
#include<vector>
#include<cstring>
#include<string>
#include<fstream>
using namespace std;

string longestchain(vector<string>& vstr)
{
	int max_count=0;
	string max_str;
	for(int i=0;i<vstr.size();i++)
	{
		if(vstr[i].size()>max_count)
		{
			max_count=vstr[i].size();
			max_str=vstr[i];
		}
	}
	
	return max_str;
}

int palindrom(char *str)
{
	int i=0,append=0;
	int len=strlen(str);
	int j=len-1;
	int start=0;
	string str1;
	while(i<j)
	{
		if(str[i]==str[j])
		{
			i++,j--;
		}
		else
		{
			str1.insert(0,1,str[append]);
			append++;
			i=append;
			j=len-1;
		}
	}
	if(!(len&1) && append==(len-1))
	{
		str1.insert(0,1,str[append]);		
		append++;
	}
	cout<<"string to be appended is "<<str1<<endl;
	return append;
}
int main()
{
	ifstream in("words.txt");
	char str[]="abcdda";
	cout<<"String is "<<str<<endl; 
	int len=palindrom (str);
	cout<<"No. of characters to be appended is "<<len<<endl;
	return 0;
}
