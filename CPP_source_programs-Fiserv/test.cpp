#include<iostream>
#include<string>
#include<exception>
using namespace std;

class a{
public:
	int a;
	virtual void sum() {
		printf("sum");
	}
};

class b : public a {
public:
	int b;
	virtual void sum() {
		printf("sum of class b");
	}
};

int main() {
	b aptr;
	a *bptr;
	bptr = &aptr;
	bptr->sum();
	string s("kanhaiya");
	for(int i=0;i<s.length();i++)
		if(i%2==0)
			cout<<s[i]<<"\t";
	return 0;
} 
