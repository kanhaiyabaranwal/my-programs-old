#include<iostream>
using namespace std;

void reverse(char *ch,int start,int end)
{
	while(start<end)
	{
		char temp=ch[start];
		ch[start]=ch[end];
		ch[end]=temp;
		start++,end--;
	}
	return;
}	
int reverse_sentence(char* str)
{
	cout<<"sentence is : "<<str<<endl;
	char *ch=str;
	int i=0;
	while(ch[i])
		i++;
	reverse(str,0,i-1);
	//keep initial pointer
	cout<<"Reversed string is :"<<str<<endl;
	int j=i=0;
	do 	
	{
		if(ch[j]==' ' || ch[j]=='\0' )
		{
			if(i<j)
			{
				reverse(ch,i,j-1);
			}
			i=j+1;	
		}
	} while(ch[j++]);
	cout<<"Sentence reversed word wise is : "<<ch<<endl;
	return 0;
}
int main()
{
	char str[]="cat likes dog";
	reverse_sentence(str);
	return 0;
}
			
			
