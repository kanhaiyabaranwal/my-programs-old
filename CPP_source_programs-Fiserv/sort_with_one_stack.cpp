#include<iostream>
#include<stack>
using namespace std;

stack<int> SortWithOneStack(stack<int> s1)
{
	stack<int> s2;
	while(s1.size()>0)
	{
		int top=s1.top();
		s1.pop();
		while(s2.size()>0)
		{
			if(s2.top()>top)
			{
				s1.push(s2.top());
				s2.pop();
			}
			else
				break;
		}
		s2.push(top);
	}
	return s2;
}
int main()
{
	stack<int> s;
	s.push(4);
	s.push(10);
	s.push(1);
	s.push(56);
	s.push(5);
	stack<int> sout=SortWithOneStack(s);
	cout<<"Sorted stack is "<<endl;
	while(sout.size()>0)
	{
		cout<<sout.top()<<",";
		sout.pop();
	}
	return 0;
}
	

