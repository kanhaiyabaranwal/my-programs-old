#include<iostream>
using namespace std;

int a[]={1,2,3,4};
int len=sizeof(a)/sizeof(a[0]);
void printUtil(int pos,int ss_len,vector<int>& ivec)
{
	if(len==0)
	{
		for(int i=0;i<ivec.size();i++)
			cout<<ivec[i];
	}
	ivec.push_back(a[pos]);
	for(int i=pos+1;i<ss_len;i++)
	{
		printUtil(i+1,ss_len-1,ivec);
	}
	ivec.pop_back();
}
void print_subsequence ()
{
	for(int i=0;i<len;i++)		//position to start the subsequence
	{
		for(int j=n-i;j>0;j--)	//length of subsequence
		{
			vector<int> ivec;
			printUtil(i,j,ivec);
	}

}
int main()
{

	print_subsequence ();
	return 0;
}
