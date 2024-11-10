//Boyer-Moore pattern matching algorithm using bad character heuristics
#include<iostream>
#include<cstring>
using namespace std;
#define CHAR_LOWER_BOUND 65
#define CHAR_UPPER_BOUND 90
#define NBR_OF_CHARS 26

//badchar[] is an array of 26 characters keeps position of last occurence of each character if present, otherwise -1
void preprocess(char *pat,int *badchar)
{
	int plen=strlen(pat);
	for(int i=0;i<NBR_OF_CHARS;i++)
		badchar[i]=-1;
	for(int i=0;i<plen;i++)
		badchar[pat[i]-65]=i;			//keep last position of each character in the pattern. plen[1]=A, badchar[plen[1]-65]=1
	return;
}

int BM_Pattern(char *str, char *pat)
{
	int slen=strlen(str);
	int plen=strlen(pat);
	int badchar[NBR_OF_CHARS];
	preprocess(pat,badchar);
	//travel through the string str starting from index plen-1.
	//If pattern match found, check previous character until index 0. Then say "pattern found".
	int ind=plen-1;
	int s=0;
	int next_start_pos=0;
	while(s<slen-plen+1)	//traverse until last complete pattern can be found 
	{
		int j=ind;
		while(j>=0 && str[s+j]==pat[j])
			j--;
			
		if(j<0)	//match found when j=-1
		{
			cout<<"Match found at "<<str+s<<endl;
			//look for last occurence of next character of string in pattern and move s to align with that
			if(s+plen<slen)		//if next character exists
				s+=plen-badchar[str[s+ind+1]-65];
			else
				s+=1;
		}
		else
		//reached here only when pattern not found, 
		//move to align with last occurence when character not found
		//then search from jth character from new found position of s
		{
			next_start_pos=j-badchar[str[s+j]-65];
			if(s+next_start_pos>=slen)	//reverse increment and then increase by 1 only
				s+=1;
			else
				s+=next_start_pos;
		}
	}
	return 0;
	
}
int main()
{
	cout<<"Boyer-Moore pattern matching algorithm using bad character heuristics"<<endl;
	char str[]="APABPANATAPANAMNK";
	char pat[]="PANA";
	BM_Pattern(str,pat);
	return 0;
}


