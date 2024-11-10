#include <stdio.h>

struct test
{
   char x;
   int y;
   int z;
};
struct efficient_test
{
   char x;
   int y: 24;
   int z;
};
 
int main()
{

   test t;
   t = {'c',10,16777216};
   printf("Size of test is %lu\n",sizeof(test));
   printf("%c,%d,%d\n", t.x,t.y,t.z);
   efficient_test et;
   et = {'c',10,16777216};
   printf("Size of efficient test is %lu\n",sizeof(efficient_test));
   printf("%c,%d,%d\n", et.x,et.y,et.z);

   return 0;
}
