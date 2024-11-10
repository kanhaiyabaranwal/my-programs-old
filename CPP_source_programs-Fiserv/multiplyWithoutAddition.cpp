#include<iostream>

using namespace std;

int multiply(int x,int y)
{
	if(y==0)
		return 0;
	else if(y>0)
		return x+multiply(x,y-1);
	else 		//if(y<0)
		return -multiply(x,-y);
}
int multiply2(int x,int y)
{
	int res=0;
    while(y>0)
    {
	if(y&1)
		res+=x;
	y>>=1;
	x<<=1;
    }
	return res;
}

int main()
{
	int x=235;
	int y=76;
	int z=x*y;
	cout<<"multiply using * gives "<<z\
	<<" multiply by addition gives "<< multiply2(x,y)<<endl;
	return 0;
}
