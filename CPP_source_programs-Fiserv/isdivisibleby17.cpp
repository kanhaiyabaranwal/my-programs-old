//Use bit operators to check if a number is divisible by 17 or not
#include<iostream>
using namespace std;

int isdiv17(int num)
{
	if(num==0 || num==17)
		return 1;
	if(num<17)
		return 0;
	//number is greater than 17, call isdiv17 for (num/16-n%16)
	return isdiv17((num>>4)-(num&15));
}

int main()
{

	cout<<"numbers divisible by 17 are "<<endl;
	for(int i=1;i<100;i++)
	{
		int n=isdiv17(i);
		if(n)
			cout<<i<<"\t";
	}
	return 0;
}
