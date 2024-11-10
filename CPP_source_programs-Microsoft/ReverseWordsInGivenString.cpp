#include<iostream>
#include<stack>
#include<string>
using namespace std;


void ReverseWordsInGivenString(string expr)
{
	stack<string> stk;
	int i=0;
	string str;
	while(i<=expr.length())
	{
		if(expr[i]!='.' && i!=expr.length())
			str.append(1,expr[i]);
			
		else if(!str.empty())
		{
			stk.push(str);
			str.clear();
		}
		i++;
	}
	cout<<"Reverserd string is: ";
	while(stk.size())
	{
		cout<<stk.top();
		stk.pop();
		if(stk.size())
		cout<<".";
	}
	cout<<endl;
}

int main()
{
	string expression="I.Like.This.Program.Very.Much";
	ReverseWordsInGivenString(expression);
	cout<<"Done!";
	return 0;
}
