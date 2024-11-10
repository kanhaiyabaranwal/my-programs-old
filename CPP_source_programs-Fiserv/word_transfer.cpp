//reversing each word in a sentence
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<stack>
using namespace std;

int main()
{
	ifstream in("string.txt");
	string str;
	vector<string> svec;
	cout<<"Reading sentences "<<endl;
	while(in>>str)
	{
		cout<<str;
		svec.push_back(str);
	}
	vector<string>::const_iterator iter=svec.begin();
	cout<<"sentence in vector is ";
	char cst[20];
	while(iter!=svec.end())
	{
		//cout<<*iter++<<",";
		memset(cst,NULL,sizeof(cst));
		strcpy(cst,iter->c_str());
		stack<char> stk;
		char *pch=cst;
		while(*pch)
		{
			stk.push(*pch);
			pch++;
		}
		while(stk.size()>0)
		{
			cout<<stk.top();
			stk.pop();
		}
		iter++;
	}
			
	cout<<endl;
	return 0;
}
