#include<iostream>
#include<string>
using namespace std;

string longest_common_substring(string str[],int sz)
{
	string comm_str;
	int j=0;
	bool not_matched=false;
	bool run=false;
	while(true)
	{
		for(int i=0;i<sz-1;i++)
		{
			if(str[i].size() >= j && str[i+1].size() >= j)
			{
				if(str[i][j] != str[i+1][j] )
				{
					not_matched=true;
					break;
				}
				run=true;
			}
			else
				run=false;
			
		}
		if(run=false || not_matched)
			break;
		else
			comm_str.push_back(str[0][j]);
		j++;

	}
	return comm_str;
}

int main()
{
	string str1[]={"geeksforgeeks", "geeks", "geek", "geezer"};
	string str[]={"apple", "ape", "april"};
	string comm_str=longest_common_substring(str,3);
	cout<<"common string is "<<comm_str<<endl;
	return 0;
}
