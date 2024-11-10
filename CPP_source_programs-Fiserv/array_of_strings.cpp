#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	char str[]="k a n h a";
	int len=strlen(str)+1;
	char *arr[len/2];
	int i=0,j=0;
	while(str[i])
	{
		if(str[i]==' ')
			str[i]='\0';
		else
			arr[j++]=str+i;
		i++;
	}
	cout<<"individual strings are:"<<endl;
	j--;
	while(j>=0)
		cout<<arr[j--]<<endl;
	return 0;
}
		
		
		
