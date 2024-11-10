#include<iostream>
#include<string>
using namespace std;

//WAP 

int main()
{
	string q1("When lilacs last in the dooryard bloom'd");
	string q2("The child is father of the man");
	string sentence("The child is in the dooryard");
	string::size_type pos=q2.find_first_of("f");
	int len=q2.length();
	cout<<q1[pos]<<endl;
	q2.erase(pos,len);
	string::size_type sz=q1.find("in");
	q2.append(q1.substr(sz));
	q2.erase(q2.find("bloom"),q2.length());
	cout<<"q2="<<q2<<endl;
	return 0;
	
}
