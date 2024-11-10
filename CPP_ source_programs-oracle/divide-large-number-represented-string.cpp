#include<iostream>
#include<vector>
#include<string>
#include<cstdio>
using namespace std;


void divide_large_number_represented_string()
{
	const string str="1248163264128256512";
	int num=125;
	int n=0;
	vector<int> quotient;
	for(int i=0;i<str.size();i++)
	{
		n=n*10+str[i]-'0';
		cout<<n<<endl;
		if(n>=num)
		{
			quotient.push_back(n/num);
			n=n%num;
		}
		else if(quotient.size())
			quotient.push_back(0);
		
	}
	for(int i=0;i<quotient.size();i++)
		cout<<quotient[i];
	cout<<endl;
	return;
}
int main()
{
	divide_large_number_represented_string();
	return 0;
}
