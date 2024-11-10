//#define __IBMCPP_TR1__ 1
#include<iostream>
#include<thread>
using namespace std;
//using namespace std::thread;
//using namespace std::tr1;

void hello()
{
	cout<<"Hello World"<<endl;
}

int main()
{
	thread t(hello);
	return 0;
}
