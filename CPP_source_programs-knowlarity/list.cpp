#include<iostream>
#include<list>
using namespace std;


int main()
{
	list<int> lint;
	lint.push_front(10);
	lint.push_back(11);
	lint.push_front(12);
	lint.push_front(13);
	lint.push_front(30);
	cout<<"This is list"<<endl;
	list<int>::iterator liter=lint.begin();
	while(liter!=lint.end())
	{
		cout<<"Next value "<<*liter<<endl;
		liter++;
	}
	return 0;
}
