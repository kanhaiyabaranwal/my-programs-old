#include<iostream>
#include<cstdlib>
#include<fstream>
using namespace std;
#define MAX_LINE 500000
#define COUNT 10000


void generate_file(ofstream& out)
{
	char str[COUNT+1][20]={0};
	int count=0;
	int line_len=19;
	for(int line=0;line<MAX_LINE; line++)
	{
		//cout<<"Line#"<<line<<"; Line length:"<<line_len<<"\t";
		int j=0;
		while(j<line_len)
		{
			int rd=rand()%26;
			char ch=rd+'a';
			//cout<<"random number:"<<rd<<" and character is "<<ch<<endl;
			
			str[count][j++]=ch;
		}
		//str[count][j++]='\n';
		str[count][j]='\0';
		count++;
		//cout<<"string["<<line<<"]="<<str<<endl;
		if(count>=COUNT)
		{
			for(int i=0;i<COUNT;i++)
			{
				//cout<<"string is:"<< str[i]<<endl;
				out<<str[i];
			}
			count=0;
		}
	}
	
}	

int main()
{
	ofstream out("string.txt");
	generate_file(out);
	out.close();

	ifstream in("string.txt");
	//cout<<"\nContents of string is :"<<endl;
	char str[13];
	//while(in>>str)
	//	cout<<str<<endl;
	return 0;
}
	
