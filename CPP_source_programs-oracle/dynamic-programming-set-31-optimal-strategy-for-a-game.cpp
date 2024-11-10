#include<iostream>

using namespace std;
#define N 4

dynamic_programming_set_31_optimal_strategy_for_a_game()
{
	//output should be 102
	int a[]={5,100,90,2};
	int winner[N][N];
	int loser[N][N];
	
	for(int i=0;i<N;i++)
	{
		winner[i][i]=a[i];
		loser[i][i]=0;
	}
	
	for(int diff=1;diff<N;diff++)
	{
		for(int i=0;i<N-diff;i++)
		{
			int upper=i+diff;
			
			int score1=a[i]+loser[i+1][upper];
			int score2=a[upper]+loser[i][upper-1];
			
			winner[i][upper]=max(score1,score2);
			//loser gets the left over value, if winner picked ith, then loser gets winner of i+1,upper and so on.
			loser[i][upper]= score1 > score2 ? winner[i+1][upper] : winner[i][upper-1];
		}
	}
	cout<<"max_score="<<winner[0][N-1]<<endl;
}

int main()
{
	
	dynamic_programming_set_31_optimal_strategy_for_a_game();
	
	return 0;
}

