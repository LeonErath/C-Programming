//
//  main.c
//  workflow
//
//  Created by Leon Erath on 26.10.16.
//  Copyright © 2016 Leon Erath. All rights reserved.
//

#include <stdio.h>

int main() {
    char c, old_c;
    //short s, old_s;
    //int i, old_i;
    //long l, old_l;
    
    c=0;
    
    while(1) {  // repeat the following code in { .... } endless
        old_c=c; // remember previous value
        c=c+1;   // increase c by 1, you may also use the short form: c++;
        if(old_c>c) { // execute the following code in { ... } if condition is true
            printf("char  overflow %d -> %d \n", old_c, c);
        }
        // printf format strings:
        // char, short, int: "%d"
        // long: "%ld"
        // unsigned int: "%u"
    
}
}
