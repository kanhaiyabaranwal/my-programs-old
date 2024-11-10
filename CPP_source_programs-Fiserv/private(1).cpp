//access private member of an object without being friend
#include<iostream>
using namespace std;

class Base {
	int i;
	char j;
	public:
	Base(int one,char two):i(one),j(two)	{}
};
int main()
{
	Base *b=new Base(1,'a');
	void *v=(void*)b;
	int m=*(int*)v;
	cout<<"private member i="<<m<<endl;
	return 0;

}
