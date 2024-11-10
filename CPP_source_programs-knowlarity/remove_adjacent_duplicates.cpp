#include<iostream>
#include<string>
using namespace std;

void remove_adjacent_duplicates ()
{
	string str="azxxzyyyptrssmp";
	int i=0,j=i+1;
	bool flag=false;
	while(i<str.length()-1)
	{
		j=i+1;
		while(str[i]==str[j] && i>0 && j<str.length())
		{
			i--;
			j++;
			flag=true;
		}
		if(flag)
		{
			string newstr=str.substr(0,i+1)+str.substr(j,str.length()-j);
			cout<<"new str="<<newstr<<endl;
			flag=false;
			str=newstr;
		}
		i++;
	}
	cout<<"new str="<<str<<endl;
		
	

}
int main()
{

	remove_adjacent_duplicates ();
	return 0;
}
