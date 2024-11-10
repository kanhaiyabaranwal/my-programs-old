#include<iostream.h>

char * strtok1(char *s,char del)
{
	static char* trail=s;
	int len=strlen(trail);
	char *ns=new char[len];
	cout<<"len="<<len<<",*ns="<<*ns<<endl;
	cout<<"sizeof ns="<<sizeof(ns)<<endl;
	int i=0;
	while(*trail!='\0')
	{
		if(*trail!=del)
			ns[i]=*trail;
		else
			break;
		trail++;
		i++;
	}
	trail++;
	ns[i]='\0';
	return ns;
}
int main()
{
	char s[]="kanhaiya";
	char *tok=strtok1(s,'a');
	cout<<"token="<<tok<<endl;
	tok=strtok1(NULL,'a');
	cout<<"toke1n="<<tok<<endl;
	tok=strtok1(NULL,'a');
	cout<<"toke2n="<<tok<<endl;
	return 0;
}
