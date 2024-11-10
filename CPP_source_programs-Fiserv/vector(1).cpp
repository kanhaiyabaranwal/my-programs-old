//compile option xlC -D__IBMCPP_TR1__ -qlanglvl=extended0x vector.cpp
//#define __IBMCPP_TR1__ 
#include<iostream>
#include<list>
#include<vector>
using namespace std;
int main()
{
	vector<int> ivec(10);
	//vector<int>::iterator iter;
	auto iter=ivec.begin();
	//if(ivec.empty()==true)
	if(iter==NULL)
	{
		cout<<"empty vector\n";
		return 0;
	}
	int i;
	cout<<"vector demo\n";
	for(iter=ivec.begin(), i=1; iter!=ivec.end();iter++,i+=2)
	{
		*iter=i;
	}
	cout<<"vector is\n"<<endl;
	ivec.push_back(100);
	ivec.push_back(200);
	vector<int>::const_iterator iter1;
	for(iter1=ivec.begin(); iter1!=ivec.end();iter1++)
		cout<<*iter1<<"\t";
	//lists
	cout<<"list demo1\n";
	list<long> llist(ivec.begin(),ivec.begin()+ivec.size()/2);
	//list<long> llist(10,2);
	list<long>::const_iterator iter2;
	for(iter2=llist.begin(); iter2!=llist.end();iter2++)
		cout<<*iter2<<"\t";
	cout<<"list demo2\n";
	//list<long> llist(10,2);
	//for(iter2=llist.begin()+(llist.end()-llist.begin())/2; iter2!=llist.end();iter2++)
	for(iter2=llist.begin(); iter2!=llist.end();iter2++)
		cout<<*iter2<<"\t";
	
	return 0;
}
	
