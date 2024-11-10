//KMP Pattern matching 
//maintains longest proper suffix table lps[] for each character of the pattern.
//Then Uses lps[] to start search for finding next pattern instead of next character where last search started.
//Naive pattern matching takes o(m(n-m+1)) order. m for traversing each character in the pattern. n-m+1 characters in the string is searched.
//KMP is O(n) since every character in string is traversed once only. lps[] is used to remember longest proper suffix that matches longest proper prefix.

#include<iostream>
#include<cstring>
using namespace std;

int KMPArray(char pat[], int *lps)
{
	lps=new int[strlen(pat)];
	cout<<"pattern len="<<strlen(pat)<<endl;

	char *prevpat=pat;
	char *curpat=pat+1;
	int len=0;
	int i=1;
	lps[0]=0;
	while(pat[i])
	{
		if(pat[i]==pat[len])
		{
			len++;
			lps[i]=len;
			i++;
		}
		else if(len)			 //lps[i] is set to remember largest proper prefix until n	ow
		{
			len=lps[len-1];		
			lps[i]=lps[len];
		}
		else
		{
			lps[i]=0;
			i++;
		}
	}
	for(int i=0;i<strlen(pat);i++)
		cout<<lps[i]<<",";
	cout<<endl;
	return 0;	

}

int pattern_match(char str[],char pat[], int *lps)
{
	int slen=strlen(str);
	int plen=strlen(pat);
	int j=0;
	for(int i=0;i<slen;i++)
	{
		if(str[i]==pat[j])
		{
			if(j==plen)
			{
				cout<<"Pattern found at index "<<i<<endl;
				j=lps[j];
				continue;
			}
			else
				j++;
		}
		else
		{
			j=lps[j];	//continue search from pos lps[j]
		}
	}
	return 0;
}

int main()
{
	cout<<"KMP pattern matching"<<endl;
	char pat[]="ABABCABAB";
	int *lps;
	cout<<"pattern is "<<pat<<endl;
	KMPArray(pat,lps);
	char str[]="ABABDABACDABABCABAB";
	cout<<"caling pattern match now."<<endl;
	pattern_match(str,pat,lps);
	return 0;
}

