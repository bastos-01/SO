#include <stdio.h>
#include <stdlib.h>



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
    int i, numSize;
    int *numbers;

    numSize = argc - 1;

    /* Memory allocation for all the numbers in the arguments */
    numbers = (int *) malloc(sizeof(int) * numSize);


    for(i = 0 ; i < numSize ; i++)
    {
        numbers[i] = atoi(argv[i+1]);
    }

    /* void qsort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *)); 
         The qsort() function sorts an array with nmemb elements of size size.*/
    qsort(numbers, numSize, sizeof(int), compareInts);

    printf("Sorted numbers: \n");
    for(i = 0 ; i < numSize ; i++)
    {
        printf("%d\n", numbers[i]);
    }

    return EXIT_SUCCESS;
}
