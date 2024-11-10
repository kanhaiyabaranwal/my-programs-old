#include<iostream>
using namespace std;
auto l = [] {
std::cout << "hello lambda" << std::endl;
};

int main()
{
	l();
	// prints ‘‘hello lambda’’
	return 0;
}
	
