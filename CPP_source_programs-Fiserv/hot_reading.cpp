#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
using namespace std;

void hot_reading()
{
	ifstream in("hot.txt");
	char buff[1025];
	int count=0;
	string str;
	
	cout<<"string is "<<str;
	while(true)
	{
		in.getline(buff,1024);
		
		if(strncmp(buff,"  <description>",sizeof("  <description>"))==0)
			cout<<"Line "<<count<<":"<<buff<<endl;
			if(count++==40)
				break;
	}
}

int main()
{
	string str;
	ifstream in("meeting.txt");
	in>>str;
	cout<<"First meeting is "<<str<<endl;
	hot_reading();
	return 0;
}
