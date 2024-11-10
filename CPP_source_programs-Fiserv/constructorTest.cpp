#include<iostream>
 
using namespace std;

class A{
	int i;
	int j;
	int k;
	public:
		A(int p):i(p) {}
		A(const A&)	{
			cout<<"called copy contructor\n";
		}
		A(const A*) {
			cout<<"called pointer contructor\n";
		}
		
};

int main()
{
	
	int sz=sizeof(char);
	char arr[10];
	int arrsz=sizeof(arr)/sizeof(char);
	cout<<"arrsz="<<arrsz<<endl;
	A *a=new A(2);
	A b(a);
	cout<<"sizeof a="<<sizeof(*a)<<"\tsizeof b="<<sizeof(b)<<endl;
	int choice;
	cout<<"Enter the option";
	cin>>choice;
	switch(choice)
	{
		case 1:
			cout<<"Calling A1\n";
			A(1);break;
			
		case 2:
			cout<<"Calling A2\n";
			A(2);
		default:
			cout<<"Calling default\n";
			A(3);
	}
	return 0;
}
