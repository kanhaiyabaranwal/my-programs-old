#include<iostream>
#include<cstdio>

using namespace std;

int main()
{

	char str[]="154.699999999999991";
	int i=0;
	double amt=0.00;
	int output;
	long long return_amount,return_amount1,return_amount2;
	output=sscanf(str,"%lf%d",&amt,&i);
	printf("amt=%.2lf\n", amt);
	printf("amt without decimal limit=%lf\n", amt);
	printf("i=%d and output=%d\n",i,output);

	return_amount = (long long)(amt * 100.00);
	return_amount1 = (long long)(amt * 10000.00)/100;
	return_amount2 = (long long)(amt * 10000.00);
	printf("ra1=%lld, ra2=%lld, ra3=%lld",return_amount,return_amount1,return_amount2);

	return 0;
}
