#include<iostream>
using namespace std;


int a[]={1,3,5,9,11,13,19};
int b[]={2,3,7,12,13,20};
int c[]={3,7,13,25};

void inc_min(int* a,int *b,int *c,int &i,int& j,int &k)
{
	if(a[i]<b[j])
	{
		if(a[i]<c[k])
			i++;
		else 
			k++;
	}
	else
	{
		if(b[j]>c[k])
			k++;
		else
			j++;
	}
}

void common_elements_in_three_sorted_arrays()
{
	int m=sizeof(a)/sizeof(a[0]);
	int n=sizeof(b)/sizeof(b[0]);
	int p=sizeof(c)/sizeof(c[0]);

	int i=0,j=0,k=0;
	
	while(i<m && j<n && k<p)	
	{
		if(a[i]==b[j] && b[j]==c[k])	
		{
			cout<<"Common:"<<a[i]<<endl;
			i++,j++,k++;
		}
		inc_min(a,b,c,i,j,k);
	}
}
int main()
{

	common_elements_in_three_sorted_arrays();
	return 0;
}
