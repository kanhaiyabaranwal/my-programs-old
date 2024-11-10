#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

class S{
	float i;
	public:
	
	void* operator new(size_t sz)
	{
		printf("inside new");
		void * m=::new char[sz];
		return m;
	}
	void* operator new[](size_t sz)
	{
		printf("inside new array");
		void* m=new char[sz];				//it simply allocates memory of size sz which is multiple of size of object plus 4.
		return m;
	}
	/*S()	{
		cout<<"Constructor S"<<endl;
	}*/
};
int main()
{
	int *n;
	//S* s=new S;
	//cout<<"sizeof(S)="<<sizeof(s)<<endl;
	S* sa=new S[3];
	cout<<"sizeof(S[])="<<sizeof(sa)<<endl;
	cout<<"my name";
	return 0;
}  
