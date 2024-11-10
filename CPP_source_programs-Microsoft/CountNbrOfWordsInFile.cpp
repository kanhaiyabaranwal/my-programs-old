#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<unordered_map>
#include<vector>
using namespace std;


void CountOfWords(string fileContent)
{
	unordered_map<string,int> umap;
	string str; 
	vector<string> svec;
	int i=0;
	while(i<=fileContent.length())
	{
		if(i!=fileContent.length() && fileContent[i]!=' ' &&  fileContent[i]!='.' )
			str.append(1,fileContent[i]);
		else
		{
			umap[str]++;
			str.clear();
		}
			
		i++;
	}	
	cout<<"Count of Words in File:"<<endl;
	for(unordered_map<string,int>::const_iterator iter=umap.begin();iter!=umap.end();iter++)	
		cout<<iter->first<<","<<iter->second<<endl;
}

int main()
{
	string path="D:\oracle backup\study\C++\cpp_project1\c++ source programs-Microsoft";
	string filename="readme.txt";
	const string fullFileName="D:\oracle backup\study\C++\cpp_project1\c++ source programs-Microsoft\readme.txt";
	ifstream ifs("D:\\oracle backup\\study\\C++\\cpp_project1\\c++ source programs-Microsoft\\readme.txt");
	if(ifs.is_open())
	{
		stringstream ss;
		ss<<ifs.rdbuf();
		string fileContent = ss.str();
		CountOfWords(fileContent);
		cout<<"File content is: "<< ss.str();
	}
	else
		cout<<"File is not open";
	return 0;
}
