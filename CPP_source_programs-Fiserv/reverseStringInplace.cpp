//In-place reversal of a string. 
//space complexity - O(1)
#include<iostream>
using namespace std;

int main()
{
	char str[]="string";
	char *pstrb=str;
	char *pstr=str;
	cout<<"first char="<<*pstrb<<endl;
	char *pstre=pstrb;
	while(*pstre)
		pstre++;
	pstre--;
	char ch;
	while(pstrb<pstre)
	{
		ch=*pstre;
		*pstre=*pstrb;
		*pstrb=ch;
		pstrb++,pstre--;
	}
	cout<<"reversed string is ";
	while(*pstr)
		cout<<*pstr++;
	cout<<endl;
	return 0;
}	
