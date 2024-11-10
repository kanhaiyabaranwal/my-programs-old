//Pattern matching using Finite Automata.
//Maintains a list of states in the pattern and updates current state based on next character
#include<iostream>
#include<cstring>
using namespace std;
#define nbr_of_chars 2

//find longest suffix that aligns with longest prefix in the pattern
int FindState(int m,int j,int **state,char *pat)
{
	for(int ns=m;ns>=0;ns--) 
	{
		//newpat=j+97;
		int k=0;
		if(pat[ns]==j+97)	//if character matches, check if matched the whole suffix and prefix
		{
			for(k=ns-1;k>=0;k--)
				if(pat[k]!=pat[m-(ns-k-1)])
					break;
			if(k==-1)		//longest prefix matching suffix found
				return state[ns][j];
		}34
	}
	return 0;
}

int Finite_Automata(char *pat,int **state)
{
	int plen=strlen(pat);
	int lateststate=0;
	for(int i=0;i<=plen;i++)
	{
		cout<<lateststate<<"\t";
		for(int j=0;j<nbr_of_chars;j++)
		{
			if(pat[i]==j+97)	//if pattern found, create another state
			{
				lateststate++;
				state[i][j]=lateststate;
			}
			else
			//find longest prefix that is also suffix to this string+current_character
				state[i][j]=FindState(i-1,j,state,pat);
				cout<<state[i][j]<<"\t";
		}
		cout<<endl;
	}
	return lateststate;
}
int main()
{
	cout<<"Pattern matching using Finite Automata"<<endl;
	//char pat[]="abaabab";
	char pat[]="abaabab";
	cout<<"pattern is "<<pat<<endl;
	//int nbr_of_chars=2;
	int plen=strlen(pat);
	int **state=new int*[plen+1];//[nbr_of_chars];
	
	for(int i=0;i<plen;i++)
		state[i]=new int[nbr_of_chars];
	int lateststate=Finite_Automata(pat,state);
	char str[]="ababaababaabababaabab";
	cout<<"string is "<<str<<endl;
	int slen=strlen(str);
	int curstat=0,nextstat=0;
	for(int i=0;i<slen;i++)
	{	
		curstat=state[curstat][str[i]-97];
		if(curstat==lateststate)
		{
			cout<<"match found at index "<<i<<endl;
			cout<<"String is "<<str+i-plen+1<<endl;
		}
	}
}
