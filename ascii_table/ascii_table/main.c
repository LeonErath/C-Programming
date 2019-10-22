/* ascii_table.c draws a table of all visible ASCII characters */
#include <stdio.h>

int main()
{
    int i, j=0;
    
    //show the visible elements of ASCII table
    for(i=33; i<127; i++)
    {
        if(i<100){
            printf("%d = ", i);
            printf("%c  | ", i);
            j++;
        }
        else{
            printf("%d = ", i);
            printf("%c | ", i);
            j++;
        }
        
        if(j==10){
            printf("\n");
            j=0;
        }
    }
    printf("32 = %cspace%c", 40, 41);
}
