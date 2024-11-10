#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


void multiply_large_numbers_represented_as_strings()
{
	string num1="654154154151454545415415454",num2="63516561563156316545145146514654";
	string num4=num1,num5=num2;
	reverse(num1.begin(),num1.end());
	reverse(num2.begin(),num2.end());
	string mul;
	int res=0,carry=0;
	string num3;
	int temp,div;
	int k=0;
	int l=0;
	for(int j=0;j<num2.size();j++)
	{
		carry=0;
		k=j;
		for(int i=0;i<num1.size();i++)
		{
			res=((num2[j]-'0')*(num1[i]-'0')+carry);
			
			
			carry=res/10;
			div=res%10;
			cout<<i<<"th run div="<<div<<" and carry="<<carry<<endl;
			if(k<num3.size())
			{
				temp=num3[k]-'0'+div;
				num3[k]=temp%10+'0';
				carry+=temp/10;
			}
			else
				num3.push_back(div+'0');
			//cout<<num3[k];
			cout<<i<<"th run num="<<num3[k]<<" and carry="<<carry<<endl;
			k++;
			
		}
		
		if(carry)
			num3.push_back(carry+'0');
		cout<<"Number after iteration "<<l<< " is ";
		for(int j=num3.size()-1;j>=0;j--)
			cout<<num3[j];
		cout<<endl;
	}
	cout<<"Multiplying "<<num4<<" and "<<num5<<"; result=";
	reverse(num3.begin(),num3.end());
	cout<<num3<<endl;
}

int main()
{
	multiply_large_numbers_represented_as_strings();
	return 0;
}
