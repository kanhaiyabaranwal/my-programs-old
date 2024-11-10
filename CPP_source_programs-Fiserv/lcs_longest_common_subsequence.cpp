//finding longest common subsequence using brute force
#include<iostream>
#include<string>
using namespace std;

void lcs(string str1,string str2)
{
	int len2=str2.length();
	int ln=(1<<len2)-1;
	string lcs;
	int max_len=0;
	cout<<"ln="<<ln<<endl;
	for(int i=ln;i>=0;i--)
	{
		string str;
		for(int j=0;j<str2.length();j++)
		{
			if((1<<j)&i)
				str+=str2[j];
		}
		cout<<"Looking for string "<<str<<endl;
		for(int k=0,l=0;k<str1.length();k++)
		{
			if(str1[k]==str[l])
				l++;
			if(l==str.length())
			{
				if(l>= max_len )
				{
					cout<<"max string found:"<< str<<endl;
					lcs=str, max_len=l;
				}
				break;
			}
		}
	}
	cout<<"longest common subsequence is "<<lcs<<" and length is "<<max_len<<endl;
	return;
}

int main()
{
	string str1="ABCBDAB";
	string str2="BDCABA";
	//string str1="ABC";
	//string str2="BC";
	cout<<"Program to find longest common subsequence"<<endl;
	lcs(str1,str2);
	return 0;
}	
