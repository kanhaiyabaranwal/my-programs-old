#include<iostream>
#include<string>
#include<stack>
#include<algorithm>
using namespace std;

string int_to_str(int x)
{
	bool is_neg=x<0?true:false;
	x=x<0?-x:x;
	string num;
	while(x>0)
	{
		num.push_back(x%10+'0');
		x/=10;
	}
	if(is_neg)
		num.push_back('-');
	reverse(num.begin(),num.end());
	return num;
}

int str_to_int(string num)
{
	bool is_neg=num[0]=='-'?true:false;
	int x=0;
	for(int i=is_neg;i<num.size();i++)
		x=x*10+(num[i]-'0');
	x=is_neg?-x:x;
	return x;
}

string convert_base(int b1,string num,int b2)
{
	bool is_neg=num[0]=='-'?true:false;
	int x=0;
	//convert to integer number
	for(int i=is_neg;i<num.size();i++)
		x=x*b1+(num[i]>='A'?num[i]-'A'+10:num[i]-'0');
	//x=is_neg?-x:x;
	
	//now convert to base2
	string newnum;
	stack<char> stk;
	while(x>0)
	{
		stk.push(x%b2>9?x%b2-10+'A': x%b2+'0');
		//newnum.push_back(x%b2>9?x%b2-10+'A': x%b2+'0');
		x/=b2;
	}
	if(is_neg)
		stk.push('-');
		//newnum.push_back('-');
	//reverse(newnum.begin(),newnum.end());
	while(stk.size())
	{
		newnum.push_back(stk.top());
		stk.pop();
	}
	return newnum;	
	
}

int main()
{
	int num;
	cout<<"converts integer number to string: Enter number"<<endl;
	cin>>num;
	string s=int_to_str(num);
	cout<<"Converted string is "<<s<<endl;
	cout<<"Conveting back to integer number"<<endl;
	num=str_to_int(s);
	cout<<"Converted number is "<<num<<endl;
	cout<<"converting from one base to another base:"<<endl;
	int b1,b2;
	cout<<"Enter base1:";
	cin>>b1;
	cout<<"Enter base2:";
	cin>>b2;
	cout<<"Enter number:";
	cin>>s;
	string news=convert_base(b1,s,b2);
	cout<<"Converted string is "<<news<<endl;
	return 0;
	
}
