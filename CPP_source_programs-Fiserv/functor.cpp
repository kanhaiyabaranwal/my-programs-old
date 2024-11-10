/*pattern matching with functor implementation*/
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

class StringMatch{
	string pattern;
public:
	StringMatch(string& pat):pattern(pat)
	{
	}
	bool operator()(const string& str)
	{
		return str.find(pattern)==string::npos?0:1;
	}
};

int main()
{
	char ch[]="kanhaiya";
	cout<<"ch="<<ch<<endl;
	vector<string> svec;
	svec.push_back("Kanhaiya");
	svec.push_back("Sneha");
	svec.push_back("neha");
	svec.push_back("Kanha");
	svec.push_back("Saneha");
	string pat="an";
	StringMatch patmatch(pat);
	int cnt=count_if(svec.begin(),svec.end(),patmatch);	//functor patmatch is called as function
	cout<<"Nbr of match found="<<cnt<<endl;	

	return 0;
}
