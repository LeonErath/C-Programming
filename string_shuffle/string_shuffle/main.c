/* Shuffles a string */
// TO DO 1: Extend the program such that spaces in the strings are not moved/shuffled.
// TO DO 2: Extend the program such that the first characters of names are not shuffled
//          (a name may consist of several parts separated by spaces).
// TO DO 3: Extend the program such that two names can be entered and shuffling happens between these two
// TO DO 4: How can a user make the program crash? What could be done against that problem?

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char name[100], c;
    char name2[100];
    int i, p1, p2;
    
    printf("Please enter your name:\n");
    scanf(" %[^\n]",name);
    printf("Please enter another name:\n");
    scanf(" %[^\n]",name2);
    
    int k=0;
    
    for(i=0; i<10; i++)
    {
        p1=rand()%strlen(name);
        p2=rand()%strlen(name2);
        if (name[p1]!=' ' && name2[p2]!=' ' &&  p2!=0&& name2[p2-1]!=' '&&p1!=0 && name[p1-1]!=' ') {
            c=name[p1];
            name[p1]=name2[p2];
            name2[p2]=c;
            printf("Hello %s %s\n", name,name2);
        }else{
            i--;
        }
        k++;
        if (k>100) {
            i=10;
            printf("Error");
        }
    }
}  
