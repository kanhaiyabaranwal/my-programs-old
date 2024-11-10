#include<iostream>
using namespace std;

int main()
{

	float mtrx=1.1;
	char *ptr = (char*)(& mtrx);
	cout<<"*ptr="<<*ptr<<endl;
	cout<<"*(ptr+1)="<<*(ptr+1)<<endl;
	cout<<"*(ptr+2)="<<*(ptr+2)<<endl;
	cout<<"*(ptr+3)="<<*(ptr+3)<<endl;
	return 0;
}
