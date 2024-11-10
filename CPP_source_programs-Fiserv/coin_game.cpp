//Puzzle - 23 coins are given and two player are there. anyone can pick 1 to 4 coins at a time.
//One who picks the last coin wins.. Find algo for it.
#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

int coin_game(int n, int p)
{
	int pick=rand()%4+1;
	if(p)
		cout<<"Player 1 picks "<<pick<<" coins"<<endl;
	else
		cout<<"Player 2 picks "<<pick<<" coins"<<endl;
	if(n-pick<=0)
		return p;
	else
		return coin_game(n-pick, !p);
}
int main()
{
	srand(time(NULL));
	int n=23;
	cout<<"Game starts with player 1"<<endl;
	int p=coin_game(n,1);
	cout<<"Player "<<p<<" wins!"<<endl;
	return 0;
}

