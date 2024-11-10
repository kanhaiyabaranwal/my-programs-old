//finding longest common subsequence using brute force
#include<iostream>
#include<cstring>
using namespace std;
#define LEN1 7
#define LEN2 6

inline int max(int a,int b)
{
	return a>b?a:b;
}

//Use memoization to remeber a sub-optimal solution
int lcs(char* str1,char* str2,const int len1,const int len2)
{
	static int LCS[LEN1][LEN2];
	if(len1<0 || len2<0)
		return 0;
	if(LCS[len1][len2]>0)	
		return LCS[len1][len2];
	int res;
	if(str1[len1]==str2[len2])
		res=lcs(str1,str2,len1-1,len2-1)+1;
	else
		res=max(lcs(str1,str2,len1-1,len2),lcs(str1,str2,len1,len2-1));
	LCS[len1][len2]=res;
	return res;
}

int main()
{
	char str1[]="ABCBDAB";
	char str2[]="BDCABA";
	int len1=strlen(str1);
	int len2=strlen(str2);
	cout<<"Program to find longest common subsequence"<<endl;
	int l=lcs(str1,str2,len1-1,len2-1);
	cout<<"Longest subsequence is of length "<<l<<endl;
	return 0;
}	
