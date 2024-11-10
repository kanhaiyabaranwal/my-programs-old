//CTCI_Q7.7.Algorithm to find the kth number such that the only prime factors are 3,5, and 7.
#include<iostream>
#include<cmath>
using namespace std;

int main()
{

	int a=b=c=0;
	int k=0;
	int next3=next5=next7=0;
	while(true)
	{
		next3=pow(3,a+1)*pow(5,b)*pow(7,c);
		next5=pow(3,a)*pow(5,b+1)*pow(7,c);
		next7=pow(3,a)*pow(5,b)*pow(7,c+1);
		if(next3 < next5 && next3 < next7)
		{
			cout<<"next from 3 "<<next3<<endl;
			a++;
		}
		else if(next5 < next3 && next5 < next7)
		{
			cout<<"next from 5 "<<next5<<endl;
			b++;
		}
		else 
		{
			cout<<"next from 7 "<<next7<<endl;
			c++;
		}
		
