//Calculates minimum number of operations required to edit string str1 to make string str2
#include<iostream>
using namespace std;
#define M 3
#define N 3


//Top-down approach of memoization
char str1[M+1];	//="xyz";
char str2[N+1];	//="abc";
int editDist[M+1][N+1];

int min(int x,int y)
{
	return x<y?x:y;
}	

int edit_dist(int m,int n)
{
	int min_dist=0;
	cout<<"calling for "<<str1[m-1]<<" and "<<str2[n-1]<<endl;
	if(m==0)
	{
		min_dist=n;
		cout<<"str1 is of 0 length and str2 length="<<n<<endl;
	}
	else if(n==0)
	{
		min_dist=m;
		cout<<"str2 is of 0 length and str1 length="<<m<<endl;
	}
	else if(editDist[m-1][n-1]>0)	//return memoized value if present
	{
		min_dist=editDist[m-1][n-1];
		cout<<"Solution from memoization:min_dist at ["<<m-1<<"]["<<n-1<<"]="<<min_dist<<endl;
	}	
	else if(str1[m-1]==str2[n-1])
	{
		cout<<"str1 and str2 matches at "<<str1[m-1]<<" and "<<str2[n-1]<<endl;
		min_dist=edit_dist(m-1,n-1);
	}
	else
	{
		cout<<"Finding min of insertion, removal and deletion\n";
		min_dist=1+min(min(edit_dist(m,n-1),edit_dist(m-1,n)),edit_dist(m-1,n-1));
	}
	editDist[m-1][n-1]=min_dist;	//memoize
	cout<<"m="<<m<<",n="<<n<<",min_dist="<<min_dist<<endl;
	return min_dist;
}
	
	


int main()
{
	for(int i=0;i<=M;i++)
		for(int j=0;j<=N;j++)
			editDist[i][j]=0;
	cout<<"Enter str1 and str2 ";
	cin>>str1>>str2;
	cout<<"str1="<<str1<<" and str2="<<str2<<endl;

	cout<<"min edit distance required to convert "<<str1<<" to "<<str2 <<" = "<<edit_dist(M,N)<<endl;
	return 0;
}	
