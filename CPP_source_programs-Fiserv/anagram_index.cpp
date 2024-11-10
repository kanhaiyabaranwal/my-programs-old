#define __IBMCPP_TR1__ 1
#include<iostream>
#include<map>
#include<string>
#include<algorithm>
#include<fstream>
#include<vector>
#include<unordered_map>
using namespace std::tr1;
using namespace std;

typedef vector<string> STRVECTOR;
void anagram_index()
{
	ifstream in("word.txt");
	string s;
	int index=0;
	unordered_map<string,vector<int> > hmap;
	STRVECTOR svec;
	while(in>>s)
	{
		svec.push_back(s);
		sort(s.begin(),s.end());
		//cout<<"Pushing index of "<<s<<" at index "<<index+1;
		hmap[s].push_back(++index);
	}
	cout<<"Number of elements in hash map="<<hmap.size()<<endl;
	STRVECTOR::const_iterator iter=svec.begin();
	cout<<"showing words with index of anagrams"<<endl;
	while(iter!=svec.end())
	{
		string str=*iter;
		sort(str.begin(),str.end());
		//cout<<"Number of elements beginning "<<*iter<<" is "<<hmap[str].size()<<endl;
		cout<<*iter<<" ";
		copy(hmap[str].begin(),hmap[str].end()-1,ostream_iterator<int>(cout,","));
		cout<<hmap[str].back()<<endl;
		iter++;
	}
	
	
	return;
}

			

int main()
{
	cout<<"Takes input from word.txt and"\ 
		"shows indexes of all anagrams in the file"<<endl;
	anagram_index();	
	return 0;
}
