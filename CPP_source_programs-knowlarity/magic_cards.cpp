#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

void magic_cards ()
{
	int n=5;
	int arr[5];
	arr[0]=1;
	int i=1;
	while(i<n)
	{
		arr[i]=2*arr[i-1];
		//cout<<arr[i]<<",";
		i++;
	}
	cout<<endl;
	
	//take input and show birthday
	i=0;
	int num=0;
	int sum=0;
	//cout<<"Choose cards"<<endl;
	string str;
	std::getline(std::cin, str);
	i=0;
	while(true)
	{
		if(str[i]=='\0')
			break;
		else 
			num=str[i]-48;
		//cout<<"Number is "<<num<<" and add "<<arr[num]<<endl;
		sum+=arr[num];
		i++;
		if(str[i]==' ')
			i++;
	}	
	cout<<sum;
}
int main()
{

	magic_cards ();
	return 0;
}
