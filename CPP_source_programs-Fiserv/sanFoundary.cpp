#include <typeinfo>    
#include <iostream>    
using namespace std;
class Myshape    
{        
	public:        
	virtual void myvirtualfunc() const {}    
};
class mytriangle: public Myshape    
{        
	public:        
	void myvirtualfunc() const        {           };
};
int main()    {        
	int t=size_t(5);
	cout<<"t="<<t<<endl;
	return 0;
    }
