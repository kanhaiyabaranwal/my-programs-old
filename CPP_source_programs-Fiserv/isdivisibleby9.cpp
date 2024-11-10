//Use bit operators to check if a number is divisible by 9 or not
#include<iostream>
using namespace std;

int isdiv9(int num)
{
	if(num==0 || num==9)
		return 1;
	if(num<9)
		return 0;
	//number is greater than 9, call isdiv9 for (num/8-n%8)
	return isdiv9((num>>3)-(num&7));
}

int main()
{

	cout<<"numbers divisible by 9 are "<<endl;
	for(int i=1;i<100;i++)
	{
		int n=isdiv9(i);
		if(n)
			cout<<i<<"\t";
	}
	return 0;
}
