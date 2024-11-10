#include<iostream>
using namespace std;

void equals ()
{

	char str[]="aaabbab";
	char tmp[50];
	int i,j;
	int k=0;
	/*while(k<sizeof(str)) 
	{
		tmp[k]=str[0];
		k++;
	}*/
	//for(i=j=0;j<sizeof(str);j++)
	for(i=j=0,tmp[0]=str[0];tmp[j]=str[0] && j<sizeof(str);j++)
	{
		cout<<"tmp="<<tmp[j]<<" and str="<<str[j]<<endl;
		if(tmp[j]==str[j])
		{
			i++;
			cout<<j<<","<<i<<endl;
		}
		else
		{
			i--;
			cout<<j<<","<<i<<endl;
		}
	}
	cout<<"i="<<i<<endl;

}
int main()
{

	equals ();
	return 0;
}
