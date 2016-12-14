// hanoi.c Towers of hanoi
// TO DO: Extend the programm such that it creates a graphical output of the disks on the three rods
//        introduce a function display(), which is called from hanoi()
//        Use global or static variables to keep the status of the disk towers.

#include <stdio.h>
#include <stdlib.h>
#define size 3
#define length 20
int n;

int display[size][length];

void display_cells(int height,int start,int goal,int helper){
    printf("\n");

    for (int k=n-1; k>= 0; k--) {
        for (int i=0; i< size; i++) {
            
            int help = display[i][k];
            int cnt = n;
            
            while (cnt>0) {
                if ((help-cnt) >= 0) {
                    printf("#");
                }else{
                    printf(" ");
                }
                cnt= cnt-1;
            }
            printf(" ");
            
        }
        printf("\n");
        
    }
    printf("\n");

}

int findEmpty(int column){
    for (int k=0; k<n; k++) {
        if (display[column][k]==0) {
            return k;
        }
    }
    return -1;
}
int findLast(int column){
    for (int k=0; k<n; k++) {
        if (display[column][k]==0 && k>0) {
            int helper = display[column][k-1];
            display[column][k-1]=0;
            return helper;
        }
    }
    int helper = display[column][n-1];
    display[column][n-1] =0;
    return helper;
}

void hanoi(int n, int start, int goal, int helper)
{
    if(n>0) {
        hanoi(n-1,start,helper,goal);
        display_cells(n, start, helper, goal);
        display[goal][findEmpty(goal)]=findLast(start);
        

        //printf("move disk from %d to %d\n", start, goal);
        hanoi(n-1,helper,goal,start);
        
    }
  
}

int main()
{
    for (int i=0; i< size; i++) {
        for (int k=0; k< length; k++) {
            display[i][k]=0;
        }
    }
    
    
    printf("How many disks?");
    
    scanf("%d", &n);
    
    for (int i=n; i>0; i--) {
        display[0][n-i]=i;
    }
    
    hanoi(n, 0, 1, 2);

    
    return EXIT_SUCCESS;
}
