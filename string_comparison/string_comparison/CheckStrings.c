/* Compare two strings */
#include <stdio.h>
//"string.h" gibt Funktionen zur Verwendung mit Strings an
#include <string.h>

int main()
{
    char s1[100], s2[100];
    
    //lesen, bis Benutzer "Enter" drückt (\ n)
    printf("Please enter string 1:\n");
    scanf(" %[^\n]",s1);
    printf("Please enter string 2:\n");
    scanf(" %[^\n]",s2);

    //"strcmp" prüft, ob die Namen gleich sind
    if(strcmp(s1, s2)==0) printf("Namen sind gleich");
    else printf("Die Namen sind unterschiedlich");
    printf("\n");
}
