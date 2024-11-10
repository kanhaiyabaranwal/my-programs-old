#include<iostream>
using namespace std;

int move(int x,int y)
{
	static int count;
	if(x==0 && y==0)
	{
		cout<<"reached"<<endl;
		count++; 
		return count;
	}
	if(x>0 )
		move(x-1,y);		//show that this was x move
	if(y>0 )
		move(x,y-1);
	return count;
}

int main()
{
	int x=4,y=3;
	int count=move(x,y);
	cout<<"Possible number of moves="<<count<<endl;
	return 0;
}
