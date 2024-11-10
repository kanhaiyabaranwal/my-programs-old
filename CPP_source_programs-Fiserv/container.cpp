#include<iostream>
#include<vector>

using namespace std;

int main(){
	vector<int> ivec(1,2);
	for(int i=0;i<10;i++)
		ivec.insert(ivec.begin(),i*2);
		//ivec.push_back(i*2);
	for(int i=0;i<20;i++)
		cout<<i<<"th element is "<<ivec[i]<<endl;
	ivec.
	return 0;

}
