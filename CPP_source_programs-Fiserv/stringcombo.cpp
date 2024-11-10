//Given any combination of the mapping numbers as string, return the number of ways in which the input string can be split into sub-strings and represented as character strings. 
//For e.g. given "111" -> "AAA", "AK", "KA" -> 3
//Valid combinations are ({1,1,1}, {1,11},{11,1}) = 3

#include<iostream>
#include<cstring>
#include<string>

using namespace std;
int arr[]={1,2,2,4};
int len;
//find combo of 2 strings at a time and then call recursively
//handle case of only one character 
int findCombo(string str, int i)
{
	int pos;
	static int countCombo;
	//cout<<"pos="<<pos<<endl;
	//terminating condition
	if(i>=len-2)
	{
		//look for combo of last 2 digits	
		if(arr[i]<=2 && arr[i+1]<7)
		{
			pos=arr[i]*10+arr[i+1];
			cout<<str<<char(96+pos)<<endl;
			++countCombo;
		}
		//print combo of individual characters
		cout<<str<<char(96+arr[i])<<char(96+arr[i+1])<<endl;
		return ++countCombo;
	}
	string newstr;
	//if at leas 2 more digits found,create character from 2 digits and call further
	if(i<len-2 && arr[i]<=2 && arr[i+1]<27)
	{
		pos=arr[i]*10+arr[i+1];
		newstr=str+string(1,96+pos);
		//cout<<"newstr"<<newstr<<endl;
		findCombo(newstr,i+2);
	}
	//create character from 1 digit and call further
	pos=arr[i];
	newstr=str+string(1,96+pos);
	//cout<<"newstr1"<<newstr<<endl;
	findCombo(newstr,i+1);
	return countCombo;
}
 
int main()
{
	cout<<"Program to find combination of mapping numbers as string, returning the number of ways input string can be split into sub-strings"<<endl;
	len=sizeof(arr)/sizeof(arr[0]);
	cout<<"len="<<len<<endl;
	string str;
	int pos=0;
	int count=findCombo(str,pos);
	cout<<"count of combo="<<count<<endl;
	/*string str1="kan";
	string str2=str1+string(1,'h')+string(1,char(96+1));
	cout<<"str2="<<str2<<char(96+1)<<endl;
	*/return 0;
}
