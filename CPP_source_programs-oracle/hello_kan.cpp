#include<iostream>
using namespace std;

void printAllBut2(int& num)
{
	cout<<"passing const int, declared int"<<endl;
	
}

int main()
{
	int num=10;
	printAllBut2(num);
	return 0;
}
