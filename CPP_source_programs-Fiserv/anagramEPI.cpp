#include<iostream>
#include<map>
#include<unordered_map>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
void find_anagrams(const vector <string >& dict) {
// Get the sorted string and then insert into hash table.
	unordered_map <string , vector <string > > hash;
	
	for (const string& s : dict) {
		string sorted_str(s);
		// Use sorted string as the hash code.
		sort(sorted_str.begin(), sorted_str.end());
		hash[sorted_str].emplace_back(s);
	}

	for (const pair <string , vector <string > >& p : hash) {
	// Multiple strings with the same hash code => anagrams.
		if (p.second.size() >= 2) {
			cout<<"Output all strings for key "<<p.first<< " ->";
			for (const auto& s : p.second) {
				cout << s << " ";
			}
			cout << endl;
		}
	}
}

/*int anagram(vector<string>& dict)
{
	unordered_multimap<string,string> hmap;
	for(int i=0;i<dict.size();i++)
	{
		string sorted=dict[i];
		sort(sorted.begin(),sorted.end());
		cout<<"sorted string is "<<sorted<<endl;
		hmap.insert(make_pair(sorted,dict[i]));
	}
	cout<<"hash size is "<<hmap.size()<<endl;
	//cout<<"count of hash map with key kan is "<<count<<endl;
	unordered_multimap<string,string>::const_iterator iter=hmap.begin();
	cout<<"Values are ";
	string first;
	for(;iter!=hmap.end();iter++)
	{
		if(first!=iter->first)
		{
			cout<<endl<<"anagrams with key "<<iter->first<<" ";
			first=iter->first;
		}
		cout<<iter->second<<" ";
	}
	cout<<endl<<"The end"<<endl;
	return 0;
}*/

int main()
{
	vector<string> svec;
	svec.push_back("act");
	svec.push_back("dog");
	svec.push_back("god");
	svec.push_back("cat");
	svec.push_back("mad");
	svec.push_back("man");
	svec.push_back("dam");
	svec.push_back("dgo");
	svec.push_back("pen");
	cout<<"Dictionary is "<<endl;
	for(int i=0;i<svec.size();i++)
		cout<<svec[i]<<" ";
	cout<<endl;
	find_anagrams(svec);
	auto m="kanhaiya";
	auto r=m;
	cout<<"r="<<r<<endl;
	return 0;
}
