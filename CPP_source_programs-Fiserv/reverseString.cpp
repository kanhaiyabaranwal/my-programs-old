//Reversing a string
#include<iostream>
using namespace std;

int main()
{
	char str[]="sfjlsjlf";
	char *end=str;
	while(*end)
		end++;
	end--;
	char *start=str;
	cout<<"string before change="<<str<<endl;
	while(start<end)
	{
		char ch=*start;
		*start++=*end;
		*end--=ch;
	}
	cout<<"string after change="<<str<<endl;
	return 0;
}
