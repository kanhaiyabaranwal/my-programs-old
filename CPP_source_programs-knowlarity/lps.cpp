#include<iostream>
#include<cstring>
using namespace std;

int max(int x,int y)
{
	return x>y?x:y;
}

int LPS(char str[])
{
	int len=strlen(str);
	cout<<"length of string="<<len<<endl;
	int lps[len];	
	int i;
	/*for(i=0;i<len-1;i++)
	{
		if(str[i]==str[i+1])
		{
			lps[i]=lps[i+1]=2;
			i++;
		}
		else
			lps[i]=1;
	}
	if(lps[i]!=2)
		lps[i]=1;
	for(int i=0;i<len;i++)
		cout<<str[i]<<" and minimum lps is "<<lps[i]<<"\n";
	cout<<endl;
	*/
	lps[0]=1;
	for(i=0;i<len-1;i++)
	{
		int j=i-1;
		int k=i+1;
		int sum1=lps[i];
		int sum2=1;
		if(str[i]==str[i+1])	//consider even case first
		{
			k++;	//compare from next character
			sum1=sum2=2;
			while(j>=0 && k< len)
			{
				if(str[j]==str[k])
				{
					sum1+=2;	
					sum2+=2;	
					j--,k++;
				}
				else
					break;
			}
		}
		int sum3=1;		//consider odd case now
		j=i-1;k=i+1;
		while(j>=0 && k<len)
		{
			if(str[j]==str[k])
			{
				sum3+=2;
				j--,k++;
			}
			else
				break;
		}
		lps[i]=	max(max(sum3,sum1),lps[i]);
		lps[i+1]=sum2;	
		cout<<"Position "<<i<<"At character "<<str[i]<<" : lps is "<<lps[i]<<"\n";
	}
	cout<<"Position "<<i<<"At character "<<str[i]<<" : lps is "<<lps[i]<<"\n";
	int max=1;
	cout<<"LPS starting each character are:\n";
	for(int i=0;i<len;i++)
	{
		if(max<lps[i])
			max=lps[i];
	}
	cout<<endl;
	return max;
}

int main()
{
	char str[20];
	cout<<"Enter string:";
	cin>>str;
	int maxlen=LPS(str);
	cout<<"Max len LPS in "<<str<<" is "<<maxlen<<endl;
	return 0;
}

