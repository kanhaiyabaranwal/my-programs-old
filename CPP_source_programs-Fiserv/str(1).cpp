#include<iostream>
using namespace std;

int main()
{
	char str[]="My name is Kanhaiya";
	char rtr[80];
	strcpy(rtr,"start again");
	sprintf(rtr,"%s and %s",rtr,str);
	cout<< rtr<<endl;
	return 0;
	char *p=str;
	char *w=p;
	int count=1;
	while(*p!='\n' && *p!=NULL)
	{
		if(*p==' ')
		{ 
			*p=NULL;
			cout<<w<<endl;
			count++;
			w=p+1;
		}
		p++;
	}
	cout<<w<<endl;
	cout<<"no. of words="<<count<<endl;
	return 0;
}
