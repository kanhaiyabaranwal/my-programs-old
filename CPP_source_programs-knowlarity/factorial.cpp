#include<iostream>
#include<climits>
using namespace std;

void multiply(int num,int* num2,int& sz)
{
	int i=0,carry=0;
	int sum=0;
	while(i<sz)
	{
		sum=num2[i]*num+carry;
		num2[i]=sum%10;
		carry=sum/10;
		//cout<<"prod="<<sum<<" and carry="<<carry<<endl;
		i++;
	}
	while(carry)
	{
		num2[i++]=carry%10;
		carry/=10;
		//cout<<"prod="<<sum<<" and carry="<<carry<<endl;
	}
	sz=i;
}
	


void factorial(int n)
{
	int* res=new int[INT_MAX];
	res[0]=1;
	int sz=1;
	for(int i=2;i<=n;i++)
	{
		//cout<<"multiplying with "<<i<<endl;
		multiply(i,res,sz);
	}
	cout<<"Factorial(5)=";
	for(int i=sz;i>=0;i--)
		cout<<res[i];
	cout<<endl;
}
void factorial1(int n)
{
	int fact=1;
	for(int i=2;i<=n;i++)
		fact*=i;
	cout<<"Factorial("<<n<<")="<<fact<<endl;
}
int main()
{
	int n;
	cout<<"Enter number:";
	cin>>n;
	cout<<"Factorial by Method# 1"<<endl;
	factorial(n);
	cout<<"Factorial by Method# 2"<<endl;
	factorial1(n);
	
	return 0;
}
