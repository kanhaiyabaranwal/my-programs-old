#include<iostream>
#include<stack>
#include<string>

using namespace std;

int precedence(char ch)
{
	switch (ch)
	{
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
		case '^':
			return 3;
		default:
			return 5;
	
	}
}

void infix2postfix_only_one_stack(string in)
{
	string post;
	stack<char> stk;
	for(int i=0;i<in.length(); i++)
	{
		
		if(in[i] >= 'a' and in[i] <= 'z')
			post.push_back(in[i]);
		else
		{
			if(in[i]=='(')
				stk.push('(');
			else if(in[i]==')')
			{
				while(stk.top()!='(')
				{
					post.push_back(stk.top());
					stk.pop();
				}
				stk.pop();
			}
			
			else if( stk.size() && in[i] != '(' && stk.top() != '(') 
			{
				while( stk.size() && in[i] != '(' && stk.top() != '(' && precedence(in[i]) <= precedence(stk.top()))
				{
					
					post.push_back(stk.top());
					stk.pop();
					
				}
				stk.push(in[i]);
			}
			else
				stk.push(in[i]);
		}
	}
	
	cout<<"stack size is "<<stk.size()<<" and top is "<<stk.top()<<endl;
	while(stk.size())
	{
		post.push_back(stk.top());
		stk.pop();
	}
		
	cout<<"postfix string is "<<post<<endl;
}


int main()
{
	string op="a+b*((c^d-e)^f+g*h)-i";
	cout<<"op's size is "<<op.size()<<endl;
	infix2postfix_only_one_stack(op);
	
	return 0;
}
