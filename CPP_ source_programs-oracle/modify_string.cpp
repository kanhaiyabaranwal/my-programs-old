//Two strings are given. 
//Modify 1st string such that all the common characters of the 2nd strings have to be removed and the uncommon characters of the 2nd string have to be concatenated with uncommon characters of the 1st string.

#include<iostream>
#include<string>
#include<vector>

using namespace std;

string modify_string1(string& s1,string& s2)
{
	vector<bool> cvec1(26),cvec2(26);
	for(int i=0;i<s1.length();i++)
	{
		cvec1[s1[i]-'a']=1;
	}
	for(int i=0;i<s2.length();i++)
	{
		cvec2[s2[i]-'a']=1;
	}
	string s3;
	int j=0;
	for(int i=0;i<s1.length();i++)
	{
		if(! cvec2[s1[i]-'a'])
		{
			s3.push_back(s1[i]);
			
		}
			
	}
	for(int i=0;i<s2.length();i++)
	{
		if(cvec2[s2[i]-'a'] && !cvec1[s1[i]-'a'])
			s3.push_back(cvec2[i]+'a');
	}
	cout<<"Modified string is : "<<s3<<endl;
	return s3;
 } 
 


void process(string s1, string s2)
{
    int A[26] = {0};
    size_t n1 = s1.length();
    size_t n2 = s2.length();
    for(int i=0;i<n1;i++)
    {
        A[s1[i]-'a'] = 1;
    }
    for(int i=0;i<n2;i++)
    {
        if(A[s2[i]-'a'] == 1)
            A[s2[i]-'a'] = 2;
        else if(A[s2[i]-'a'] == 0)
            A[s2[i]-'a'] = 3;
    }
    size_t n = n1+n2+1;
    char* output = new char[n];
    n=0;
    for(int i=0;i<n1;i++)
    {
        if(A[s1[i]-'a'] == 1)
            output[n++] = s1[i];
    }
    for(int i=0;i<n2;i++)
    {
        if(A[s2[i]-'a'] != 2)
            output[n++] = s2[i];
    }
    if(n == 0)
        cout << "-1" << endl;
    else
    {
        output[n++] = '\0';
        cout << output << endl;
    }
    
}

string modify_string(string& s1,string& s2)
{
	string s3;
	vector<bool> cvec1(26),cvec2(26);
	for(int i=0;i<s1.length();i++)
	{
		cvec1[s1[i]-'a']=1;
	}
	s1.append(s2);
	for(int i=0;i<s2.length();i++)
	{
		cvec2[s2[i]-'a']=1;
	}
	for(int i=0;i<s1.length();i++)
	{
		if(cvec2[s1[i]-'a'] ^ cvec1[s1[i]-'a'])
			s3.push_back(s1[i]);
	}
	cout<<"Modified string is : "<<s3<<endl;
	return s3;
}

int main()
{
	string s1("aacdb");
	string s2("gafdf");
	//cout<<"Enter string1: ";
	//cin>>s1;
	//cout<<"Enter string2:";
	//cin>>s2;
	//process(s1,s2);
	string s3=modify_string(s1,s2);
	//cout<<"Modified string is : "<<s3<<endl;
	return 0;
}
