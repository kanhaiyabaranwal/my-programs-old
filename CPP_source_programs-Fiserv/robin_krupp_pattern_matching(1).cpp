//Robin-Krupp Pattern matching algorithm
//Use Hash function to match m characters substring to the pattern. Hash value should uniquely represent the substring.
//If hash value of pattern matches that of substring, pattern found.
//Base is no. of distinct characters in the string. For alphabets, it will be 26, for alphanumeric it will be 36 etc.
#include<iostream>
#include<cstring>
using namespace std;
#define BASE 36	

int RobinKrupp(char str[],char pat[])
{
 int slen=strlen(str);
 int plen=strlen(pat);
 int hash1=0,hash2=0;
 int Base_multiplier=1;
 for(int i=0;i<plen;i++)
 {
  if(pat[i] >96 && pat[i] <123)
  {
  	hash1=hash1*BASE+pat[i]-96;		//a,b,c,...,z means 1,2,3,..,26
  	hash2=hash2*BASE+str[i]-96;
  }
  else if(pat[i] >47 && pat[i] < 58)
  {
  	hash1=hash1*BASE+pat[i]-48+27;		//0,1,2,..,9 means 27,28,29,..,36
  	hash2=hash2*BASE+str[i]-48+27;
  }
  Base_multiplier*=BASE;
 }
 Base_multiplier/=BASE;
 cout<<"hash1="<<hash1<<endl;
 cout<<"hash2="<<hash2<<endl;
 cout<<"Base_multiplier="<<Base_multiplier<<endl;
 //Now do pattern matching based on hash function of each of substring starting from 1st value of hash2
 //matching first pattern
 if(hash1==hash2)
   cout<<"pattern found  at string beginning "<<str<<" , hash1="<<hash1<<", hash2="<<hash2<<endl;
  char str1,str2;
 for(int i=1;i<slen-plen+1;i++)
 {
	
  if(str[i-1] >96 && str[i-1] <123)
  	str1=str[i-1]-96;
  else if(str[i-1] >47 && str[i-1] <58)
  	str1=str[i-1]-48+27;
  if(str[i+plen-1] >96 && str[i+plen-1] <123)
  	str2=str[i+plen-1]-96;
  else if(str[i+plen-1] >47 && str[i+plen-1] <58)
  	str2=str[i+plen-1]-48+27;
  hash2=BASE*(hash2-Base_multiplier*str1)+str2;
  if(hash1==hash2)
   cout<<"pattern found again at string beginning "<<str+i<<" , hash1="<<hash1<<", hash2="<<hash2<<endl;
 }
 return 0; 
}

int main()
{
 cout<<"Robin-Krupp Algorithm "<<endl;
 //char str[]="1231213123231";
 //char pat[]="12";
 char str[]="a1abaab123abc1ab1a1a";
 char pat[]="b1";
 RobinKrupp(str,pat);
 return 0;
}

