#include<iostream>
using namespace std;

int check_div(int num,int div)
{
	int **state=new int*[div];
	for(int i=0;i<div;i++)
	{
		state[i]=new int[2];
		state[i][0]=(2*i)%div;
		state[i][1]=(2*i+1)%div;
		//cout<<"state["<<i<<"]["<<0<<"]="<<state[i][0]<<endl;
		//cout<<"state["<<i<<"]["<<1<<"]="<<state[i][1]<<endl;
	}
	int curstate=0;		//start with state 0
	int dig=0;
	int num1=num;
	while(num1>0)
	{
		num1>>=1;
		dig++;
	}
	for(int i=dig-1;i>=0;i--)
	{
		//int p=(num&(1<<i))>>i;
		//cout<<"i="<<i<<" and curstate="<<curstate<<" and next digit is "<<p<<endl;
		curstate=state[curstate][(num&(1<<i))>>i];
	}
	//cout<<"curstate="<<curstate<<endl;
	if(curstate) 
	{
		cout<<num<<" is not divisible by "<<div<<endl;
		cout<<"Remainder is "<<curstate<<endl;
	}
	else
		cout<<num<<" is divisible by "<<div<<endl;
	return 0;
}

int find_quotient(int num,int div)
{
	int temp=num;
	int quot=0;
	while(temp>div)
	{
		quot++;
		temp-=div;
	}
	cout<<"quotient after dividing "<<num<<" by "<<div<<" is "<<quot<<endl;
	return 0;
}

int main()
{
	int num,div;
	cout<<"Enter number"<<endl;
	cin>>num;
	cout<<"Enter divisor"<<endl;
	cin>>div;
	check_div(num,div);
	find_quotient(num,div);
	return 0;
	
}
