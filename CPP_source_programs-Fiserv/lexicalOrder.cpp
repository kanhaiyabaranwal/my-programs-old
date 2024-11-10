#include<iostream>
#include<vector>
#include<cstdlib>
#include<sstream>
#include<algorithm>
using namespace std;

int main()
{
	vector<int> ivec;
	int num;
	for(int i=0;i<30;i++)
	{
		num=rand()%50;
		ivec.push_back(num);	
		cout<<"num="<<num<<"\t";
	}
	vector<string> svec;
	//svec.insert(ivec.begin(),ivec.end());
	cout<<"string values are"<<endl;
	string str;
	char *str1=new char[20];
	stringstream ss;
	for(int i=0;i<30;i++)
	{
		ss<<ivec[i];
		str=ss.str();		//str is initialized with the number
		svec.push_back(str);
		cout<<"svec="<<svec[i]<<"\t"<<"ss contains"<<ss.str()<<endl;
		ss.str("");
	}
	sort(svec.begin(),svec.end());
	cout<<"lexically sorted numbers are"<<endl;
	for(int i=0;i<30;i++)
	{
		cout<<svec[i]<<"\t";
	}
	return 0;
}
