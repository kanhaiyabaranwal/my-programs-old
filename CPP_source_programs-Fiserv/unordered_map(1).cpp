#include<iostream>
#include<unordered_map>
using namespace std;
using namespace std::tr1;

struct s{
	int arr[5];
};

int main()
{
	unordered_map<int ,struct s> umap;
	//unordered_map<int ,int> umap;
	int val=4;
	umap[1].arr[0]=2;
	umap[1].arr[1]=3;
	//umap[1]=3;
	cout<<"Values in umap are :"<<umap[1].arr[0]<<endl;
	//cout<<"Values in umap are :"<<umap[1]<<endl;
	return 0;
}
