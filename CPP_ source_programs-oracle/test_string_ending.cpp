#include<iostream>
#include<string>

using namespace std;

void printchar(string str)
{
	int i=str.length()-1;
	if(i<0)
	{
		cout<<"end found"<<endl;
		return;
	}
	cout<<"next char is "<<str[0]<<endl;
	cout<<"substr is "<<str.substr(1)<<endl;
	printchar(str.substr(1));
	
}

int main()
{
	string str="kan";
	printchar(str);
	return 0;
	
}
