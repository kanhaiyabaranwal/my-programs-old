#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

void convert_to_ascii()
{
	char str[]="CAR";
	char *word=(char*)(malloc(2*(strlen(str)+1)-1));
	int i=0;
	int j=0;
	while(i<strlen(str))
	{
		
		int asc=(int)str[i];
		cout<<"char="<<str[i]<<",asc="<<asc<<endl;
		char a1=char(asc%10+48);
		char a2=char(asc/10+48);
		cout<<"a1="<<a1<<" and a2="<<a2<<endl;
		word[j++]=a2;
		word[j++]=a1;
		i++;
	}
	word[j]='\0';
	cout<<word<<endl;
}
int main()
{
	convert_to_ascii();
	return 0;
}
		
