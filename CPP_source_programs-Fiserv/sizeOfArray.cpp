#include<iostream>

using namespace std;

class arr{
	int *vec;
	public:
		arr(int i){
			int *vec=new int[i];
		}
		int sz(){
			int size=sizeof(vec[])/sizeof(int);
			cout<<"size of arr is "<<size<<endl;
			return size;
		}
};

int main()
{
	arr a(8);
	a.sz();
	return 0;
}
