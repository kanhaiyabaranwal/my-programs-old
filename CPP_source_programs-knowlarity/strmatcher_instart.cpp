/********************************************************************
Description     :       Driver Program for Prefix and exact string matching 
Author          :       Kanhaiya P. Baranwal 
Date            :       07-FEB-2016
********************************************************************/

#include "strmatcher_instart.hpp"
using namespace std;
 
int main()
{
    // Input keys (use only 'a' through 'z' and lower case)
    char keys[][8] = {"abc", "fas", "abc","Abc"};
    int id[]={908,907,901,900};
 
    StringMatcher strm;
 
    strm.add_exact_match(keys[0],id[0]);
    strm.add_prefix_match(keys[1],id[1]);
    strm.add_prefix_match(keys[2],id[2]);
    strm.add_prefix_match(keys[3],id[3]);

    // Search for different keys
    printf("%s --- %d\n", "abc", strm.lookup("abc") );
    printf("%s --- %d\n", "abcd", strm.lookup("abcd") );
    printf("%s --- %d\n", "fast", strm.lookup("fast") );
    printf("%s --- %d\n", "fas", strm.lookup("fas") );
    printf("%s --- %d\n", "Abcd", strm.lookup("Abcd") );
    printf("Deleting a prefix string Abc\n");
    strm.delete_prefix_match(keys[3]);
    printf("%s --- %d\n", "Abcd", strm.lookup("Abcd") );
    printf("Deleting exact string abc\n");
    strm.delete_exact_match(keys[0]);
    printf("%s --- %d\n", "abc", strm.lookup("abc") );
    printf("Deleting prefix string abc\n");
    strm.delete_prefix_match(keys[2]);
    printf("%s --- %d\n", "abc", strm.lookup("abc") );
    return 0;
}
