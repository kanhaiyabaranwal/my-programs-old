#include<iostream>
using namespace std;

void square_root(float num)
{
	float y=1;
	float x=num;
	float e=0.00001;
	while(x-y > e)
	{
		x=(x+y)/2;
		y=num/x;
		cout<<"Next x="<<x<<" and y = "<<y<<endl;
	}
	return;
}
	

int main()
{
	float num;
	cout<<"Number? ";
	cin>>num;
	square_root(num);
	return 0;
}
