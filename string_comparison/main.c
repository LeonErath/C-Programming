 /* Compare two strings */
// TO DO 1: This program does not always give the correct results. What is the problem? Correct it!
// TO DO 2: Adapt the comparison such that it can be used for providing an ordering e.g. for phone books

#include <stdio.h>

int main()
{
    char s1[100], s2[100];
    int i, flag;
    
    printf("Please enter string 1:\n");
    scanf(" %s",s1);
    printf("Please enter string 2:\n");
    scanf(" %s",s2);

    
    flag=i=0;
    
    // stop dazu da um die Schleife zu stoppen
    int stop=0;
    
    // Schleife geht solange bis s1 und s2 gleich 0 ist
    while((s1[i]!=0 || s2[i]!= 0) &&stop==0)
    {
        // Vergleicht die einzelnen Buchstaben
        if(s1[i]!=s2[i]){
            flag=1;
            printf("\n\nSortierte Reihenfolge:\n");
            // Guckt welcher Buchstabe größer ist als der andere
            if (s1[i]<s2[i]) {
                 printf("%s\n%s",s1,s2);
            }else{
                printf("%s\n%s",s2,s1);
   
            }
            // Schleife wird gestoppt
            stop=1;
            
        }
        i=i+1;
    }
    
    if (flag == 0) {
        printf("Namen sind gleich");
    }
    printf("\n\n");

   }
