//finding anagram.
//a[]="dog" and b="god"
#include<iostream>

using namespace std;

int main()
{
	char str2[]="sskkpp";
	char str1[]="ssssss";
	int l[26];
	for(int i=0;i<26;i++)
		l[i]=0;
	char *ps=str1;
	while(*ps)
		l[*ps++-97]++;
	ps=str2;
	while(*ps)
		if(--l[*ps++-97]<0)
			cout<<str1<<" and "<<str2<<" are not anagrams"<<endl;
			
	cout<<str1<<" and "<<str2<<" are anagrams"<<endl;
	return 0;
}
