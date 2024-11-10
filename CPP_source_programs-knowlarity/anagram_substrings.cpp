#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

void is_anagram(string str)
{
	int len=str.length();
	if(!len || len==1)
		return;
	string str1=str.substr(0,len/2);
	string str2;
	if(len&1)
		str2=str.substr(len/2+1,len/2);
	else
		str2=str.substr(len/2,len/2);
	cout<<"str1="<<str1<<" and str2=" <<str2<<endl;
	sort(str1.begin(),str1.end());
	sort(str2.begin(),str2.end());
	cout<<"str1="<<str1<<" and str2=" <<str2<<endl;
	if(str1==str2)
		cout<<"Yes, anagrams"<<endl;
	else
		cout<<"No anagrams"<<endl;
}

int main()
{
	string str;
	cout<<"Enter string:";
	cin>>str;
	is_anagram(str);
	return 0;
}
