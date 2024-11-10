//counting combination of  possible number of steps to reach to step N
#include<iostream>
using namespace std;
#define HEIGHT 35
int steps[HEIGHT];
int steps(int height)
{
	static int nbrofsteps=0;
	if(height==0)
	{
		//cout<<"steps in "<<count<<" steps"<<endl;
		//nbrofsteps++;
		return 1;
	}
	if(height<0)
		return 0;
	
	return steps(height-1)+steps(height-2)+steps(height-3);
}

int main(){
	int step=steps(HEIGHT);	
	cout<<"Nbr of steps possible "<<step<<endl;
	return 0;
}

