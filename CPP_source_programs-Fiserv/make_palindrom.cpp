#include<iostream>
#include<stack>
#include<queue>
#include<cstring>
using namespace std;

void make_palindrom(char str[])
{
	int i=0,j=strlen(str)-1;
	int end=j;
	queue<int> q;
	stack<int> stk;
	while(i<j)
	{
		if(str[i] != str[j])
		{
			while(q.size())
			{
				stk.push(q.front());
				q.pop();
			}
			stk.push(i);
			i++;
			j=end;
		}
		else
		{
			q.push(i);
			i++,j--;
		}
	}
	cout<<"Original  string:"<<str<<endl;
	cout<<"Palindrom string:"<<str;
	while(stk.size())
	{
		cout<<str[stk.top()];
		stk.pop();
	}
	cout<<endl;
}
int main()
{
	char str[]="abcdbcbbcbbd";
	make_palindrom(str);
	return 0;
}

