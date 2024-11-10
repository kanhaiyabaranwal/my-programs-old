//swap odd and even bits in an integer with as few instructions as possible 
//(e.g., bit 0 and bit! are swapped, bit 2 and bit 3 are swapped, and so on).
#include<iostream>
using namespace std;

int main()
{
	cout<<"swap odd and even bits in an integer with as few instructions as possible."<<endl;
	int m=124334;
	cout<<"m=";
	for(int i=31;i>=0;i--)
	{
		int m1=(m&(1<<i))>>i;
		cout<<m1;
	}
	cout<<endl;
	for(int i=0;m>0 && i<32 ;i+=2)
	{
			if( ((m&(1<<i))>>i)!= ((m&(1<<(i+1)))>>(i+1)))
			m^=(3<<i);
	}
	cout<<"m=";
	for(int i=31;i>=0;i--)
	{
		int m1=(m&(1<<i))>>i;
		cout<<m1;
	}
	cout<<endl;
	return 0;
}
