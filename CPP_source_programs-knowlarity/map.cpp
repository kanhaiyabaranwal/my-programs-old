#include<iostream>
#include<map>
#include<string>
using namespace std;

int main()
{
	map<string,string> nmap;
	nmap.insert(pair<string,string>("kanhaiya","Baranwal"));
	nmap.insert(pair<string,string>("Sneha","Suman"));
	nmap.insert(pair<string,string>("Saanvi","Baranwal"));
	nmap.insert(make_pair("toshiba","Japan"));
	map<string,string>::const_iterator iter=nmap.begin();
	while(iter!= nmap.end())
	{
		cout<<"first name="<<iter->first<<", last name="<<iter->second<<endl;
		iter++;
	}
	return 0;
}
