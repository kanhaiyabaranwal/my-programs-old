#include<iostream>
#include<array>
#include<iterator>
#include<algorithm>
#define NUM 6
using namespace std;



template<int n>
class Factorial{
	public:
	enum {val=n*Factorial<n-1>::val };
};

template<>
class Factorial<0>{
	public:
	enum{ val=1 };
};
int fact[10]={-1};
//array<int,10> fact;

int factorial(int n)
{
	if(!n)
		return fact[n]=1;
	if(fact[n]!=0)
		return fact[n];
	return fact[n]=n*factorial(n-1);
	
}

void uncommon_number()
{
	for(int i=1;i<NUM;i++)
		for(int j=0;j<NUM;j++)
			for(int k=0;k<NUM;k++)
			{
				int num=i*100+j*10+k;
				int facti=fact[i]?fact[i]:factorial(i); 
				int factj=fact[j]?fact[j]:factorial(j);
				int factk=fact[k]?fact[k]:factorial(k) ;
				//int factor=(fact[i]?fact[i]:factorial(i)) + (fact[j]?fact[j]:factorial(j)) + (fact[j]?fact[j]:factorial(j));
				cout<<"num="<<num<<" and factors="<<facti<<","<<factj<<","<<factk<<endl;
				//cout<<"num="<<num<<" and fact="<<factor<<endl;
				if(num==(facti+factj+factk))
				//if(num==factor)
						cout<<"Uncommon number is "<<num<<endl;
			}
}

void assign(int &i)
{
	i=0;
}
int main()
{
	//return n*factorial(n-1);
	cout<<"Kanha"<<endl;
	//for_each(fact.begin(),fact.end(),assign);
	//copy(fact.begin(),fact.end(),ostream_iterator<int> (cout," "));
	for(int i=0;i<10;i++)
	{
		fact[i]=0;
		cout<<fact[i]<<" ";
	}
	uncommon_number();
	//for_each(fact.begin(),fact.end(),factorial);
	cout<<endl;
	for(int i=0;i<10;i++)
	{
		//fact[i]=0;
		cout<<fact[i]<<" ";
	}
	//copy(fact.begin(),fact.end(),ostream_iterator<int> (cout," "));
	//cout<<"factorial(5)="<<Factorial<5>::val<<endl;
	return 0;
} 
