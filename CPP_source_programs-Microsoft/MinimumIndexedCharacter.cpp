#include<iostream>
#include<unordered_map>

using namespace std;

void MinimumIndexedCharacter(string str, string patt)
{
	unordered_map<char,int> umap;
	for(int i=0;i<str.length();i++)
	{
		if(umap.find(str[i])==umap.end())
		umap[str[i]]=i;
	}

	for(int i=0;i<patt.length();i++)
	{
		if(umap.find(patt[i])!=umap.end())
		{
			cout<<"first character from patt "<<patt<<" found in string "<<str<<" is "<<patt[i]<<" and found at "<<umap[patt[i]]<<endl;
			return;
		}
	}
	cout<<"No character in pattern "<<patt<<" found in string "<<str<<endl;
}

int main()
{
	string str="kanhaiya baranwal";
	string patt="saanvi";
	MinimumIndexedCharacter(str, patt);
	return 0;
}
