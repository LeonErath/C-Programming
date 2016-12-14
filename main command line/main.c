// command line args
// TO DO: Use the command line arguments to modify previous programs from the lecture, e.g.
//        devowelizer: provide a string to be "devowelized"
//        ascii-art: provide x and y
// TO DO: parse the command line arguments: If there is a string "-h" or "-help"
//        print a small help text


#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main(int argc, char *argv[])
{
    int n = 0;
    
    while ( n < argc ) {
        printf("Command line argument %d is %s\n", n+1, argv[n]);
        ++n;
    }
    n = 0;
    
    while ( n < argc ) {
        if (strcmp(argv[n], "-h")==0) {
            printf("\n");
            printf("Helper Text");
        }
        ++n;
    }
    return EXIT_SUCCESS;
}
