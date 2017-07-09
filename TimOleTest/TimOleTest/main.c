//
//  main.c
//  TimOleTest
//
//  Created by Leon Erath on 24.04.17.
//  Copyright © 2017 Leon Erath. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, const char * argv[]) {

    int zahlengeneriert=0;
    int zahlen[100];  //Array
    int i;
    int eingabe1;
    int programmbeenden=1;
    printf("***********************\n***  DATENANALYSE  ***\n************************\n\n***********************\n***    HAUPTMENUE    ***\n************************\n* 1. DATEN GENERIEREN  *\n* 2. DATEN AUSGEBEN    *\n* 3. DATEN ANALYSIEREN *\n* 4. PROGRAMM BEENDEN  *\n************************\n\n");
    
    while(programmbeenden){         //Hauptmenübildschirm

        fseek(stdin,0,SEEK_END);
        scanf("%d", &eingabe1);
        if (eingabe1 == 4) {programmbeenden=0;}
        if (eingabe1 == 1) {
            zahlengeneriert=1;
            for (i=0; i<=100; i++){
                zahlen[i]=rand()%100;
            }
        }
            
        if (eingabe1 == 2) {
            if (zahlengeneriert==1) {
                for (i=0; i<=100; i++) {
                    printf("%d,", zahlen[i]);
                }
            }
        }
    }
        
    

    return 0;
}
