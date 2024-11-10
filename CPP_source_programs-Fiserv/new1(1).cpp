//: C13:PlacementOperatorNew.cpp
// Placement with operator new
#include <cstddef> // Size_t
#include <iostream.h>
using namespace std;
class X {
int pl;
static int i;
static char  ch[10000];	//global storage location
public:
X() {
cout << "this = " << this << endl;
}
~X() {
cout << "X::~X(): " << this << endl;
}
void* operator new(size_t, void* loc) {
	cout<<"inside overload new with predefined memory"<<endl;
return loc;
}
void* operator new(size_t sz) {
	cout<<"inside overload new"<<endl;
	int sizeofClass = sizeof(X);
	int nbrOfObjects=sz/sizeofClass;
	cout<<"size passed as argument="<<sz<<endl;
	cout<<"sizeofClass="<<sizeofClass<<endl;
	cout<<"Nbr of Objects="<<nbrOfObjects<<endl;
	void *p=::new X();
return p;
}
void* operator new[](size_t sz){
	int sizeofClass = sizeof(X);
	int nbrOfObjects=(sz-8)/sizeofClass;
	cout<<"size passed as argument="<<sz<<endl;
	cout<<"sizeofClass="<<sizeofClass<<endl;
	cout<<"Nbr of Objects="<<nbrOfObjects<<endl;
	cout<<"sz allocated for this array"<<endl;
	i=sz;
	return ch;	
}
void operator delete[](void* p)
{
	::delete []p;
	cout<<"inside overloaded delete array"<<endl;
}
};
int X::i=0;
char X::ch[]={0};
int main() {
void* l=new char[10];
cout << "l = " << l << endl;
X* xp = new(l) X(); // X at location l
xp->X::~X(); // Explicit destructor call

X* xp1=new X();

cout<<"creating an array"<<endl;
X* xp2=new X[3];
cout<<"Array of X created\n";
delete []xp2;
delete xp1;
cout<<"playing with array of integers\n";
int y[1];
cout<<"sizeof int arr "<<sizeof y<<endl;
// ONLY use with placement!
} ///:~
