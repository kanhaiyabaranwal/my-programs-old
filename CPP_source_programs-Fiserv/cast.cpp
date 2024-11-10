// dynamic_cast
#include <iostream>
#include <exception>
using namespace std;

class CBase { virtual void dummy() {} };
class CDerived: public CBase { int a; };

int main () {
  try {
    CBase * pba = new CDerived;
    CBase * pbb = new CBase;
    CDerived * pd;
   CBase b;

     b= static_cast<CBase>(*pba);
    if (pd==0) cout << "Null pointer on first type-cast" << endl;

	cout<<"typeid of pd="<<typeid(pd).name()<<endl;
    pd = dynamic_cast<CDerived*>(pbb);
    if (pd==0) cout << "Null pointer on second type-cast" << endl;
	cout<<"typeid of pd="<<typeid(pd).name()<<endl;

  } catch (exception& e) {cout << "Exception: " << e.what();}
  return 0;
}

