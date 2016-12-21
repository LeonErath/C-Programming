/* Variables and memory
 have a look the variables in your previous programs, e.g. address_list.c
 
 TO DO 1: Use sizeof to determine how much memory different types require in memory.
 TO DO 2: Also consider arrays, structs, enums and unions.
 TO DO 3: Use & to determine the addresses of different variables in memory.
 TO DO 4: Can you see a difference of addresses for local and global variables?
 TO DO 5: How are variables sorted in memory (increasing or decreasing addresses)? 
            increasing
 TO DO 6: What about addresses of local variables in recursive functions (e.g. hanoi.c)?
 TO DO 7: Can you find int variables stored at uneven addresses? How do you judge the result?
            variables are only stored on even numbers
 TO DO 8: What is the size of the following struct? Why? Can it be reduced?
            yeah:
                    struct test {char a,c;  int b,d;}; just stores 12 bit instead of 16
 
 */





#include <stdio.h>

struct test {
    char a;
    int b;
    char c;
    int d;
};

union Data {
    int i;
    float f;
    char str[20];
};

enum gender{
    m,f
};

int main(int argc, const char * argv[]) {
    struct test t;
    t.a = 'a';
    t.b = 10;
    t.c = 'A';
    t.d = 11;
    union Data data;
    
    enum gender newgender;
    newgender = m;
    char testArray[20];
    
    printf("Size of *****************************************");
    printf("\n");
    printf("%lu Byte for Struct test", sizeof(t));
    printf("\n");
    printf("%lu Byte for char t.a", sizeof(t.a));
    printf("\n");
    printf("%lu Byte for int t.b", sizeof(t.b));
    printf("\n");
    printf("%lu Byte for char t.c", sizeof(t.c));
    printf("\n");
    printf("%lu Byte for Hello World", sizeof("Hallo Welt"));
    printf("\n");
    printf("%lu Byte for enum gender", sizeof(newgender));
    printf("\n");
    printf("%lu Byte for testArray", sizeof(testArray));
    printf("\n");
    printf("%lu Byte for Union Data", sizeof(data));
    printf("\n");
    printf("Adresses of *************************************");
    printf("\n");
    printf("%p Struct test", &t);
    printf("\n");
    printf("%p char t.a", &t.a);
    printf("\n");
    printf("%p int t.b", &t.b);
    printf("\n");
    printf("%p char t.c", &t.c);
    printf("\n");
    printf("%p enum gender", &newgender);
    printf("\n");
    printf("%p testArray", &testArray);
    printf("\n");
    printf("%p Union Data", &data);
    printf("\n");
    printf("************************************************");
    
    return 0;
}
