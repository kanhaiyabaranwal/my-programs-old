#include<stdio.h>

int main() 
{    
	FILE *fp;
	fp = stdout;
	fprintf (fp,"Test123\n");
	printf("sizeof('V') = %d sizeof(char) = %d", sizeof('V'), sizeof(char));    
	return 0; 
}
