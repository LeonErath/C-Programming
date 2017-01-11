/* hexdump.c
 A Hexdump prints the content of some memory area in hexadecimal format.
 
 TO DO 1: Have a look at the following program. How does it work?
            converts a number to a hexadecimal number
 TO DO 2: Extend the program such that it shows 16 values in a row and puts the memory address at the beginning
 TO DO 3: Add other data structures and show how they maintain their data
 (or copy the hexdump to your other programs and call it from there)
 TO DO 4: Use malloc to allocate memory and hexdump it.
 TO DO 5: What happens if you call hexdump with arbitrary numbers, e.g. hexdump(10000,10); Why?
            doesn't work
 TO DO 6: What happens if you call hexdump("Hello",6); Why?
            strings are arrays of characters
            hexadump converts the ascii characters in hexadecimal numbers
 TO DO 7: Do a hexdump(hexdump, 100). What might that mean? What happens if you try to change values in this address range?
 TO DO 8: Optional: Hexdumps often also show the memory content as ascii characters in an additional column.
 Extend the program accordingly.
 
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// Hexdump function
void hexdump(void *adr, int length)
{
    int i;
    unsigned char *c_adr;
    
    for(i=0; i<length; i++) {
        if (i%4 == 0) {
            // prints the decimal number as hexadecimal number
            printf("\n%d ",(char *)adr);
        }
        printf("%4x",*(unsigned char *)adr);
        
        // Increment using char pointer (i.e. byte increments)
        c_adr=(unsigned char *)adr;
        // Adress jumps always 8 bit and int has 32 bit
        c_adr++;
        
        adr=(void *)c_adr;
    }
    printf("\n");
}

// Test code to call hexdump
int main()
{
    // char c[]= {10,'v',1,'a',2};
    // double b[]= {10.1,20.23,13.3};
    // int a[]={ 1, 8,10,12,200,425,1000};
    
    // Functionpointer which points on the function hexdump
    //void (*func)(void*,int) = hexdump;
    //(*func)(func,100);
    

    // Hexdump with allocated memory
    // int *ptr;
    // ptr = malloc(100*sizeof(int));
    // hexdump(ptr, 100);
    

    
    // printf("Integer arry with Hexdump:");
    // hexdump(a,sizeof(a));
    // printf("\nDouble arry with Hexdump:");
    // hexdump(b,sizeof(b));
    // printf("\nChar arry with Hexdump:");
    // hexdump(c,sizeof(c));
    getchar();
}

