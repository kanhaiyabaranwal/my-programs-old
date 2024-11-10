#include<iostream>
#include<stack>
#include<string>
#include<sstream>
using namespace std;

class A{
	
};

int main1()
{
	bool i=1,w=0;
	bool r=i||w;
	bool r1=i^w | i&w ;
	if(r==r1)
		cout<<"same result found"<<endl;
	else
		cout<<"same result not found"<<endl;
	
	
	return 0;
}

int IsBalanced(string str)
{
	stack<char> stk;
	for(int i=0;i<str.length();i++)
	{
		if(str[i]=='(')
			stk.push(str[i]);
		if(str[i]==')')
		{
			if(stk.empty())
				return -1;
			else
				stk.pop();
		}		
	}
	if(stk.empty())
				return 0;
	else
			return -1;
}

int main()
{
	string str1="(234sd(sdf))";
	int out=IsBalanced(str1);
	cout<<"resl="<<out;
	
	string str="kan";
	int i=456;
	char arr[10];
	stringstream ss;
	ss<<i;
	//ss.str();
	//sprintf(arr,"%d",i);
	//str+=string(arr);
	string mystr;
	ss>>mystr;
	str+=mystr;
	cout<<"string is "<<str;
	
	int arr1[]={2,4,5,6,7,8,9,10};
	
	int sz=sizeof(arr1)/sizeof(arr1[0]);
	
	int *even=arr1;
	int *odd=arr1+sz-1;
	cout<<"sz="<<sz<<" , even[0]="<<*even<<" ,odd[sz-1]="<<*odd<<endl;
	//int lower=0,upper=sz-1;
	while(even<odd)
	{
		if(!(*even&1))
			even++;
		if(*odd&1)
			odd--;
		if(*even&1 && !(*odd&1))
		{
			int temp=*odd;
			*odd=*even;
			*even=temp;
			even++,odd--;
		}
	}
	for(int i=0;i<sz;i++)
		cout<<arr1[i]<<" ";
	cout<<endl;
	return 0;
}
