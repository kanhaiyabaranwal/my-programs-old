/* fscanf example */
#include <stdio.h>

int main ()
{
  char str [80];
  char rsp [80];
  float f;
  FILE * pFile;

  pFile = fopen ("myfile.txt","w+");
  fprintf (pFile, "%s", "PI\n");
  fprintf (pFile, "%s", "SI is also good going");
  rewind (pFile);
  //fscanf (pFile, "%f", &f);
	memset(rsp,NULL, 80);	
 while ( !feof(pFile)  )
 {
	if ( fgets (str , 100 , pFile) != NULL )
  		sprintf (rsp,"%s count# %s",rsp,str);
	break;
  //fscanf (pFile, "%s", str);
  //printf ("I have read: %s \n",str);
 }
 printf("File contents:%s" , rsp);
  fclose (pFile);
  return 0;
}
