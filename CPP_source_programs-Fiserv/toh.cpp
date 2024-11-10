#define __IBMCPP_TR1__ 1
#include<iostream>
#include<array>
#include<stack>
using namespace std;
using namespace std::tr1;


void transfer(int n,array<stack<int>, 3>& peg, int src, int dest, int aux)
{
	if(n>0)
	{
		transfer(n-1,peg,src,aux,dest);
		cout<<"Move from "<<src<<" to "<<dest<<endl;
		peg[dest].push(peg[src].top());
		peg[src].pop();
		transfer(n-1,peg,aux,dest,src);
	}
}

int toh(int n)
{
	array<stack<int> ,3>  peg;
	for(int i=0;i<n;i++)
		peg[0].push(i*2);
	transfer(n,peg,0,1,2);
	return 0;
}


int main()
{
	cout<<"Tower of Hanoi"<<endl;
	toh(5);
	return 0;
}

