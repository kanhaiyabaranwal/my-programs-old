#define __IBMCPP_TR1__ 1
#include<iostream>
#include<stack>
#include<array>
using namespace std;
using namespace std::tr1;


 void transfer(int n, array <stack <int>, 3>& pegs , int from , int to, int use) {
 if (n > 0) {
 transfer(n - 1, pegs , from , use, to);
 pegs[to].push(pegs[from].top());
 pegs[from].pop();
 cout << "Move from peg " << from << " to peg " << to << endl;
 transfer(n - 1, pegs , use, to, from);
 }
 }

void move_tower_hanoi(int n) {
array <stack <int>, 3> pegs;
// Initialize pegs.
for (int i = n; i >= 1; --i) {
pegs[0].push(i);
}
transfer(n, pegs , 0, 1, 2);
}

int main()
{
	/*stack<int> src,aux,dest;
	for(int i=0;i<10;i++)
	{
		src.push(i*2);
	}
	cout<<"Top element "<<src.top()<<endl;
	*/
	move_tower_hanoi(5);
	return 0;
}
	
