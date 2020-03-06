#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LINEMAXSIZE 80 /* or other suitable maximum line size */


/* SUGESTÂO: utilize as páginas do manual para conhecer mais sobre as funções usadas:
 man qsort
*/

int compareInts(const void *px1, const void *px2)
{
    int x1 = *((int *)px1);
    int x2 = *((int *)px2);
    return(x1 < x2 ? -1 : 1);
}

int main(int argc, char *argv[])
{
    FILE *fp = NULL;
    char line [LINEMAXSIZE]; 

    if( argc != 2)
    {
        printf("USAGE: %s fileName\n", argv[0]);
        return EXIT_FAILURE;
    }

    fp = fopen(argv[1], "r");
    if( fp == NULL )
    {
        perror ("Error opening file!");
        return EXIT_FAILURE;
    }
    int contador = 0;
    while( fgets(line, sizeof(line), fp) != NULL )
    {
        contador++;
    }
    fclose(fp);


    fp = fopen(argv[1], "r");

    int valores[contador];
    int num_line = 0;
    while( fgets(line, sizeof(line), fp) != NULL )
    {
        valores[num_line] = atoi(line);
        num_line++;
    }

    printf("File Numbers: \n");
    for(int i = 0 ; i < num_line ; i++)
    {
        printf("%d\n", valores[i]);
    }

    /* void qsort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *)); 
         The qsort() function sorts an array with nmemb elements of size size.*/
    qsort(valores, num_line, sizeof(int), compareInts);

    printf("Sorted numbers: \n");
    for(int i = 0 ; i < num_line ; i++)
    {
        printf("%d\n", valores[i]);
    }   
    fclose(fp);
    return EXIT_SUCCESS;
}