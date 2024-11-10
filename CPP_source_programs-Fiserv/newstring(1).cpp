#include<iostream>
#include<string>
#include<new>
#include<sstream>
#define NUM_OF_STR 3

using namespace std;

void out_of_mem()
{
	cout<<"out of memory error"<<endl;
	exit(1);
}

int main()
{
	cout<<"enter int"<<endl;
	int n;
	cin>>n;
	//string *str=new string[NUM_OF_STR];
	string *str=new string[n];
	string istr;
	stringstream sstream;
	int i;
	for(i=0;i<n;i++)
	{
		sstream<<i;
		str[i]="kanhaiya"+sstream.str();
		cout<<"str["<<i<<"]="<<str[i]<<" ";
		sstream.flush();
		sstream.str(string());
		sstream.clear();
	}
	sstream<<i;
	int j=0;
	sstream>>j;
	cout<<"final val="<<j<<endl;
	return 0;
}
