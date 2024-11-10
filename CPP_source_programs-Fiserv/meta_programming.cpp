#include<iostream>
using namespace std;

template<int n> 
class printN{
	
	public:
		printN(){
			printN<n-1> p;
			cout<<n<<" ";
		}
		int operator()(){
			return n;
		}
};
template<>
class printN<1>{
	public:
		printN(){
			cout<<1<<" ";
		}
		
};
int main()
{
	printN<100> p;
	return 0;
}
