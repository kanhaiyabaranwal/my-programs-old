#include<iostream>
#include<cstdio>
using namespace std;

// class definition with incomplete static member could be in a header file
class A {
	public:
};

// this needs to be placed in a single translation unit only
//const char A::RECTANGLE[] = "rectangle";

int main()
{
	cout<<"Hello World!"<<endl;
	//int *a=(int*)0x1000;
	//cout<<*a<<endl;
	const char a[]="geeks";
	char *p=(char*)&a;
	printf("%c\n",*&*&*p);
	return 0;
}
