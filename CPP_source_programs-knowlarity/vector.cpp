#include<iostream>
#include<vector>
#include<list>

using namespace std;

int main()
{
	list<string> slist(10,"sh");
	
	vector<int> ivec={1,2,3,4,5};
	ivec.reserve(10);
	cout<<"ivec.size:"<<ivec.size()<<endl;
	cout<<"ivec.capacity:"<<ivec.capacity()<<endl;
	cout<<"ivec.max_size:"<<ivec.max_size()<<endl;
	ivec.resize(3);
	cout<<"ivec.size:"<<ivec.size()<<endl;
	vector<int>::iterator iter=ivec.begin();
	while(iter!=ivec.end())
	{
		cout<<"Next value "<<*iter<<endl;
		iter++;
	}
	return 0;
}
