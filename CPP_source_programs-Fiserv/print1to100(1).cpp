#include<iostream>
using namespace std;
#define N 100
class A
{
public:
    static int a;
    A()
    {  cout<<a++<<endl;  }
};

int A::a = 1;

int main()
{
    #static int N = 100;
    A obj[N];
    return 0;
}
