#include<iostream>
using namespace std;

int operator sizeof(const X& x){
	return std::sizeof(x);
}

int main()
{
	int i=4;
	cout<<"sizeof int="<<sizeof(int)<<", sizeof i="<<sizeof(i)<<endl;
	return 0;
}
