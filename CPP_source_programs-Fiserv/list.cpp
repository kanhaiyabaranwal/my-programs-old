//Write a program to take a file containing first names. print them ascending order.
#include<iostream>
#include<string>
#include<list>
#include<fstream>
using namespace std;

int main()
{
	list<string> slist;
	ifstream in;
	in.open("name.lst");
	string name;
	//in>>name;
	//cout<<"string is "<<name<<endl;
	while( in>>name )
	{
		slist.push_back(name);
	}
	list<string>::const_iterator iter=slist.begin();
	cout<<"the list is\n";
	while(iter!=slist.end())
	{
		cout<<*iter<<"\t";
		iter++;
	}
	return 0;	
}
