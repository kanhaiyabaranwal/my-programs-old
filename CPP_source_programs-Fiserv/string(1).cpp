#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

string print(void)
{
	return "Kanhaiya";
}
int main()
{
	const string &s = print();
	//printf("s=%s\n",s.c_str());
	cout<<"string="<<s<<endl;
	string s1("Baranwal");
	cout<<"string="<<s1<<endl;
	
	return 0;
}
	
