#include <iostream>
using namespace std;

#define   keyhash(s) ( ((((((* (unsigned char *) (s)    *0x101+ \
                  *((unsigned char *) (s)+1))*0x101+ \
                  *((unsigned char *) (s)+2))*0x101+ \
                  *((unsigned char *) (s)+3))*0x101+ \
                  *((unsigned char *) (s)+4))*0x101+ \
                  *((unsigned char *) (s)+5))*0x101+ \
                  *((unsigned char *) (s)+6))*0x101+ \
                  *((unsigned char *) (s)+7) )

#define   keyhash1(s) ( ((((((* (unsigned char *) (s)    *0x101+ \
                  *((unsigned char *) (s)+1))*0x101
int main()
{
	char qname[]="d1";
	int qkey = keyhash1(qname);
	cout<<"qkey"<<qkey<<endl;
	unsigned char * pc = (unsigned char *)("d");
	unsigned char * pc1 = (unsigned char *)("1");
	cout<<"* (unsigned char *) (d)"<<(*pc)*0x101<<endl;
	cout<<"* (unsigned char *) (d)"<<(*pc1)*0x101<<endl;
	return 0;
}
	
