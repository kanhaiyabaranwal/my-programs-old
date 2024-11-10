//Arithmetic Operations on large numbers
#include<iostream>
#include<string>
#include<cstring>
#include<stack>
using namespace std;

char* make_equal_lenth(char* num1,char *num2)
{
	int len1=strlen(num1);
	int len2=strlen(num2);
	int diff,len;
	char *p1;
	if(len1<len2)
	{
		diff=len2-len1;
		len=len2;
		p1=num1;			//number with smaller length
		
	}
	else
	{
		diff=len1-len2;
		len=len1;
		p1=num2;
	}
	char *num3=new char[len];
	//left pad to make strings of equal length
	int i=0;
	for(i=0;i<len;i++)
	{
		if(i<diff)
			num3[i]='0';
		else
			num3[i]=p1[i-diff];
	}
	num3[i]='\0';
	cout<<"num3="<<num3<<endl;
	return num3;
}

char* add(char* num1,char* num2)
{
	cout<<"Addition of numbers "<<num1<<" and "<<num2<<endl;
	stack<int> stk1,stk2;
	char *pch;
	if(strlen(num1)>=strlen(num2))		//keep track of larger number
		pch=num1;
	else
		pch=num2;
	char*num3=make_equal_lenth(num1,num2);		//returns padded string to make 2 strings of equal length
	//create stacks	of characters of equal size
	for(int i=0;i<strlen(num3);i++)
	{
		stk1.push(num3[i]-48);			//padded string
		stk2.push(pch[i]-48);			//larger string
	}
	delete [] num3;						//padded string is not required any more
	stack<int> stk3;
	int carry=0;
	int n1,n2,sum;
	while(stk1.size()>0)		//while stacks have enough size
	{
		
		n1=stk1.top();
		n2=stk2.top();
		sum=n1+n2+carry;
		carry=sum>9?1:0;
		sum=sum>9?sum-10:sum;
		cout<<"Adding "<<stk1.top()<<" and "<<stk2.top()<<",sum="<<sum<<",carry="<<carry<<endl;
		stk3.push(sum);
		stk1.pop();
		stk2.pop();
	}
	if(carry)
		stk3.push(carry);
	cout<<"sum of "<<num1<<" and "<<num2<<" is "<<endl;
	
	char *result=new char[stk3.size()];
	int i=0;
	while(stk3.size()>0)
	{
		result[i++]=stk3.top()+48;
		cout<<stk3.top();
		stk3.pop();
		
	}
	result[i]='\0';
	cout<<endl;
	return result;
}	

int main()
{
	cout<<"operation of large numbers"<<endl;
	char num1[]="123456789";
	char num2[]="987654321";
	char *res=add(num1,num2);
	cout<<"Result returned is "<<res<<endl;
	return 0;
}
