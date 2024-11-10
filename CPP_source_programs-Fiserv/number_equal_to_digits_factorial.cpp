#include<iostream>
using namespace std;

int fact(int n)
{
	if(n==0 || n==1)
		return 1;
	return n*fact(n-1);
}

int number_equal_to_digits_factorial()
{
	for(int i=1;i<10;i++)
		for(int j=0;j<10;j++)
			for(int k=0;k<10;k++)
				if(100*i+10*j+k ==fact(i)+fact(j)+fact(k))
					cout<<"Number found:"<<100*i+10*j+k<<endl;
	return 0;
}

int main()
{
	cout<<"number_equal_to_digits_factorial"<<endl;
	number_equal_to_digits_factorial();
	return 0;
}
