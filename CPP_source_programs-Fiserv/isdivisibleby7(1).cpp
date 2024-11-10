//Use bit operators to check if a number is divisible by 7 or not
#include<iostream>
using namespace std;

int isdiv7(int num)
{
	if(num==0 || num==7)
		return 1;
	if(num<7)
		return 0;
	//number is greater than 7, call isdiv7 for (num/8+n%8)
	return isdiv7((num>>3)+(num&7));
}

int main()
{

	cout<<"numbers divisible by 7 are "<<endl;
	for(int i=1;i<100;i++)
	{
		int n=isdiv7(i);
		if(n)
			cout<<i<<"\t";
	}
	return 0;
}
