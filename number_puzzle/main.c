/* number_puzzle.c
 Write a number puzzle program by completing the TO DOs
 TO DO 1: Initialize the puzzle, such that the numbers 1 to 15 are randomly distributed in the array.
 -1 should mark the empty field.
 TO DO 2: get key and move pieces accordingly (if keystroke is valid)
 TO DO 3: Check, if puzzle is in correct order -> set sorted=1
 TO DO 4: Create a more fancy output, e.g. by creating frames around the numbers
 (Use a special character e.g. a block rather than '*')
 (Also, mark the empty field rather than showing -1)
 
 *********************
 *  1 *  2 *  3 *  4 *
 *********************
 *  5 *  6 *  7 *  8 *
 *********************
 *  9 * 10 * 11 * 12 *
 *********************
 * 13 * 14 * 15 ******
 *********************
 
 TO DO 5, optional: created an automatic, intelligent puzzle solver, which solves the puzzle without user interaction.
 */

#include <stdio.h>
#include <stdlib.h>
 int puzzle[4][4];
searchNumber=1;

int checkPossible(char key){
    for (int i=0; i<4; i++) {
        for (int k=0; k<4; k++) {
            if (puzzle[i][k]==-1) {
                if (key=='w' && i==0) {
                          printf("not possible\n\n");
                    return 0;
                }
                if (key=='s' && i==3) {
                        printf("not possible\n\n");
                    return 0;
                }
                if (key=='a' && k==0) {
                         printf("not possible\n\n");
                    return 0;
                }
                if (key=='d' && k==3) {
                          printf("not possible\n\n");
                    return 0;
                }
            }
        }
    }
    return 1;
}
int switchPositions(char key){
    for (int i=0; i<4; i++) {
        for (int k=0; k<4; k++) {
            if (puzzle[i][k]==-1) {
                switch (key) {
                    case 'd':
                        puzzle[i][k]=puzzle[i][k+1];
                        puzzle[i][k+1] = -1;
                        return 1;
                        break;
                    case 'a':
                        puzzle[i][k]=puzzle[i][k-1];
                        puzzle[i][k-1] = -1;
                        return 1;
                        break;
                    case 'w':
                        puzzle[i][k]=puzzle[i-1][k];
                        puzzle[i-1][k] = -1;
                        return 1;
                        break;
                    case 's':
                        puzzle[i][k]=puzzle[i+1][k];
                        puzzle[i+1][k] = -1;
                        return 1;
                        break;
                        
                    default:
                        break;
                }

                
                
               
                
            }
        }
    }
    
    return 0;
}

int checkCorrectOrder(){
    int count =0;
    for (int i=0; i<4; i++) {
        for (int k=0; k<4; k++) {
            count++;
            if (k==3&&i==3) {
                if (puzzle[i][k]!=-1) {
                    return 0;
                }
            }else{
                if (puzzle[i][k]!=count) {
                    return 0;
                }
            }
           
        }
    }
    return 1;
}
int moveNumber(char key){
    if (checkPossible(key)) {
        switchPositions(key);
        if (checkCorrectOrder()) {
            return 1;
        }else{
            printf("\nnot correct order\n");
        }
    }
    return 0;
}




int main()
{
   
    char key;            // This holds the current key entered by the player.
    char sorted=0;       // This flag marks, if the field is sorted.
    int i, j;
    int rndNumbers[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,-1};
    
    
    
    for (int i=0;i<4; i++) {
        for (int l=0; l<4; l++) {
            int k = rand()%16;
            while (rndNumbers[k]==0) {
                k = rand()%16;
            
            }
            puzzle[i][l]=rndNumbers[k];
            rndNumbers[k]=0;
        }
    }
    
    while(!sorted) {
        int positionX=0,positionY=0;
        /* Output */
        printf("*****************\n");
        for(i=0; i<4; i++) {
            for(j=0; j<4; j++) {
                if (puzzle[i][j]==-1) {
                    printf("****");
                    positionX=j;
                    positionY=i;

                }else{
                    printf("*%2d ", puzzle[i][j]);

                }
            }
            printf("*\n");
            printf("*****************\n");
          
        }
        
        printf("\nmove into direction?");
        
        for (int i=0;i<4; i++) {
            for (int l=0; l<4; l++) {
                if (puzzle[i][l]==searchNumber) {
                    if (i==0) {
                        if (l>0) {
                            // 1 ist oben -> -1 muss links moven
                        }else{
                            // 1 ist oben links
                            //searchNumber++;
                            sorted=1;
                        }
                    }else{
                        if (positionX==l && positionY==i+1) {
                            // ist über 1 -> muss nach unten
                            
                        }else if (positionY==i+1){
                            // -1 über 1
                            if (positionX<l) {
                                // right
                            }else{
                                // left
                            }
                        }else if (positionY>i+1){
                            // muss nach unten
                        }
                        
                        // 1 Muss erstmal nach oben -> -1 muss über 1 moven
                        if (l>0) {
                            // man geht von links
                            if (positionX == l) {
                                // left
                            }else{
                                //up
                            }
                                
                        }else{
                            // man geht von rechts
                            if (positionX == l) {
                                // right
                            }else{
                                //up
                            }
                        }
                    }
                }
            }
        }

        
        if (positionY!= 0) {
            sorted = moveNumber('w');
        }else{
            sorted =1;
        }
      
        
        
        
        
    }
}
