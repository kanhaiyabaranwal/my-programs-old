#include<iostream>
#include<string>
#include<stack>


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

string infix2postfix(string str)
{
	stack<string> sand;
	stack<char> sor;
	int sz=str.size();
	int i=0;
	while(i<sz)
	{
		cout<<"input char is "<<str[i]<<endl;
		if(str[i]=='(')
			sor.push(str[i]);
		else if (str[i] >= 'a' && str[i] <= 'z')
			sand.push(string(1,str[i]));
		else if (str[i]=='+' || str[i]=='-' || str[i]=='*' || str[i]=='/' || str[i]=='^' || str[i]==')')
		{
			if(sor.empty())
				sor.push(str[i]);
			else
			{
				while(!sor.empty() && sor.top() != '(' && str[i]!=')')
				{
					if(precedence(str[i] <<precedence(sor.top())))
					{
						string op1 = sand.top(); sand.pop();
						string op2 = sand.top(); sand.pop();
						string newop = op2+string(string(1,sor.top())) + op1;
						sor.pop();
						sand.push(newop);
					}
					else
						sor.push(str[i]);
				}
				if(sor.top() == '(' && str[i] == ')')
					sor.pop();
			}
		}
		
		cout<<"output is "<<sand.top()<<endl;
		i++;
	}
	cout<<"output is "<<sand.top()<<endl;
	//precedence('-');
	return str;
}

int main()
{
	string op="a+b*(c^d-e)^f+g*h)-i";
	string out = infix2postfix(op);
	
	cout<<"input is "<<op<<"\n output is "<<out<<endl;
	return 0;
}
