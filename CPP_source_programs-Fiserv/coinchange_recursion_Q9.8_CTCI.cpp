//Represent value of n cents using coins 25 cents, 10 cents, 5 cents and 1 cents
#include<iostream>
using namespace std;
#define VAL25 25
#define VAL10 10
#define VAL5 5
#define VAL1 1

int coinchange(int amt,int denomin)
{
	static int count;
	int next_denomin=1;
	switch(denomin)
	{
		case VAL25:
			next_denomin=VAL10;
			break;
		case VAL10:
			next_denomin=VAL5;
			break;
		case VAL5:
			next_denomin=VAL1;
			break;
		default:
			cout<<amt<<" "<<denomin<<" coins."<<endl;
			return count++;		
	}
	for(int i=0;i*denomin<=amt;i++)
	{
		cout<<i<<" "<<denomin<<" coins,";
		coinchange(amt-i*denomin,next_denomin);
	}
	return count;
	
}

int main()
{
	cout<<"Enter value in cents";
	int n;
	cin>>n;
	int count=coinchange(n,VAL25);
	cout<<"Number of coin changes="<<count<<endl;
	return 0;
} 
