#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int> ivec;
	int i;
	for(i=0; i<5; i++)
		ivec.insert(ivec.begin(),i*3);
	cout << "size="<<ivec.size()<<endl;
	cout<< "max_size="<<ivec.capacity()<<endl;
	int max_size=ivec.capacity();
	for(;i < max_size; i++)
		ivec.push_back(i*3);
	cout<<"now full, insert now and see capacity\n";
	cout << "size="<<ivec.size()<<endl;
	cout<< "max_size="<<ivec.capacity()<<endl;
	ivec.insert(ivec.begin(),i*3);
	cout<<"Max size should increase now\n";
	cout << "size="<<ivec.size()<<endl;
	cout<< "capacity="<<ivec.capacity()<<endl;
	cout<< "max_size="<<ivec.max_size()<<endl;

	ivec.resize(15,5);
	ivec.reserve(20);
	cout<<"ivec after reserving 30 elements"<<endl;
	for(i=0;i<30;i++)
	{
		try {
			cout<<ivec.at(i)<<"\t";
		}
		catch(exception& e){
			cout<<"vecto at location "<<i<<"not defined\n";
			break;
		}
	}
	cout<< "\ncapacity="<<ivec.capacity()<<endl;
	return 0;
}

