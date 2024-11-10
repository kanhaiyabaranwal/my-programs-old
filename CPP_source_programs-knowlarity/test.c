#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<fstream>
using namespace std;


void test()
{
	int i,a=10;
	i=5;
	//(++i)=a;
	cout<<"i="<<i<<endl;
}		

void read_file()
{
	fstream file;
	char str[12];
	system("sleep 100");
	file.open("string.txt",ios::in);
	if(file.fail())
	{
		cout<<"failed to open file"<<endl;
	}
	else
	{
		bool res=file.getline(str,12);
		cout<<"string found is "<<str<<endl;
		if(res)
			cout<<"fail bit is set"<<endl;
		else
			cout<<"fail bit is not set"<<endl;
		file.getline(str,12);
		cout<<"string found is "<<str<<endl;
	}
	return ;
}
	
	
	

/*int main ()
{
    int i;
    //read_file();
    test();
    return 0;
}*/
#define N 50
#define my_sizeof(x) (char*)(&x+1) - (char*)(&x)

int main(int num,char *argv[]=NULL)
{
    long x;
    cout<<"\nsizeof(long)"<<my_sizeof(long)<<endl;
    return 0;
}

