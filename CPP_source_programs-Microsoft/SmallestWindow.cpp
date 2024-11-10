#include<iostream>
#include<string>
#include<vector>
#include<set>
using namespace std;
//Find the number of occurences of pattern in a string

int NumberOfOccurencesOfPattern(string str, string pat)
{
	int has_pat[26]={0};
	int has_str[26]={0};
	for(int i=0;i<pat.length();i++)
		has_pat[pat[i]-'a']++;
	
	int count=0,total_count=0;
	int start_index=-1;
	for(int i=0;i<str.length();i++)
	{
		if(has_pat[str[i]-'a']!=0)
		{
			has_str[str[i]-'a']++;
			count++;
			if(start_index==-1)
				start_index=i;
		}
		
		if(count>=pat.length() && (total_count==0 || (start_index!=-1 && str[i]==str[start_index])) )
		{
			cout<<"count="<<count<<";Pattern found starting from "<<start_index <<" to "<<i<<endl;
			//count--;	
			//condition for finding another pattern
			
			if(start_index!=-1 && str[i]==str[start_index])
			{
				int j=start_index+1;
				while(j<i)
				{
					if(has_str[str[j]-'a']>has_pat[str[j]-'a'])
					{
						start_index=j;
						has_str[str[j]-'a']--;
						
					}
					j++;	
				}	
				total_count++;
			}
		}
	}
	return 0;
}

int main()
{
	string str="imetopractico";
	string pat="toc";
	NumberOfOccurencesOfPattern(str,pat);
}
