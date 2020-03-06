#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

typedef struct
{
    double y;
    double x;
} Ponto2D;

void printPonto2D(Ponto2D *p)
{
    printf("Person: %lf, %lf\n", p->x, p->y);
}

int main (int argc, char *argv[])
{
    FILE *fp = NULL;
    Ponto2D pt, sum;

    /* Validate number of arguments */
    if(argc != 2)
    {
        printf("USAGE: %s fileName\n", argv[0]);
        return EXIT_FAILURE;
    }

    /* Open the file provided as argument */
    errno = 0;
    fp = fopen(argv[1], "rb");
    if(fp == NULL)
    {
        perror ("Error opening file!");
        return EXIT_FAILURE;
    }

    /* read all the itens of the file */
    while(fread(&pt, sizeof(Ponto2D), 1, fp) == 1)
    {
        sum.x = sum.x + pt.x;
        
        printPonto2D(&pt);
    }

    fclose(fp);

    return EXIT_SUCCESS;
}