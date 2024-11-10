#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
	ifstream ifs;
	ifs.open("marks.txt");
	string str;
	int marks=0;
	int sum=0,count=0;
	int roll;
	char sub[30];
	while(getline(ifs,str))
	{

		//int marks=atoi(str);
		//ifs>>str;
		//if(str=="Data Structures")
		//{
		//	sum+=marks;
		//	count+=1;
		//}
		//ifs>>str;	//thi is 
		if(str.find("Data Structures")!= std::string::npos)
		{
			cout<<"str is "<<str;
			int pos = str.find_last_of(' ');
			cout<<" and marks is "<<str.substr(pos+1)<<endl;
			marks=atoi(str.substr(pos+1).c_str());
			sum+=marks;
			count+=1;
		}
			
	}
	cout<<"sum="<<sum<<" totals:"<<count<<" and avg is:"<<sum/count<<endl;
	return 0;
}
				
