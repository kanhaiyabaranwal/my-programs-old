#include<iostream>
#include<string>
#include<stack>
using namespace std;

int parenthesis(int n,string str,stack<string> stk)
{
	if(n==0)
	{
		while(stk.size()>0)
		{
			str+=stk.top();
			stk.pop();
		}
		cout<<str<<",";
		return 0;
	}
	if(n>0)
	{
		stk.push("}");
		str+="{";
		parenthesis(n-1,str,stk);		
		//stk.pop();
	}
	while(stk.size()>0)
	{
		stk.pop();
		str+="}";
		parenthesis(n-1,str,stk);		
		//parenthesis(n-1,str+"}",stk);
	}
	return 0;
}
int main()
{
	cout<<"Printing all combinations of parenthesis"<<endl;
	cout<<"Number of parenthesis ";
	int n;
	cin>>n;
	string str;
	stack<string> stk;
	parenthesis(n,str,stk);
	return 0;
}
