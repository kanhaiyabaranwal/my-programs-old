#include<iostream>
#include<vector>
#include<fstream>
#include <iterator> 
using namespace std;


ifstream dataFile("ints.dat");
istream_iterator<int> x(dataFile);

class A{
	int i;
	int b;
	public:
	
};

int main()
{
	A a;
	A b();
	cout<<"size of a:"<<sizeof(a)<<endl;
	cout<<"size of b:"<<sizeof(b)<<endl;
	return 0;
}
