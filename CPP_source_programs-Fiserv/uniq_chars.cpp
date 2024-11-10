#include<iostream>
using namespace std;

int main()
{
	char str[]="sknfvkn";
	char *ptr=str;
	bool uniq[26];
	long bitcheck=0;
	for(int i=0;i<26;i++)
		uniq[i]=0;
	
	while(*ptr)
	{
		if((bitcheck & (1<<(*ptr-96))) > 0)
			cout<<"dulicate found at "<<*ptr<<endl;
		bitcheck|=1<<(*ptr-96);
		ptr++;
	}
}
