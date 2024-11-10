#include <iostream>    
#include <string>    
#include<typeinfo>    
using namespace std;
    
int main( )    
{        
	try        
	{            
	string strg1("Test");
            string strg2("ing");
            strg1.append(strg2, 1, 3);
            cout << "Type: " << typeid(strg1).name() << endl;
            cout << strg1 << endl;
		
	    throw new string("kanhaiya");	    
        }        catch (string *a )        
	{            
		cout << "Caught: " << *a << endl;
        };
        return 0;
    }
