#include<iostream>
using namespace std;

int main()
{
	int a[]={2,3,4,5,7,9,10,12,24,25,26,29};
	int sz=sizeof(a)/sizeof(a[0]);
	for(int i=0;i<sz;i++)
	{
		a[i]*=a[i];
		cout<<a[i]<<"\t";
	}
	for(int i=sz-1;i>=0;i--)
	{
		int j=0,k=i-1;
		while(j<k)
		{
			if(a[j]+a[k]>a[i])
				k--;
			else if(a[j]+a[k]<a[i])
				j++;
			else
			{
				cout<<"Pythagorean Triplet found "<<a[j]<<","<<a[k]<<","<<a[i]<<endl;
				break;
			}
		}
	}
	cout<<endl;
	return 0;	
		
}
