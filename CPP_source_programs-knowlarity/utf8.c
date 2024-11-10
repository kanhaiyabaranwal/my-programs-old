#include <stdio.h>
#include <stdlib.h>
void print_non_ascii_count(FILE *f) {
    unsigned val = 0;
    int c = 0, cnt = 0;
    int no_of_non_ascii=0;
    while ((c = fgetc(f)) != EOF) {  
         if(c=='\n'){
           printf("%d\n",no_of_non_ascii);
           no_of_non_ascii=0;
           }
         if (c < 0x80)
             continue;
         else if ((c & 0xC0) == 0xC0) {
            if (cnt > 0) {
                printf("bad count\n");
                return;
            }
            if ((c & 0xF8) == 0xF0) {      
                val = c & 0x07;            
                cnt = 3;                   
            }
            else if ((c & 0xF0) == 0xE0) { 
                val = c & 0x0f;            
                cnt = 2;                  
            }
            else if ((c & 0xE0) == 0xC0) { 
                val = c & 0x1f;           
                cnt = 1;                   
            }
            else {
                printf("bad byte\n");
                return;
            }
        }
 
        else { 
            val <<= 6;                    
            val |= c & 0x3f;
            if (--cnt <= 0) {
               if(val>127)
                 no_of_non_ascii++;
            }
        }
    }
}
 
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("please inter file name\n");
        return 0;
    }
 
    FILE *f = fopen(argv[1], "rb");
    if (f == NULL) {
        printf("Cannot open file please check input file\n");
         return 0;
    }
 
    print_non_ascii_count(f);
 
    fclose(f);
    return 0;
}



