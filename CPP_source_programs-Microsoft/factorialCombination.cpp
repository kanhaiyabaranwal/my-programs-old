#include<iostream>
using namespace std;
int solve(int A, int B, int C) {
    
    int n=A;
    int r=B;
    int p=C;
    long long mul=1;
    long long localmul=1;
    bool flag=true;
    long long large,small;
    if(n-r>r)
    {
        large=n-r;small=r;
    }
    else{
        large=r;small=n-r;
    }
        
        for(int i=2;i<=small;i++)
            localmul*=i;
        cout<<"localmul:"<<localmul<<endl;
        for(int i=n;i>=large+1;i--)
        {
            mul*=i;
            if(mul%localmul==0 && flag)
            {
                mul/=localmul;
                flag=false;
            }
            mul=mul%p;
        }

    return mul;
}

int main()
{
	int A=7,B=5,C=17;
	int output=solve(A,B,C);
	cout<<"output:"<<output<<endl;
	return 0;
}
