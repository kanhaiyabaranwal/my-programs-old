//Robin-Krupp Pattern matching algorithm
//Use Hash function to match m characters substring to the pattern. Hash value should uniquely represent the substring.
//If hash value of pattern matches that of substring, pattern found.
#include<iostream>
#include<cstring>
using namespace std;

int RobinKrupp(char str[],char pat[])
{
 int slen=strlen(str);
 int plen=strlen(pat);
 int hash1=0,hash2=0;
 int mul10=1;
 for(int i=0;i<plen;i++)
 {
  hash1=hash1*10+pat[i]-48;
  hash2=hash2*10+str[i]-48;
  mul10*=10;
 }
 mul10/=10;
 cout<<"hash1="<<hash1<<endl;
 cout<<"hash2="<<hash2<<endl;
 cout<<"mul10="<<mul10<<endl;
 //Now do pattern matching based on hash function of each of substring starting from 1st value of hash2
 //matching first pattern
 if(hash1==hash2)
   cout<<"pattern found, hash1="<<hash1<<", hash2="<<hash2<<endl;
 for(int i=1;i<slen-plen;i++)
 {
  hash2=10*(hash2-mul10*(str[i-1]-48))+(str[i+plen-1]-48);
  if(hash1==hash2)
   cout<<"pattern found again, hash1="<<hash1<<", hash2="<<hash2<<endl;
 }
 
}

int main()
{
 cout<<"Robin-Krupp Algorithm "<<endl;
 char str[]="1231213123231";
 char pat[]="23";
 RobinKrupp(str,pat);
 return 0;
}
