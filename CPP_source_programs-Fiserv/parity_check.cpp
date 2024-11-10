#include<iostream>

void parity_check(int n)
{
	int res=0;
	while(n)
	{
		res+=1;
		n&=(n-1);
	}
	std::cout<<"parity result="<<res<<std::endl;
}
		

int main()
{
	int i;
	std::cout<<"Number for parity check\n";
	std::cin>>i;
	parity_check(i);
	return 0;
}
