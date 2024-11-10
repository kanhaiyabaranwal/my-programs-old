//Reverse words from the end.
//Ex-
//Input "Today is Monday"
//Output is "Monday is Today"
#include<iostream>
#include<cstring>
#include<stack>

using namespace std;

int main()
{
	char str[]="Today is Monday";
	stack<char> stk;
	int len=strlen(str);
	char *pch=&str[len-1];
	cout<<"*pch="<<*pch<<endl;
	int i=0;
	while(i<=len)
	{
		if(*pch==' ' || i==len)
		{
			while(!stk.empty())
			{
				
				//cout<<"displaying top "<<stk.top()<<endl;
				cout<<stk.top();
				stk.pop();
			}
			cout<<' ';
		}
		//cout<<"inserting *pch "<<*pch<<endl;
		else
			stk.push(*pch);
		i++;
		pch--;
	}
	return 0;
}

