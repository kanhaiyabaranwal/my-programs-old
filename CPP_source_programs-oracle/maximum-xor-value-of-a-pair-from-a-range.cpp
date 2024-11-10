#include<iostream>

using namespace std;

int maximum_xor_value_of_a_pair_from_a_range()
{
	int L=19,R=39;
	int xor1=L^R;
	int msb=0;
	while(xor1)
	{
		xor1>>=1;
		msb++;
	}
	int num=1;
	
	while(--msb)
	{
		num=(num<<1)+1;
		//msb--;
	}
	cout<<"max xor number is "<<num<<endl;
	return num;
}

int main()
{
	maximum_xor_value_of_a_pair_from_a_range();
	return 0;
}
