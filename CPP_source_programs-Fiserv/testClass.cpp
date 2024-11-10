#include<iostream>
using namespace std;//This class can be designed as you wish
class SR{public:SR(int i) {}};
struct A { A(){ cout << "A"; } };
struct B { B(){ cout << "B"; } };
struct C { C(){ cout << "C"; } };
struct D { D(){ cout << "D"; } };
struct E : D { E(){ cout << "E"; } };
struct F : A,B
{
        C c;
        D d;
        E e;
        F() : d(),c(),e() { cout << "F"; }
};
int main()
{
        F f;
        F *p = 0;
        //E *p=new E();
        delete p;
         return 0;
}
