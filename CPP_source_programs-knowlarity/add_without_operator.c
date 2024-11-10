#include<iostream>
using namespace std;

int add_without_operator(int x,int y)
{
	while(y>0)
	{
		int carry=x&y;
		x=x^y;
		y=carry<<1;
	}
	return x;
}

int main()
{
	int x,y;
	cout<<"x and y:"<<"\t";
	cin>>x>>y;
	int res=add_without_operator(x,y);
	cout<<"res="<<res<<endl;
	return 0;
}
	
