#include<iostream>
#include<cstdio>
using namespace std;

int divide(int nu, int de) {

    int temp = 1;
    int quotient = 0;

    while (de <= nu) {
        de <<= 1;
        temp <<= 1;
    }

	printf("%d %d\n",de,temp,nu);
    while (temp > 1) {
        de >>= 1;
        temp >>= 1;

        if (nu >= de) {
            nu -= de;
            printf("%d %d\n",quotient,temp);
            quotient += temp;
        }
    }

    return quotient;
}

int main()
{
	int out=divide(45,4);
	cout<<"out="<<out<<endl;
	return 0;
}
