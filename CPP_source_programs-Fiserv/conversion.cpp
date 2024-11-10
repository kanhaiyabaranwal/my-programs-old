#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;

struct sVal {
	int val;
};

void (Print)(float f)
{
	cout<<"float valmue is "<<f<<endl;
}
int main()
{
	int p=4;
	Print(p);
	char *pch;
	pch=new char[10];
	strcpy(pch,"How are you");
	cout<<"pch="<<pch<<endl;
	vector<int> vec;
	vector<int>::value_type val;
	cout<<"val="<<val<<endl;
	return 0;
}
