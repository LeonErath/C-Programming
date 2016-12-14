/* matrices */
// TO DO: Extend the programm such that the result is printed
// TO DO: Extend the programm such that it also calculates the product of the two 3x3 matrices.

#include <stdio.h>

int main()
{
    float m1[3][3]= { { 12, 5.3, 10.0 }, { 5, 10.2, -2 },  { 1, -1, 3 } };
    float m2[3][3]= { { 2.1, -3, 1.5 },  { 10, -12, 3.1 }, { 4, 8.2, -2 } };
    float prod[3][3];

    
    int i, j,k;
    
    for (i=0; i<3; i++)
        for (k=0; k<3; k++)
            prod[i][k]=0;
    
    // 00 = 0.0 * 0.0 + 0.1 * 1.0 + 0.2 * 2.0
    // 01 = 0.0 * 0.1 + 0.1 * 1.1 + 0.2 * 2.1
    // 02 = 0.0 * 0.2 + 0.1 * 1.2 + 0.2 * 2.2
    
    for(i=0; i<3; i=i+1){
        for(j=0; j<3; j=j+1){
            for (k=0; k<3; k++) {
             prod[i][j]+=m1[i][k]*m2[k][j];
            }
           
        }
    }
    
   
    
    
    
    for (i=0; i<3; i++) {
        for (k=0; k<3; k++) {
                for (j=0; j<3; j++) {
                    if (k==0) printf(" %7.2f",m1[i][j]);
                    if (k==1) printf(" %7.2f",m2[i][j]);
                    if (k==2) printf(" %7.2f",prod[i][j]);
                
                }
            if (i != 1) printf("   ");
            if (k==0&&i == 1) printf(" * ");
            if (k==1&&i == 1) printf(" = ");
        }
        printf("\n");
    }
    
    
}
