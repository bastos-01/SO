#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    FILE *fp = NULL;
    char line [80]; 

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


    fp = fopen(argv[1], "r");
    int num_palavras=0;
    int char_lower=0;
    int char_upper=0;

    while( fgets(line, sizeof(line), fp) != NULL )
    {
       printf("%s", line);
       for(int i=0; i<length(line); i++){
           printf("teste\n");
            if(isupper(line[i])){
                char_upper++;
            }
            else{
                char_lower++;
            }
       }
       num_palavras++;
    }
    printf("%d\n", num_palavras);
    printf("%d\n", char_upper);
    printf("%d\n", char_lower);

    fclose(fp);
    return EXIT_SUCCESS;
}