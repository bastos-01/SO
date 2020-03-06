#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

typedef struct
{
    int age;
    double height;
    char name[64];
} Person;

void printPersonInfo(Person *p, Person *sum)
{
    printf("Person: %s, %d, %f\n", p->name, p->age, p->height);
    printf("%d", sum->age);
}

int main (int argc, char *argv[])
{
    FILE *fp = NULL;
    Person p, sum = {35, 1.65, "xpto"};

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
    while(fread(&p, sizeof(Person), 1, fp) == 1)
    {
        sum.age += p.age;
        printPersonInfo(&p, &sum);
    }

    fclose(fp);

    return EXIT_SUCCESS;
}
