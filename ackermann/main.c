// Ackermann: calculate the Ackermann function
// The mathematical Ackermann function is defined as follows:
//
//    A(m,n) =   n+1              if m=0
//               A(m-1,1)         if m>0 and n=0
//               A(m-1, A(m,n-1)) if m>0 and n>0
//
// TO DO 1: Write a function that calculates the Ackermann function according to the definition above
//          Test the program with very small values first!
// TO DO 2: Extend the function such that it counts the number of functions calls (use a global variable cnt)
//          Print the function arguments and current count every n function calls.
// TO DO 3: Count the amount of recursively called functions (which are not yet completed) and print them as well
// TO DO 4: Use static variables in ackermann for counting rather than global variables.
// TO DO 5: Optional: Provide values m and n via the command line
//          Allow in addition the option '-v' (verbose), to switch on output of intermediate results
// TO DO 6: Optional: Visualize the current recursion depth with bars of ascii-characters: xxxxxxxxxxxxxxxxxx

#include <stdio.h>
#include <string.h>

int n, m, result;
static int counter =0;
static int ebenen =0;
static int intermediate=0;

int ackermann(int m,int n){
    counter++;
    for (int i=0; i<ebenen; i++) {
        printf("#");
    }
    printf("\n");
    if (m==0) {
        n=n+1;
        if (intermediate) {
        printf("n=n+1  n: %d m: %d\n",n,m);
        }
        //printf("\n");

        return n;
    
    }
    if (m>0 && n==0) {
        //printf("ackermann(m-1,1)\n");
        ebenen++;
        int zwischenergebnis =ackermann(m-1, 1);
        ebenen--;
        return zwischenergebnis;
    }
    if (m>0 && n>0) {
        //printf("ackermann(m-1,ackermann(m,n-1))\n");
        ebenen++;
        int zwischenergebnis = ackermann(m-1, ackermann(m, n-1));
        ebenen--;
        return zwischenergebnis;

    }
   


    return 0;
}



int main(int argc, char *argv[])
{
    int n = 0;
    
    if (argc > 2) {
        m = atoi(argv[1]);
        n = atoi(argv[2]);;
    }else{
       //return 1;
    }
   
    
    
    while ( n < argc ) {
        if (strcmp(argv[n], "-v")==0) {
            intermediate++;
        }
        ++n;
    }
    
    printf("Value for m: ");
    scanf("%d", &m);
    printf("Value for n: ");
    scanf("%d", &n);
    printf("Ergebnis: %d Durchgägne: %d Ebenen: %d\n",ackermann(m, n),counter,ebenen);
    
    
    return 0;
}
