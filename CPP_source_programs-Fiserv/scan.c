/* fscanf example */
#include <stdio.h>
#include <time.h>

int main ()
{
  char str [80];
  char rsp [2080];
  float f;
  FILE * pFile;
time_t current_time;
 current_time=time(NULL);
	printf("current time since epoch=%ld\n",current_time);

  pFile = fopen ("scan.txt","r");
  //fprintf (pFile, "%s", "PI\n");
  //fprintf (pFile, "%s", "SI is also good going");
  //rewind (pFile);
  //fscanf (pFile, "%f", &f);
	memset(rsp,NULL, 80);	
 while ( !feof(pFile)  )
 {
	if ( fgets (str , 256 , pFile) != NULL )
  		sprintf (rsp,"%s %s",rsp,str);
  //fscanf (pFile, "%s", str);
  //printf ("I have read: %s \n",str);
 }
/*char *p=rsp;
while(*p != NULL)
{
	if(*p==':')
		*p=',';
	p++;
}*/
 printf("File contents\n" );
 printf("%s" , rsp);
  fclose (pFile);
  return 0;
}
