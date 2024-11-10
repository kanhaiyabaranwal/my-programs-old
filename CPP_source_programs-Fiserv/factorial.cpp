#include<iostream>
using namespace std;

//time - o(n), space - o(1)
int factorial(int n)
{
	int mult=1;				//for factoril(1)=1
	for(int i=2;i<=n;i++)
		mult*=i;
	return mult;
}

int main()
{
	int n,fact;
	cout<<"Factorial calculation method. Enter number"<<endl;
	cin>>n;
	fact=factorial(n);
	cout<<"Factorial value= "<<fact<<endl;
	return 0;
}
