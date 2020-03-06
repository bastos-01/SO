#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
int main(int argc, char *argv[])
{
    int opt;
  
    while ((opt = getopt(argc, argv, "ab")) != -1)
    {
        switch (opt)
        {
            case 'a':
                printf("sop");
                break;
            case 'b':
                break;
                /* If getopt() finds an option character in argv that was not included in
                  optstring, or if it detects a missing option argument, it returns '?'
                 */
            default: /* '?' */
                fprintf(stderr, "Usage: %s [-t nsecs] [-n] name\n",
                        argv[0]);
                exit(EXIT_FAILURE);
        }
    }

   

    return EXIT_SUCCESS;
}