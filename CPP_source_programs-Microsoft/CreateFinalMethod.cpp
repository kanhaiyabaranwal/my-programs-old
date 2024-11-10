#include<iostream>
using namespace std;

class C;
class B{
	private:
		virtual void f(){
			cout<<"Inside B"<<endl;
		}
		friend class C;
};

class C: private B{
	public:
		void f(){
			cout<<"Inside C"<<endl;
		}
		
};

class D: public C{
		public:
		 void f(){
			cout<<"Inside D"<<endl;
		}
};

int main()
{
	D d;
	d.f();
	return 0;
}

