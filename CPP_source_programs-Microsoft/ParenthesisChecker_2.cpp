#include<iostream>
#include<stack>
#include<string>
using namespace std;

void ParenthesisChecker(string expression)
{
	const string ERR = "Badly Formed String";
	const string SUCCESS = "Parenthesis Match completed";
	stack<char> stk;
	int i=0;
	while(i<expression.length())
	{
		if(expression[i]=='(' || expression[i]=='{' || expression[i]=='[' )
			stk.push(expression[i]);
		else
		{
			if(expression[i]==')' || expression[i]=='}' || expression[i]==']')
			{
				if(stk.size()==0 || (stk.size()>0 && (
						(expression[i]==')' && stk.top() !='(') ||
						(expression[i]=='}' && stk.top() !='{') ||
						(expression[i]==']' && stk.top() !='[')
						)))
				{
					cout<<ERR<<endl;
					return;
				}
				else
				{
					cout<<stk.top()<<" matched to "<<expression[i]<<endl;
					stk.pop();
				}
					
			}
		}
		i++;
	}
	if(stk.size()!=0)
	{
		cout<<ERR<<endl;
	}
	cout<<SUCCESS<<endl;
}

int main_2()
{
	string expression="[()]{}{[()()]()}}";
	ParenthesisChecker(expression);
	cout<<"Done!";
	return 0;
}
