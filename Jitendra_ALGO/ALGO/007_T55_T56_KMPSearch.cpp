/*
https://www.youtube.com/watch?v=GTJr8OvyEVQ
https://www.youtube.com/watch?v=KG44VoDtsAA
http://www.geeksforgeeks.org/searching-for-patterns-set-2-kmp-algorithm/

Knuth–Morris–Pratt(KMP) Pattern Matching(Substring search)
Knuth–Morris–Pratt(KMP) Pattern Matching(Substring search) Part2

*/
#include <iostream>
using namespace std;

int match(const string& text,const string& pattern)
{
	int pattern_len = pattern.length();
	int text_len = text.length();
	//build longest-prefix-suffix array 
	int* LSP = new int[pattern_len];
	LSP[0] = 0;
	int j=0,i=1;

	while(i < pattern_len)
	{
		while(j>0 && pattern[i] != pattern[j])
		{
			j = LSP[j-1];
		}
		if(pattern[i] == pattern[j])
		{
			LSP[i] = j+1;
			j++;
		}
		else 
		{
			LSP[i] = 0;	
		}
		i++;
	}
	for(int k=0;k<pattern_len;k++)
		cout << LSP[k] << "  ";
	cout<<endl;
	i=0;j=0;
	while(i<text_len)
	{
		while( j>0 && text[i] != pattern[j])
		{
			j = LSP[j-1];
		}
		if(text[i] == pattern[j])
		{
			if( j == pattern_len -1)
				return i-pattern_len+1;
			j++;
		}
		i++;
	}
	return -1; // no match
}

int main_7()
{
	cout << "Maaaaa.......\n";

	//string patten("bcglx");
	//string text("abcbcglx");

	string patten("ABACABACAA");
	string text("ABABAAB");

	cout << "index: " <<match(text,patten) << endl;

	return 0;
}

