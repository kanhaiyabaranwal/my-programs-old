#include<stdio.h>
#define LOG_FILE "/u/bkanhaiy/kan.tmp"

int main()
{
        //Kan test
        FILE *kanfp=fopen(LOG_FILE,"w+");
        if(kanfp != NULL)
        {
                fprintf(kanfp,"Test successful\n");
                fclose(kanfp);
        }
	else
		printf("failed to create a kan.tmp file\n");
	return 0;
}
