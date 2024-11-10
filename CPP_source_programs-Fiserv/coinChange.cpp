//Coin change- Given possible different coins with infinite supply of each of them, find number of possible combinations to achieve an amount.
//Example-coins are 1,2,3. Sum required=4, Possible combinations are {1,1,1,1},{1,1,2},{2,2},{1,3}. Output is 4.
#include<iostream>
using namespace std;
#define NBR_OF_SOLUTIONS 4
int S[]={2,5,3,6};
//int S[]={1,2,3};

//Returns possible number of coin changes for value SumRequired from N combinations of coins
int NbrCoinChange(int SumRequired, int N)
{
	if(SumRequired<=0 || N==0)
		return 0;
	int n=0;	//number of coins of Nth coin to calculate SumRequired
	int tcount=0;	//total count of possible combinations
	int newSumRequired=0;
	int count=0;
	while(n*S[N-1] <= SumRequired)
	{
		newSumRequired=SumRequired-n*S[N-1];
		if(newSumRequired==0)				//one combo found
		{
			tcount++;
			break;
		}
		else						//find count of possible new sum
		{
			count=NbrCoinChange(newSumRequired,N-1);	// possible number of coin changes from lesser coins
			tcount+=count;
		}
		n++;
	}
	return tcount;
}

int main()
{
	cout<<"Coin Change Program"<<endl;
	cout<<"Enter Sum Required"<<endl;
	int sumRequired;
	cin>>sumRequired;
	int nbrofDifferentCoins=sizeof(S)/sizeof(S[0]);
	cout<<"nbrofDifferentCoins="<<nbrofDifferentCoins<<endl;
	if(NBR_OF_SOLUTIONS!=nbrofDifferentCoins)
	{
		cout<<"nbrofDifferentCoins is different from NBR_OF_SOLUTIONS, correct them"<<endl;
		return 0;
	}
	int count=NbrCoinChange(sumRequired,nbrofDifferentCoins);
	cout<<"Possible combinations="<<count<<endl;
	return 0;
}
