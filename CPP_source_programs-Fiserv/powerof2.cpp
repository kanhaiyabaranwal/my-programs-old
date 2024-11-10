#include<iostream>
using namespace std;

int main()
{
	int n;
	cout<<"enter number for identification of power of 2\n";
	cin>>n;
	int k,l;
	k=n;
	while(k)
	{
		l=k&1;
		k>>=1;
		if(l && !k )		//if k is 1 and rest of bits is 0, then power of 2.
		{
			cout<<"Power of 2 found\n";
			break;
		}	
		if(l && k)
		{
			cout<<"Not Power of 2\n";
			break;
		}
	}
	return 0;
	
}
