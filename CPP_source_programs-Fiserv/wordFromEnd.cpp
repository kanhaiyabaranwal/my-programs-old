#include<iostream>
#include<string>
#include<stack>
using namespace std;
int reverse(char *str,int begin,int end);

int main()
{
	/*with string
	string str="Kanhaiya is a good boy";
	string last;
	size_t lastspace= str.find_last_of(" ");
	while(lastspace!=string::npos)
	{
		last=str.substr(lastspace+1);
		cout<<last<<"\t";
		str=str.substr(0,lastspace);
		lastspace= str.find_last_of(" ");
	}
	cout<<str<<endl;
	*/
	
	/*without string, with character array
	char *line=new char(50);
	memset(line,NULL,50);
	
	sprintf(line,"Kanhaiya is a good boy");
	line[sizeof(line)]='\0';
	//strcpy(line,"Kanhaiya is a good boy");
	printf("line=%s",line);
	//cout<<line<<endl;

	delete line;	
	*/
	/*using stack
	stack<string> stk;
	string str;
	cout<<"Enter line, x to exit\n";
	while(cin>>str && str!="x")
		stk.push(str);
	while(!stk.empty())
	{
		cout<<stk.top()<<"\t";
		stk.pop();
	}
	*/
	//by reversing a string

	char str[]="Kanhaiya is a good boy";
	int len=strlen(str);
	reverse(str,0,len-1);
	cout<<str<<endl;
	int begin=0,end=len-1;
	char word[10];
	begin=0;
	int tempend, tempbegin;
	tempend=begin;
	tempbegin=begin;
	while(tempend!=end-1)
	{
		if(str[tempend]==' ')
		{
			reverse(str,tempbegin,tempend-1);
			tempbegin=tempend+1;
		}
		tempend++;
	}
	cout<<str<<endl;
	return 0;
}
int reverse(char *str,int begin,int end)
{
	char temp;
	while(begin<end)
	{
		temp=str[begin];
		str[begin]=str[end];
		str[end]=temp;
		begin++;
		end--;
	}
	return 0;
}
