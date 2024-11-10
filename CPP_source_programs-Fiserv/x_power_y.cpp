#include<iostream>
using namespace std;

int x_pow_y(int x,int y=2)
{
	int num=x;
	int res=0;
	int temp=x,temp1=x;
	if(y==1)
		return x;
	for(int i=1;i<y;i++)
	{
		temp1=x;res=0;
		for(int j=0;j<64,temp1>0;j++)
		{
			if(num&(1<<j))
				res+=temp;
			temp<<=1;
			temp1>>=1;
		}
		temp=res;
	}
	return res;
}

int main()
{
	cout<<"Calculate pow(x,y) efficiently:"<<endl;
	int x,y;
	cout<<"Enter x:";
	cin>>x;
	cout<<"Enter y:";
	cin>>y;
	int res=x_pow_y(x,y);	
	cout<<"Result is "<<res<<endl;
	return 0;
}
