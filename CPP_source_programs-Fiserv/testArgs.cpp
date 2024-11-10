#include<iostream>
using namespace std;

namespace kan{
	int x;
	int func();
}
int kan::func(){
	cout<<"inside kan::func()\n";
	x=4;
	return x;
}

int main(int argc,char **argv)
{
	cout<<"Nbr of arguments="<<argc<<endl;
	for(int i=0;i<argc;i++)
		cout<<i<<"th argument is "<<argv[i]<<endl;
	kan::func();
	cout<<"kan::x="<<kan::x<<endl;
	return 0;	
}
