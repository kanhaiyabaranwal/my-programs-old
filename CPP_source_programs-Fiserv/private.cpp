#include<iostream>
using namespace std;

class X{
	int i;
	public:
		void suicide(){
			cout<<"deleting from X\n";
			delete this;
		}
		X() { 
		cout<<"In X Contructor\n";
		}
};
/*
class Y: public X{
	int j;
	public:
		void suicide(){
			cout<<"deleting from Y\n";
			delete this;
		}
		Y():X(),j(6) {
			cout<<"j="<<j<<endl;
			cout<<"Inside Y Contructor\n";
		}
};
*/
int main(){
	
	//Y y;
	//cout<<"size of (y)"<<sizeof(y)<<endl;
	 
	X x;
	//cout<<"size of (x)"<<sizeof(x)<<endl;
	x.suicide();
	return 0;
}

