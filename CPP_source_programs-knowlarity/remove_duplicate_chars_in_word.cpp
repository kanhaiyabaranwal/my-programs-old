#include<iostream>
#include<string>
using namespace std;


void remove_duplicate_chars_in_word(string str)
{
	int i=0;
	int track=0;
	cout<<"old str="<<str<<endl;
	while(i<str.length())
	{
		if((1<<(str[i]-'a')) & track)
			str.replace(i,1,"");
		else
			track|=(1<<str[i]-'a');
		i++;
	}
	cout<<"New str="<<str<<endl;
}

int main()
{
	remove_duplicate_chars_in_word("kanhaiya");
	return 0;
}
	
	
