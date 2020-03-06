#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

typedef struct
{
    int age;
    double height;
    char name[64];
} Person;

void printPersonInfo(Person *p)
{
    printf("Person: %s, %d, %f\n", p->name, p->age, p->height);
}

void readPersonData(Person *pp)
{
    
    printf("Idade da pessoa: ");
    scanf("%d", &(pp->age));
    printf("Altura da pessoa: ");
    scanf("%lf", &(pp->height));
    printf("Nome da pessoa: ");
    scanf("%*c%[^\n]" , pp->name);

}


int main (int argc, char *argv[])
{
    FILE *fp = NULL;
    Person p;

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
    Person pessoas[1000];
    int contador = 0;

    int nPessoas = fread(pessoas, sizeof(Person), 1000, fp);
    fclose(fp);

    int num_pessoas = 0;
    printf("Quantas pessoas quer armazenar? ");
    scanf("%d", &num_pessoas);
    for(int i = 0 ; i < num_pessoas ; i++)
    {    
        printf("Pessoa número %d \n", i+1);
        readPersonData(&pessoas[nPessoas]);;
        nPessoas++;
    }

    fp = fopen(argv[1], "wb");
    fwrite(pessoas, sizeof(Person), nPessoas, fp);
    fclose(fp);

    

    return EXIT_SUCCESS;
}
