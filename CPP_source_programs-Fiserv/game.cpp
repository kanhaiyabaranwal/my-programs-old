#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

int main()
{
	int tot=23;
	int turn=1;	//1 means player 1, 0 is player 2
	srand(time(NULL));
	int count=0;
	while(tot>4)
	{
		int pick=rand()%4+1;
		tot-=pick;
		turn=!turn;
		count++;
		cout<<"turn of "<<turn<<". Count is "<<count<<". Total is"<<tot<<endl;
	}
	turn=!turn;
	cout<<"player "<<turn<<" won in "<<count/2<<"turns"<<endl;
	return 0;
}
		
		

