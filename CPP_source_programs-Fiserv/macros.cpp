#include<cstdio>
#include<iostream>
using namespace std;

//stringizing	,shows variable name as well as its value
#define DEBUG(x)	cout<<#x<<"="<<x<<endl;x;
//token pasting - creating variables
#define FIELD(a)	int a##_size; char *a##_str
class Record{
	public:
	FIELD(one);
	Record(int i):one_size(i) {
	};
	
};

int main()
{
	int k=9;
	DEBUG(k)
	Record r(1);
	DEBUG(r.one_size)
	return 0;
}

