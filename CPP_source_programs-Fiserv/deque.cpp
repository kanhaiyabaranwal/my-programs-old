#include<iostream>
#include<deque>
#include<vector>
using namespace std;

int main()
{
	vector<int> ivec(10,3);
	cout<<"Elements in vector are -> ";
	for(int i=0;i<ivec.size();i++)
		cout<<ivec[i]<<" ,";
	cout<<endl;
	cout<<"sizeof vector="<<sizeof(ivec)<<endl;

	deque<int> ideq(10,3);
	cout<<"Elements in deque are -> ";
	for(int i=0;i<ideq.size();i++)
		cout<<ideq[i]<<" ,";
	cout<<endl;
	cout<<"sizeof deq="<<sizeof(ideq)<<endl;
	return 0;
}
