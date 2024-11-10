//Problem statement: Consider a row of n coins of values v1 . . . vn, where n is even. We play a game against an opponent by alternating turns. In each turn, a player selects either the first or last coin from the row, removes it from the row permanently, and receives the value of the coin. Determine the maximum possible amount of money we can definitely win if we move first.

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//int coin[]={5,3,7,10};
int coin[]={8,15,3,7};
int optim[4][4];
int max(int x,int y)
{
	return x>y?x:y;
}
int min(int x,int y)
{
	return x<y?x:y;
}
int GameStrategy(int s,int e)
{
	if(s+1==e)
		max(coin[s],coin[e]);
	else if(s>=e)
		return 0;
	if(optim[s][e]>0)
		return optim[s][e];
	//opponent intends to definitely defeat the first mover(f). If f picked s, opponent shall pick either s+1 or e-1 based on the output such that, remaining output is minimum. So if f picked s then, min([s+2,e],[s+1,e-1]).
	optim[s][e]= max(coin[s]+min(GameStrategy(s+2,e),GameStrategy(s+1,e-1)),
		   coin[e]+min(GameStrategy(s+1,e-1),GameStrategy(s,e-2)));
	return optim[s][e];
}
int main()
{
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			optim[i][j]=0;
	int maxVal=GameStrategy(0,3);	
	cout<<"Max Value obtained="<<maxVal<<endl;
	return 0;
}
