//Given an input string and a dictionary of words, find out if the input string can be segmented into a space-separated sequence of dictionary words. See following examples for more details.

#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;

string svec[]={"i","like","samsung","sam","sung","man","go","mango"};
int len=8;
int DictFound(string str)
{
	//string[]={"i","like","samsung","sam","sung","man","go","mango"};
	for(int i=0;i<len;i++)
	{
		if(svec[i]==str)
			return 1;
	}
	return 0;
}

//returns vector of words found
int hasWord(string str,int s, int e, stack<string>& wstack)
{
	static int allPatternFound=0;
	if(s>=e)	//pattern navigated, all words found, now print
	{
		cout<<"pattern navigated, all words found, now print"<<endl;
		for(int i=0;wstack.size();i++)
		{
			cout<<wstack.top()<<", ";
			wstack.pop();
		}
		cout<<"Done searching";
		allPatternFound=1;
		return 0;
	}
	for(int i=s;i<=e;i++)
	{
		string smallstr=str.substr(s,i-s+1);
		cout<<"Finding "<<smallstr<<endl;
		int res=DictFound(smallstr);
		if (res==1)
		{
			cout<<smallstr<<" found; search further;i="<<i<<",e="<<e<<endl;
			wstack.push(smallstr);
			hasWord(str,i+1,e,wstack);
			if(allPatternFound)
				return 0;
			//search complete for this word, now pop and move to next
			wstack.pop();
		}
	}
	cout<<"Word Search not completely matched to the pattern\n";
	return 1;
}

int main()
{
        cout<<"Dictionary is :";
        for(int i=0;i<len;i++)
                cout<<svec[i]<<"\t";
	string pattern="ilikesamsung";
	int slen=pattern.size();
	stack<string> wvec;
	hasWord(pattern,0,slen-1,wvec);
	return 0;
}
	

