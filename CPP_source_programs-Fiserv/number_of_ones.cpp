#include<iostream>
using namespace std;

int main()
{
	cout<<"Count of 1s in the number"<<endl;
	cout<<"Enter number"<<endl;
	int x;
	cin>>x;
	int count=0;
	while(x)
	{
		x&=(x-1);
		count++;
	}
	cout<<"Number of 1s is "<<count;
	return 0;
}
