#include<iostream>
#include<cstring>
using namespace std;

void func(char *input)
{
	char *str;
	str=(char*)0x876;
	strcpy(str,input);
	cout<<str<<endl;
}

int main()
{
	char str1[]="kanhaiya";
	char str2[3];
	strcpy(str2,str1);
	cout<<str2;
	func(str1);
	return 0;
}
