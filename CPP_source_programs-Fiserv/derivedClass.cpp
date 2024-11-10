#include<iostream> 

using namespace std;   

class base {     
int arr[10];      
};

class b1: public base { 
};   
class b2: public base { 
};   
class b3: public base { 
};   
//class derived: virtual public b1, virtual public b2 ,virtual public b3{
class derived: public b1 , public b2{
};   

int main(void) 
{    
	cout<<sizeof(derived);   
	return 0; 
}
