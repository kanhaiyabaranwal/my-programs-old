#include<iostream>
using namespace std;
#define N 4

// A wrapper over isSameBSTUtil()
bool isSameBST(int a[], int b[], int n)
{
	int included1[N] {};
	int included2[N] {};
	
	for(int i=0;i<N;i++)
	{
		int j;
		for(j=0;j<N;j++)
			if(b[j]==a[i])
				break;
		int min_ind1,max_ind1,min_ind2,max_ind2;
		min_ind1=max_ind1=i;
		min_ind2=max_ind2=j;
		for(int k=i+1;k<N;k++)
		{
			if(a[k]<a[min_ind1] && !included1[k])
			{
				min_ind1=k;
			}
			if(a[k]>a[max_ind1] && !included1[k])
			{
				max_ind1=k;
			}
		}
		for(int k=j+1;k<N;k++)
		{
			if(b[k]<b[min_ind2] && !included2[k])
			{
				min_ind2=k;
			}
			if(b[k]>b[max_ind2] && !included2[k])
			{
				max_ind2=k;
			}
		}
		if(a[min_ind1]!=b[min_ind2] || a[max_ind1]!=b[max_ind2])
			return false;
		included1[min_ind1]=true;
		included1[max_ind1]=true;
		included2[min_ind2]=true;
		included2[max_ind2]=true;
	}
	return true;
}


// Driver program to test above functions
int main()
{
   //int a[] = {8, 3, 6, 1, 4, 7, 10, 14, 13};
   //int b[] = {8, 10, 14, 3, 6, 4, 1, 7, 13};
   int a[] = {2,4,3,1};
   int b[] = {2,1,4,3};
   int n=sizeof(a)/sizeof(a[0]);
   printf("%s\n", isSameBST(a, b, n)?
             "BSTs are same":"BSTs not same");
   return 0;
}
