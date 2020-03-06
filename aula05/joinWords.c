#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv){
    
    //char *str[argc];
    char teste[1024]="";

    for(int i=1;i<argc;i++){
        strcat(teste, argv[i]);
        //str[i] = argv[i];
        //printf("%s", str[i]);
    }
   
    printf("%s ", teste);
     printf("\n");

    return EXIT_SUCCESS;
}