#include <stdio.h>

int main(int ac) {
  int c;
  int i;
  int num_true = 0;
  FILE *fp = fopen("output.txt", "r");
  while ((c = getc(fp)) != -1) {
    for (i=0; i<8; i++) {
      if (c & (1<<i)) {
        num_true++;
      }
    }
  }
  printf("The total number is: %d\n", num_true);
  return 0;
}
