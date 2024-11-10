#include<iostream>
#include<set>

using namespace std;

int main()
{
	set<int> iset;
	iset.insert(1);
	iset.insert(3);
	iset.insert(11);
	iset.insert(2);
	set<int>::iterator iter=iset.begin();
	while(iter!=iset.end())
	{
		cout<<"Next value "<<*iter<<endl;
		iter++;
	}
	return 0;
}
