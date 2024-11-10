#include<iostream>

using namespace std;
class Trial{
	int x;
	char c;
	public:
		Trial(int xh,char ch):x(xh),c(ch) {}
		Trial& operator=(const Trial& t){
			x=t.x;
			c=t.c;
			return *this;
		}
		friend ostream& operator<<(ostream& os,Trial &t){
			os<<t.x<<t.c<<endl;
			return os;
		}
		friend ostream& operator<<(ostream& os,Trial *t){
			os<<t->x<<t->c<<endl;
			return os;
		}
		void print(Trial& t){
			cout<<"this.x="<<x<<endl;
			cout<<"this.c="<<c<<endl;
			cout<<"t.x="<<t.x<<endl;
			cout<<"t.c="<<t.c<<endl;
		}
		void print(Trial* t){
			cout<<"this.x="<<x<<endl;
			cout<<"this.c="<<c<<endl;
			cout<<"t.x="<<t->x<<endl;
			cout<<"t.c="<<t->c<<endl;
		}
};
int main(){
	Trial a(2,'a');
	Trial b(3,'b');
	a.print(b);
	cout<<a<<endl;
	cout<<b<<endl;
	b=a;
	cout<<"b after change to a\n";
	cout<<b<<endl;
	Trial *pa=new Trial(4,'a');
	cout<<*pa<<endl;
	Trial *pb=&a;
	pa->print(pb);
	
	return 0;
}
	
