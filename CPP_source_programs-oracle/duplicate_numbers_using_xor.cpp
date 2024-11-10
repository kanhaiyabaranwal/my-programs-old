#include<iostream>
using namespace std;

void duplicate(int *a, int sz)
{
	int n=sz-2;
	int xor1=0,xor2=0;
	for(int i=0;i<sz;i++)
	{
		xor1^=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		xor2^=i;
	}
	int xor5=xor1^xor2;
	int set_bit=xor5 & (~(xor5-1));
	cout<<"set bit:"<<set_bit<<endl;
	int xor3=0,xor4=0;
	xor1=0,xor2=0;
	
	for(int i=0;i<sz;i++)
	{
		if(a[i] & set_bit )
			xor1^=a[i];
		else
			xor2^=a[i];
	}
	
	cout<<"xor1:"<<xor1<<", xor2:"<<xor2<<endl;
	for(int i=1;i<=n;i++)
	{
		if(i & set_bit )
			xor3^=i;
		else
			xor4^=i;
	}
	cout<<"xor3:"<<xor3<<", xor4:"<<xor4<<endl;	
	int res1=xor1^xor3;
	int res2=xor2^xor4;
	cout<<res1<<" "<<res2<<endl;
	
}

int main()
{
	int arr[]={1,2,3,3,4,4,5,6};
	duplicate(arr,8);
	return 0;
}
