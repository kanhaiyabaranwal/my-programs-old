#include<iostream>
#include<stack>
#include<unordered_set>
#include<string>
using namespace std;


void reverse_the_given_string(string str)
{
	stack<char> cstk;
	unordered_set<char> cset;
	typedef string::const_iterator iter;
	for(iter citer =str.begin(); citer!=str.end(); citer++)
	{
		if(cset.find(*citer)==cset.end())
		{
			cstk.push(*citer);
			cset.insert(*citer);
		}
		
	}
	while(!cstk.empty())
	{
		cout<<cstk.top()<<",";
		cstk.pop();
	}
	cout<<endl;
}

int main()
{
	string str("GEEKS FOR GEEKS");
	reverse_the_given_string(str);
	return 0;
}
