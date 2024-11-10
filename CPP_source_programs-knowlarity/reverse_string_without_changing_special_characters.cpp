#include<iostream>
#include<cstring>
using namespace std;

void reverse_string_without_changing_special_characters(char *str)
{
	char *ptr=str;
	int len=strlen(str);
	char *eptr=str+len-1;
	while(ptr<eptr)
	{
		cout<<"*ptr="<<*ptr<<" and "<<"*eptr="<<*eptr<<endl;
		if(!(*ptr>='A' && *ptr<='Z') && !(*ptr>='a' && *ptr<='z') && !(*ptr>='0' && *ptr<='9'))
		{
			cout<<"increasting ptr"<<endl;
			ptr++;
			continue;
		}			
		if(!(*eptr>='A' && *eptr<='Z') && !(*eptr>='a' && *eptr<='z') && !(*eptr>='0' && *eptr<='9'))
		{
			cout<<"increasting eptr"<<endl;
			eptr--;
			continue;
		}
		{
			cout<<"swapping ptr and  eptr"<<endl;
			char temp=*ptr;	
			*ptr=*eptr;
			*eptr=temp;
			ptr++,eptr--;
		}
	}
	cout<<"changed string:"<<str<<endl;
}


int main()
{
	char str[]="Ab,c,de!$";
	cout<<"string before:"<<str<<endl;
	reverse_string_without_changing_special_characters(str);
	cout<<"string after:"<<str<<endl;
	return 0;
}

