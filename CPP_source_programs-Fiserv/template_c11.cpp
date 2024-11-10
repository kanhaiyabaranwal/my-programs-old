#include<iostream>
using namespace std;

void print ()
{
}
template <typename T, typename... Types>
void print (const T& firstArg, const Types&... args)
{
std::cout << firstArg << std::endl; // print first argument
print(args...); // call print() for remaining arguments
}


int main()
{
	print(43,"kanhaiya",4.6,'e');
	return 0;
}
