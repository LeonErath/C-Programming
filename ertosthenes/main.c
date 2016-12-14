/* prime sieve of Eratosthenes */
// TO DO 1: The program seems to work, but look carefully at the results -> There is a (typical) bug
// TO DO 2: Extend it such that the maximum number n to be calculated can be entered by the user
//          Use scanf("%d", &n)
// TO DO 3: What does this mean for the array? How should the program be adapted to work reliably?

#include <stdio.h>

#define Max 100



int main()
{
    printf("*********************************************************************\n\n");
    int i, j, n;
    printf("Enter a postive number: ");
    scanf("%d", &n);
    unsigned char is_prime[Max];
    if (n<100) {
        /* Initialize Array */
        for(i=0; i<n; i=i+1)
            is_prime[i]=1;
        
        for (i = 2; i <n; i=i+1)
            for (j= 2*i; j < n; j=j+i)
                is_prime[j] = 0;
        
        printf("\n\nPrime numbers are: ");
        for(i=2; i<n; i=i+1)
            if(is_prime[i]>0)
                printf("%d ",i);
     
    }
       printf("\n\n*********************************************************************\n\n");
}
