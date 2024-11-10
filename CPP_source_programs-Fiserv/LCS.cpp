//Largest common sequence between two strings
#include<iostream>
#include<cstring>
#include<deque>
#include<algorithm>
#include<iterator>
using namespace std;
//char str1[]="ABCBDACABDCAB";
char str1[]="ABCBDAB";
char str2[]="BDCABA";
static const int len1=7;	//strlen(str1);
static const int len2=6;	//strlen(str2);
int LCS[len1+1][len2+1];

void findNext(int i,int j,deque<char>& q)
{
	//if(LCS[i+1][j]==0 || LCS[i][j+1]==0 || LCS[i+1][j+1]==0)	//terminating condition
	if(LCS[i][j]==0)
	{
		cout<<str1[i]<< " pattern match over\n";
		copy(q.begin(),q.end(),ostream_iterator<char>(cout," "));
		return ;
	}
	int flag=0;
	if(LCS[i+1][j+1]+1== LCS[i][j] && str1[i]==str2[j])		//character matched, print and call further
	{
		//cout<<"Next char is at"<<LCS[i][j]<<"and is "<<str2[j]<<"\t";
		//cout<<str1[i]<<"\t";
		flag=1;
		q.push_back(str1[i]);
		findNext(i+1,j+1,q);
	}
	if(LCS[i+1][j] == LCS[i][j])
	{
		if(flag--)
			q.pop_back();
		findNext(i+1,j,q);
	}
	if(LCS[i][j+1] == LCS[i][j])
	{
		if(flag)
			q.pop_back();
		findNext(i,j+1,q);
	}
	
		
	
}
int largestSequence()
{
	for(int i=0;i<=len1;i++)
		LCS[i][len2]=0;
	for(int j=0;j<=len2;j++)
		LCS[len1][j]=0;
	
	for(int i=len1-1;i>=0;i--)
	{
		for(int j=len2-1;j>=0;j--)
		{
			LCS[i][j]=LCS[i+1][j+1];		//initialize with length of common subsequence leaving current letters
			if(str1[i]==str2[j])			//match found, increase length common subsequence 
				LCS[i][j]++;
			if(LCS[i+1][j] > LCS[i][j])		//if length of string leaving current character from  str1 is larger, update largest value with that
				LCS[i][j]=LCS[i+1][j];		//if length of string leaving current character from  str2 is larger, update largest value with that
			if(LCS[i][j+1] > LCS[i][j])
				LCS[i][j]=LCS[i][j+1];
		}
	}
	
	//print values
	cout<<"LCS Matrix is"<<endl;
	cout<<"  ";
	for(int j=0;j<len2;j++)
		cout<<str2[j]<<" ";
	cout<<endl;
	for(int i=0;i<=len1;i++ )
	{
		cout<<str1[i]<<" ";
		for(int j=0;j<=len2;j++)
		{
			cout<<LCS[i][j]<<" ";
		}
		cout<<endl;
	}

	//finding largest sequence, by traversing diagonally from LCS[0][0] to LCS[len1-1]LCS[len2-1] 
	deque<char> q;
	findNext(0,0,q);
		
	
	/*int i=0;
	int j=0;
	while(i<len1 && j<len2)
	{
		if(LCS[i+1][j+1]<LCS[i][j])
		{
			cout<<LCS[i+1][j+1]<<" character is "<<str1[i]<<endl;
			i++;j++;
			continue;
		}
		if(LCS[i+1][j]<LCS[i][j])
		{
			cout<<LCS[i+1][j]<<" character is "<<str1[i]<<endl;
			i++;
			continue;
		}
		if(LCS[i][j+1]<LCS[i][j])
		{
			cout<<LCS[i][j+1]<<" character is "<<str2[j]<<endl;
			j++;
			continue;
		}
		
	}
	*/
	return LCS[0][0];
}

int main()
{
	cout<<"Program to find largest common sequence in two strings using DP\n";
	//take an additional dummy row and column at the end to start calculating length
	//calculate length of common subsequence from the end to start
	//fill last column and last row with zeros
	int subseq_len=largestSequence();	
	cout<<"Largest subsequence is of length "<<subseq_len<<endl;
	return 0;
	
}

