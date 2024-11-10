#include<iostream>
#include<map>
#include<utility>
using namespace std;

typedef map<int,int>::reverse_iterator iter;

int main()
{
	//map of pow and coefficient
	map<int,int> poly1, poly2, poly3;
	poly1.insert(make_pair(3,3));
	poly1.insert(make_pair(2,2));
	poly1.insert(make_pair(0,5));
	
	poly2.insert(make_pair(4,4));
	poly2.insert(make_pair(1,5));
	poly2.insert(make_pair(0,7));
	
	iter iter1=poly1.rbegin();
	cout<<"Polynomial #1 is "<<endl;
	for(;iter1!=poly1.rend();iter1++)
		cout<<iter1->second<<"*y^"<<iter1->first<<"+";
	cout<<endl<<"Polynomial #2 is "<<endl;
	for(iter1=poly2.rbegin();iter1!=poly2.rend();iter1++)
		cout<<iter1->second<<"*y^"<<iter1->first<<"+";
	iter iter2=poly2.rbegin();
	for(iter1=poly1.rbegin();iter1!=poly1.rend();iter1++)
	{
		iter2=poly2.rbegin();
		for(;iter2!=poly2.rend();iter2++)
			poly3[iter1->first+iter2->first]+=iter1->second*iter2->second;
	}
	cout<<"Resulting polynomial is "<<endl;
	for(iter1=poly3.rbegin();iter1!=poly3.rend();iter1++)
		cout<<iter1->second<<"*y^"<<iter1->first<<"+";
	    
}
