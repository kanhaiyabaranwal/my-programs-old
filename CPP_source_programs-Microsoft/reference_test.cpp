#include<iostream>
using namespace std;

struct s{
	int num;
	
};

int& func(s &sp, int num){
	int &ref = sp.num;
	ref=num;
	return ref;
}

int main(){
	
	float f=5.0;
	if(f==5)
		cout<<"first"<<endl;
	else if (f==5.0)
		cout<<"second"<<endl;
	else
		cout<<"third"<<endl;
	s sp;
	sp.num=1;
	func(sp,5)=6;
	cout<<"sp.num="<<sp.num<<endl;
	return 0;
		
}
