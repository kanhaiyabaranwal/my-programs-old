#include<iostream>

using namespace std;

int main()
{
    int arr[26]={0};
    char str[]="SNEHA SUMAN";
    char *pstr=str;
    while(*pstr)
    {
                arr[*pstr-65]++;
                pstr++;
    }
    for(int i=0;i<26;i++)
    {
            if(arr[i]>1)
                        cout<<char(i+65)<<'\t';
    }
    int in;
    cin>> in;
    return 0;
}
