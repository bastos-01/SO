#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv)
{
    if(argc == 4){
        char op = *argv[2];
        /*double num1 = atof(argv[1]);
        double num2 = atof(argv[3]);*/
        char *a1,*a2;
        double num1 = strtod(argv[1], &a1);
        double num2 = strtod(argv[3], &a2);

        double result;
        
        switch (op){

        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case 'x':
            result = num1 * num2;
            break;
        case '/':
            result = num1 / num2;
            break;
        case 'p':
            result = pow(num1, num2);
            break;

        }

        printf("%.2f %c %.2f = %.2f\n", num1,op,num2,result); 

    }else{
         fprintf(stderr, "Número inválido de argumentos\n");
        return EXIT_FAILURE; //echo $? == 1
    }
    return EXIT_SUCCESS; //echo $? == 0
}