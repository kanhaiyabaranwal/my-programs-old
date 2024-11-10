#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	string str="234296313692432";
	string half_str=str.substr(0,str.length()/2);
	cout<<"str="<<str<<"\t half_str="<<half_str<<endl;
	int n=half_str.length()-1;
	string::iterator iter=half_str.end();
	iter--;
	while(n>0)
	{
		//cout<<"n="<<n<<"\t";
		//cout<<"half_str[n-1]="<<half_str[n-1]<<" and half_str[n]="<<half_str[n]<<endl;
		if(half_str[n-1]<half_str[n])
			break;
		n--;
		iter--;
	}
	//const_iterator<string> iter=half_str.end();
	sort(iter,half_str.end());
	cout<<"sorted string is ";
	cout<<"Pivot digit is "<<half_str[n-1]<<endl;
	for(string::iterator it=iter;it!= half_str.end(); it++)
	{
		if(*it>half_str[n-1])
		{
			swap(*it,half_str[n-1]);
			sort(it,half_str.end());
			break;
		}
	}
	cout<<"half_str="<<half_str<<endl;
	string first_half=half_str;
	reverse(half_str.begin(),half_str.end());
	if(str.length()|1)
		cout<<first_half<<str[str.length()/2]<<half_str<<endl;
	else
		cout<<first_half<<half_str<<endl;

}
