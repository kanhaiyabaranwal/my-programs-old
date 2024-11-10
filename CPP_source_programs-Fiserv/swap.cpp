#include<iostream>
using namespace std;

int main()
{
	char arr[]="swap";
	char *p1=arr+1,*p2=arr+3;
	*p1=*p1^*p2;
	*p2=*p1^*p2;
	*p1=*p1^*p2;
	cout<<"after change arr="<<arr<<endl;
	return 0;
}
