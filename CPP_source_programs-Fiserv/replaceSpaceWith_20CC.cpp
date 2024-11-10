//replace space with %20
#include<iostream>
using namespace std;

int main()
{
	char str[]="sneha suman baranwal    ";
	char *pc=str;
	bool charfound=0;
	int spacecount=0;
	int endspace=0;
	int slen=0;
	int len=0;
	while(*pc)
	{
		if(*pc==' ')
		{
			spacecount++;		
			endspace++;
		}
		else
		{
			charfound=1;
			endspace=0;
		}
		len++;
		slen++;
		pc++;
	}
	spacecount-=endspace;
	len-=endspace;
	cout<<"space count="<<spacecount<<", slen="<<slen<<", len="<<len<<endl;
	if(slen!=len+spacecount*2)
		cout<<"insufficient space"<<endl;
	int k;
	for(int i=slen-1,k=1;i>=0;i--,k++)
	{
		if(str[len-k]!=' ')
			str[i]=str[len-k];
		else
		{
			str[i--]='0';
			str[i--]='2';
			str[i]='%';
		}
	}
	cout<<"string after change="<<str<<endl;
	
	return 0;
	
}
