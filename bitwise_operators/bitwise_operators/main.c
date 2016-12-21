/* bitwise_operators.c binary operations */
/* TO DO 1: Something is wrong with the output
 Hint: put the output first into an additional variable m,
 use bitwise operators and count the digits */
/* TO DO 2: A second number should be entered and
 both numbers should be combined with the various bitwise
 operators before providing the output */
/* TO DO 3: Use signed integers and see how negative numbers
 are presented in binary format */

#include <stdio.h>


// prints a decimal number in binary format
int numberToBinary(unsigned int number){
    unsigned int m=0;
    // nullen zählt die Nullen die vor der erste "1" von der umgedrehten Zahl stehen
    int nullen=0;
    // anfangzuende ist ein Boolean damit nullen hochgezählt werden kann bis zu ersten "1"
    int anfangzuende=0;
    
    
    
    // n=0 als spezial Fall ausgeschlossen
    if (number>0) {
        while(number>0) {
            // m wird immer nach einem durchgang nach links verschoben um 1
            m= m<<1;
            
            if ((number&1)==1) {
                m++;
                if (!anfangzuende) {
                    anfangzuende=1;
                }
            }else{
                if (!anfangzuende) {
                    nullen++;
                }
            }
            number=number >> 1;
        }
        
        
        while (m>0) {
            printf("%d",m&1);
            m=m>>1;
        }
        while (nullen>0) {
            printf("0");
            nullen--;
        }
        
        
    }else{
        printf("0");
    }
    printf("\n\n");
    return 1;
}




int main()
{
    while (1) {
        unsigned int n,k;
        printf("*******************************************************************************************\n\n");
        printf("Please enter an integer number:");
        scanf("%u",&n);
        printf("\n");
        
        printf("Please enter another integer number:");
        scanf("%u",&k);
        printf("\n");
        
        printf("Your first Number is: %d -> ",n);
        numberToBinary(n);
        
        printf("Your second Number is: %d -> ",k);
        numberToBinary(k);
        
        int andVariable= n&k;
        printf("AND: ");
        numberToBinary(andVariable);
        
        int orVariable= n|k;
        printf("OR: ");
        numberToBinary(orVariable);
        
        int xorVariable= n^k;
        printf("XOR: ");
        numberToBinary(xorVariable);
        
        printf("*******************************************************************************************\n\n");
    }
    
   
    
   
}



