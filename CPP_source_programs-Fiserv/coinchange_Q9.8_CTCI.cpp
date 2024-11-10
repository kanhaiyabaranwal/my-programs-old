//Represent value of n cents using coins 25 cents, 10 cents, 5 cents and 1 cents
#include<iostream>
using namespace std;
#define VAL25 25
#define VAL10 10
#define VAL5 5
#define VAL1 1

int coinchange(int n)
{
	int count=0;
	for(int i=0;i*VAL25<=n;i++)			//i is coins of 25 cents
	{
		int rest25=n-i*VAL25;
		for(int j=0;j*VAL10<=rest25;j++)
		{
			int rest10=rest25-j*VAL10;
			for(int k=0;k*VAL5<=rest10;k++)
			{
				int rest5=rest10-k*VAL5;
				//for(int l=0;l*VAL1<rest5;l++)
				cout<<"Coin combo->  "<<i<<" 25cents, "<<j<<" 10cents, "<<k<<" 5cent coins, "<<rest5<<" 1 cent coins"<<endl;
				count++;
			}
		}
	} 
	return count;
}

int main()
{
	cout<<"Enter value in cents";
	int n;
	cin>>n;
	int count=coinchange(n);
	cout<<"Number of coin changes="<<count<<endl;
	return 0;
} 
