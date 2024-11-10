#include<iostream>
using namespace std;

int kth_element(int *a,int *b,int index1,int index2,int k)
{
	int ind=0;
	int e=0;	
	int ind1=0,ind2=0;
	while(ind1<=index1 && ind2<=index2)
	{
		if(k==ind)
		{
			if(a[ind1]<=b[ind2])
			{
				cout<<"kth element is "<<a[ind1]<<endl;
				e=a[ind1];
			}
			else
			{
				cout<<"kth element is "<<b[ind2]<<endl;
				e=b[ind2];
			}
			return e;
		}
		
		if(a[ind1]<=b[ind2] && ind1<=index1)
			ind1++;
		else if(ind2<=index2)
			ind2++;
		ind++;
	}
	cout<<"Failed to find kth element"<<endl;
	return -1;
}
int kth_element_recur(int *a,int *b,int k,int start1,int end1,int start2,int end2)
{
	int mid1=start1+((end1-start1)>>2);
	int mid2=start2+((end2-start2)>>2);
	if(k==1)
	{
		if(a[mid1]>b[mid2])
		{
			cout<<"Element found is "<<a[mid1]<<endl;
			return a[mid1];
		}
		else
		{
			cout<<"Element found is "<<b[mid2]<<endl;
			return b[mid2];
		}
	}
	else if(k==0)
	{
		if(a[mid1]<b[mid2])
		{
			cout<<"Element found is "<<a[mid1]<<endl;
			return a[mid1];
		}
		else
		{
			cout<<"Element found is "<<b[mid2]<<endl;
			return b[mid2];
		}
	}
	
	int included;
	if(a[mid1]==b[mid2])
	{
		cout<<"Element found is "<<a[mid1]<<endl;
		return a[mid1];
	}
	if(a[mid1]>b[mid1])
	{
		included=mid2-start2;
		end1=mid1+1;
		start2=mid2;
	}
	else
	{
		included=mid1-start1;
		end2=mid2-1;
		start1=mid1;
	}
	int e=kth_element_recur(a,b,k-included,start1,end1,start2,end2);
	return e;
}
		


int main()
{
	int a[]={2,7,13,19,27,38,51};
	int b[]={5,9,31,43,75,82};
	int k;
	cout<<"Finding kth element,Enter k:";
	cin>>k;
	int sz1=sizeof(a)/sizeof(a[0]), sz2=sizeof(b)/sizeof(b[0]);
	//int e=kth_element(a,b,0,sz1-1,sz-2);
	int e=kth_element(a,b,sz1-1,sz2-1,k-1);
	cout<<"Finding kth element using recursion:"<<endl;
	cout<<"Kth element in order(n) "<<e<<endl;
	e=kth_element_recur(a,b,k-1,0,k-1,0,k-1);
	cout<<"Kth element in order(logn) "<<e<<endl;
	return 0;
}
	
