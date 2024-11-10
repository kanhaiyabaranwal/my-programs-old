#include<iostream>
#include<string>
#include<sstream>
using namespace std;

class X{
	int i;
	static int j;
	public:
		X(int j):i(j) {cout<<"constructor";}
		~X() {
			cout <<"destructor";
		}
		friend ostream& operator<<(ostream& os,X &x){
			os<<"member i="<<x.i<<endl;
			return os;
		}
		X& operator=(const X& x){
			cout<<"inside ="<<endl;
			i=x.i;
			return *this;
		}
};
int X::j=0;
X funcx(){
	X x(4);
	return x;
}

int f3() {
	return 1;
}
const int f4(){
	return 4;
}

char* func(){
	return "Kanhaiya";
}
int main()
{
	string str;
	//while ( cin>>str && str!="x")
	//	cout<<str;
	//cout<<"string reading completed\n";
	//char ptr[]="kanhaiya";
	//*ptr='J';
	//cout<<ptr<<endl;
	int i=f3();
	//f3()=4;
	int j=f4();
	char* s=func();
	//*pch='J';
	cout<<s;
	X x=funcx();
	funcx()=x;
	//cout<<"cx="<<cx;
	string s1("file");
	//char str[5];
	stringstream ss;
	ss<<10;
	string s2= ss.str();
	cout<<"s2="<<s2<<endl;
	//s1.append(string(1))
	return 0;
}
