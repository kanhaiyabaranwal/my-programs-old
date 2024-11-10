#include<iostream>
#include<string>
using namespace std;

int main()
{
	string str1="WaterBottle";
	string str3=str1+str1;
	string str2="erBottleWat";
	if((str3).find(str2)!=string::npos)
		cout<<"string found at position "<<str3.find(str2)<<endl;
	else
		cout<<"string is not rotation"<<endl;
	return 0;
}
