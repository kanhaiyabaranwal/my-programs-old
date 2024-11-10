#include<iostream.h>
#include<string.h>
using namespace std;

int main()
{
	char str[]="kanhaiya";
	int len=strlen(str);
	char str1[len];
	char str2[len];
	int newi;
	for(int i=0;i<len;i++)
	{
		str1[i]=str[(i+2)%len];
		str2[i]=str[(len+(i-2))%len];
		//newi=(i+2)%len;
		//cout<<str[newi];
	}
	cout<<"str1="<<str1<<endl;
	cout<<"str2="<<str2<<endl;
	for(int i=0;i<len;i++)
	{
		cout<<str[i];
	}
	cout<<endl;


	string s1("kanhaiya");
	string s2("nhaiyaka");
	string s3=s1.substr(2)+s1.substr(0,1);
	cout<<"s3="<s3<<endl;
	if(s3!=s2)
		cout<<"string did not match";
	return 0;
}

