//In-place reversal of a string. 
//space complexity - O(1)
#include<iostream>
using namespace std;

void swap(char *strb,char* stre)
{
	*strb^=*stre;
	*stre^=*strb;
	*strb^=*stre;
}

int main()
{
	char str[]="I am reversible string";
	char *pstrb=str;
	char *pstr=str;
	cout<<"first char="<<*pstrb<<endl;
	char *pstre;
	char ch;
	while(*pstr)
	{
		if(*pstr==' ')
		{
			pstre=pstr-1;
			while(pstrb<pstre)
				swap(*pstrb++,*pstre--);
			while(*pstr==' ')
				pstr++;
			pstrb=pstr;
		}
		else
			pstr++;
	}
	pstre=pstr-1;
	while(pstrb<pstre)
		swap(*pstrb++,*pstre--);
	cout<<"reversed string is "<<str;
	cout<<endl;
	return 0;
}	
