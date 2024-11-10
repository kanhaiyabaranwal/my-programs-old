//print unique characters from end
//space order-O(n), worst case assuming all characters are unique
//time order-O(nlogn), worst case with each character finding take logn in the set(BST) for last characetr, and there are n characters
#include<iostream>
#include<set>
#include<cstring>
using namespace std;

int main()
{
	char str[]="geeks for geeks";
	set<char> cset;
	int len=strlen(str);
	//char *pchar=str[len-1];
	set<char>::const_iterator it;
	for(int i=len-1;i>=0;i--)
	{
		it=cset.find(str[i]);
		if(it==cset.end())
		{
			cout<<"new char found "<<str[i]<<"\n";
			cset.insert(str[i]);
		}
		else
			cout<<str[i]<<" is already present"<<endl;
	}
	return 0;
}
		
	
