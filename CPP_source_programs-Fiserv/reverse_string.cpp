#include<iostream>
#include<vector>
#include<string>
#include<stack>

using namespace std;

int reverse_sentence(vector<string>& svec)
{
	for(int i=0;i<svec.size();i++)
	{
		string str=svec[i];
		stack<char> sch;
		int j=0;
		while(j<str.size())
			sch.push(str[j++]);
		while(sch.size())
		{
			cout<<sch.top();
			sch.pop();
		}
		cout<<" ";
	}
	return 0;
}

int main()
{
	vector<string> svec;
	svec.push_back("my");
	svec.push_back("name");
	svec.push_back("is");
	svec.push_back("kanhaiya");
	reverse_sentence(svec);
	return 0;
}
	
