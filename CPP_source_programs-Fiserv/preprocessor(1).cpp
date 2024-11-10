#include<iostream>

using namespace std;

#define DEBUG(x) cout<<##x<<"="<<x<<" and #x="<<#x<<endl;

int main()
{
	int var=4;
	DEBUG(var);
	return 0;
}
