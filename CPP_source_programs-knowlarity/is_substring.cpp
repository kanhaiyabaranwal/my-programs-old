#include<iostream>
#include<string>
#include<cmath>
using namespace std;

void is_substring ()
{
	string s1="bcabcabbc";
	string s2="abca";
	int h1=0,h2=0;
	int len=s2.length();
	int i;
	for(i=0;i<len;i++)
	{
		h2=h2*10+s2[i]-96;
		h1=h1*10+s1[i]-96;
	}
	cout<<"hash of "<<s2<<" is "<<h2<<endl;
	i=0;
	while(i<s1.length()-len)
	{
		cout<<"hash of h1="<<h1<<endl;
		if(h1==h2)
			cout<<"pattern matched at substr "<<s1.substr(i,len)<<endl;
		h1=(h1-(s1[i]-96)*pow(10,len-1))*10+s1[i+len]-96;
		i++;
	}	
	

}
int main()
{

	is_substring ();
	return 0;
}
