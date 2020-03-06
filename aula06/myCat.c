#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

/* SUGESTÂO: utilize as páginas do manual para conhecer mais sobre as funções usadas:
 man fopen
 man fgets
*/

#define LINEMAXSIZE 80 /* or other suitable maximum line size */


int main(int argc, char *argv[])
{
    FILE *fp = NULL;
    char line [LINEMAXSIZE]; 

    /* Validate number of arguments */
    if( argc != 3 )
    {
        printf("USAGE: %s fileName\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    int x = 1;
    /* Open the file provided as argument */
    while(x< argc){
    errno = 0;
    fp = fopen(argv[x], "r");
    if( fp == NULL )
    {
        perror ("Error opening file!");
        return EXIT_FAILURE;
    }

    /* read all the lines of the file */
    printf("Ficheiro: %s \n", argv[x]);
    int num_line = 1;
    while( fgets(line, sizeof(line), fp) != NULL )
    {
         printf("%d -> %s",num_line, line);
         num_line++;
    }
    printf("\n");
    x++;
    }

    fclose(fp);

    return EXIT_SUCCESS;
}
