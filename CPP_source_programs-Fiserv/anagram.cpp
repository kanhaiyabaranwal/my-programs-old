#include<iostream>
#include<string>
using namespace std;

int anagram(string str1,string str2)
{
	int len=str2.length();
	static int count=0;
	if(str2.length()<=1)	//terminating condition
	{
		cout<<"Next Anagram ->"<<str1+str2<<endl;
		return count++;
	}
	string str3=str2.substr(0,1);
	anagram(str1+str3,str2.substr(1,str2.length()-1));	//called anagram for first combo
	for(int i=1;i<len;i++)
	{
		if(str3!=str2.substr(i,1))
		{
			string str5=str2.substr(1,i-1);		//2nd part
			string str4=str2.substr(i,1);		//3rd part
			string str6=str2.substr(i+1,str2.length()-i-1);	//4th part
			anagram(str1+str4,str5+str3+str6);
		}
	}
	return count;
}

int main()
{
	string  str="permute";
	cout<<"anagrams of pattern "<<str<<"\n";
	cout<<"char at 0 is "<<str.substr(0,1)<<endl;
	string str1;
	int count=anagram(str1,str);
	cout<<"Total count="<<count<<endl;
	return 0;
}
	
