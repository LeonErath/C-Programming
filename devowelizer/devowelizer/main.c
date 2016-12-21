/* devowelizer / revowelizer
 TO DO 1: Extend the program such that it replaces all vowels in the text with other vowels.
 TO DO 2: Extend the program such that the replacement vowel is chosen randomly.
 Hint: List the vowels in an additional array ...
 Use rand() to generate random numbers
 TO DO 3: Modify the programm such that it removes all vowels (and shortens the text accordingly)
 TO DO 4 (optional): Write an encryption/decryption program which encodes texts by defining
 in a table how each character shall be replaced by another one.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// no duplicates in cryptionkey
char cryptionKey[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
// no duplicates in changeChar
char changeChar[] = {'v','w','x','y','z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u'};

int encryptMethode(char txt[]){
    int k=0,i=0;

    printf("\nYour text encrypted:\n");
    while(txt[i]!=0)
    {
        k=0;
        while (k< 26) {
            if (txt[i]==cryptionKey[k]) {
                txt[i]=changeChar[k];
                k=26;
            }
            k++;
        }
        i=i+1;
    }
    printf("%s\n",txt);
    
    return 1;
}
int decryptMethode(char txt[]){
    int k=0,i=0;
    printf("\nYour text decrypted:\n");
    while(txt[i]!=0)
    {
        k=0;
        while (k< 26) {
            if (txt[i]==changeChar[k]) {
                txt[i]=cryptionKey[k];
                k=26;
            }
            k++;
        }
        i=i+1;
    }
    printf("%s\n\n",txt);
    
    return 1;
}

int main()
{
    
    printf("**************************************************************\n\n");
    char txt[1000];

    printf("Please enter your text:\n");
    
    scanf("%[^\n]", txt);
    
    for(int i = 0; txt[i]; i++){
        txt[i] = tolower(txt[i]);
    }
    encryptMethode(txt);
    decryptMethode(txt);
    printf("**************************************************************\n\n");
    
}
