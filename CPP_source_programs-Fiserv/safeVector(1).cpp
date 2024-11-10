#include <iostream>  

#include <vector>  

   

using namespace std;  
#define EXIT_SUCCESS 0
   

int main(int argc, char** argv) {  

       

    /*  Initialize vector of 10 copies of the integer 5 */  

    vector<int> vectorOne(10,5);  

       

    /*  run through the vector and display each element, if possible */  

    for (long index=0; index<20; ++index) {  

        try {  

            cout << "Element " << index << ": " << vectorOne.at(index) << endl;  

        }  



        catch (exception& e) {  

            cout << "Element " << index << ": index exceeds vector dimensions." << endl;  
		break;
        }  
    }  

       

    return EXIT_SUCCESS;  

} 

