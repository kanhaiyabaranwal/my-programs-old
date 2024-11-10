#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string IntToShortenedURL(int num)
{
	char map[]="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	string shortURL;
	cout<<"num to sURL:"<<endl;
	while(num)
	{
		cout<<"Char to push is "<<map[num%62]<<endl;
		shortURL.push_back(map[num%62]);
		num/=62;
	}
	cout<<"sURL[0]="<<shortURL[0]<<endl;
	reverse(shortURL.begin(),shortURL.end());
	cout<<"After reversal sURL[0]="<<shortURL[0]<<endl;
	return shortURL;
}
int ShortenedURLToInt(string sURL)
{
	int num=0;
	cout<<"sURL to num:"<<endl;
	for(int i=0;i<sURL.length();i++)
	{
		cout<<"Next char is "<<sURL[i]<<endl;
		if(sURL[i]>='a' && sURL[i] <='z')
			num=num*62+(sURL[i]-'a');
		if(sURL[i]>='A' && sURL[i] <='Z')
			num=num*62+(sURL[i]-'A'+26);
		if(sURL[i]>='0' && sURL[i] <='9')
			num=num*62+(sURL[i]-'0'+52);
		cout<<"Num is :"<<num<<endl;
	}
	return num;
}

int main()
{
	
	int num=37492832;
	cout<<"Number is "<<num<<endl;

	string sURL=IntToShortenedURL(num);			
	cout<<"Shortened URL created is "<<sURL<<endl;
	cout<<"Number obtained back is "<<ShortenedURLToInt(sURL)<<endl;
	return 0;
}
