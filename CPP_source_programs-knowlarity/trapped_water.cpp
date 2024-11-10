#include<iostream>
using namespace std;

int trapped_water ()
{
	int a[]={0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	int n=sizeof(a)/sizeof(a[0]);
	int t=0;
	for(int i=1;i<n-1;i++)
	{
		int lmax=0,rmax=0,max=0;
		int j=0;
		while(j<i)
		{
			if(a[j]>lmax)
				lmax=a[j];
			j++;
		}
		if(lmax<a[i])
			continue;
		j++;
		while(j<n)
		{
			if(a[j]>rmax)
				rmax=a[j];
			j++;
		}
		if(rmax<a[i])
			continue;
		max=lmax>rmax?rmax:lmax;
		t+=(max-a[i]);
	}
	return t;
}
int main()
{

	cout<<"Trapped water : "<<trapped_water ()<<endl;
	return 0;
}
