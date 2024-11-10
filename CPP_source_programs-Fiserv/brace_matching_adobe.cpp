#include<iostream>
#include<stack>
#include<string>
using namespace std;

int match_brace(string s)
{
	stack<char> schar;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='[' || s[i]=='{' || s[i]=='(')
				schar.push(s[i]);
		else if(s[i]==']' || s[i]=='}' || s[i]==')')
		{
				if(	(s[i]==']' && schar.top()=='[') ||  (s[i]=='}' && schar.top()=='{') || (s[i]==')' && schar.top()=='()'))
				{
					schar.pop();
					
				}
				else
					return 0;
		}
	}
	if(schar.size())
		return 0;
}

int main()
{
	string s="a+(b-[c+d*{3-u}])";
	if(match_brace)
		cout<<"correct matched found"<<endl;
	else
		cout<<"correct matched not found"<<endl;
		return 0;
}
