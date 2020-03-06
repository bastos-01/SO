#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc == 3)
    {
        int i;

        for(i = 0 ; i < argc ; i++)
        {
            printf("Argument %02d: \"%s\"\n", i, argv[i]);        
        }
    }else{
        fprintf(stderr, "Número inválido de argumentos\n");
        return EXIT_FAILURE; //echo $? == 1
    }
    
    return EXIT_SUCCESS; //echo $? == 0
    
}
