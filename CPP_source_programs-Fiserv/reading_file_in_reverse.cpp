#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <ctype.h>
void read_file(FILE *fileptr)
{
   char currentchar = '\0';
   int size = 0;
   fpos_t pos;
   while(true)
   {
		
        while( currentchar != '\n' )
        {
            currentchar = fgetc(fileptr); //printf("%c\n", currentchar);
            fseek(fileptr, -2, SEEK_CUR);
            if( currentchar == '\n') { fseek(fileptr, -2, SEEK_CUR); break; }
            else size++;

        }
        char buffer[size]; fread(buffer, 1, size, fileptr);
        //printf("Length: %d chars\n", size);
        printf("Buffer: %s\n", buffer);
        Sleep(5*1000);
        fflush(fileptr);
        //fflush(stdout);
        fgetpos(fileptr, &pos);
		fseek(fileptr, -1, SEEK_END); /* Seek to END of the file just before EOF */
        
    }
}


    int main()
    {
        //if( argc < 2) { printf("Usage: backwards [filename]\n"); return 1; }
		char filename[]="input.txt";
        FILE *fileptr = fopen(filename, "rb");
        if( fileptr == NULL ) { perror("Error:"); return 1; }

        fseek(fileptr, -1, SEEK_END); /* Seek to END of the file just before EOF */
        read_file(fileptr);
        return 0;
    }
