/* Game of life
 The "game of life" is an old and very simple approach of simulating evolution
 A 2-dimensional field of cells is regarded with a cell being either empty/dead (0) or occupied/alive (1)
 The intial state can be chosen e.g. manually or using some random operations.
 
 The further evolution is governed by the following rules:
 
 Every cell interacts with its eight neighbours, which are the cells that are directly horizontally, vertically, or diagonally adjacent.
 At each step in time, the following transitions occur:
 1. Any live cell with fewer than two live neighbours dies, as if by needs caused by underpopulation.
 2. Any live cell with more than three live neighbours dies, as if by overcrowding.
 3. Any live cell with two or three live neighbours lives, unchanged, to the next generation.
 4. Any empty/dead cell with exactly three live neighbours cells will be populated with a living cell.
 
 The initial pattern constitutes the 'seed' of the system. The first generation is created by applying the above rules simultaneously to every cell in the seed ó births and deaths happen simultaneously, and the discrete moment at which this happens is sometimes called a tick. (In other words, each generation is a pure function of the one before.)  The rules continue to be applied repeatedly to create further generations.
 
 see: http://en.wikipedia.org/wiki/Conway's_Game_of_Life
 */


// TO DO: Complete the programm such that it simulates the game of life.
//        Do this as teamwork (e.g. in teams with 2 or 3)
//        and benefit from the fact the functions can developed separately and then integrated into the final program.
// TO DO optional 1: extend the program, such that it detects 'stable states', i.e. the system is oscillating between a few states.
// TO DO optional 2: let the program find a start state, such that the system stays alive and unstable for as long as possible
// TO DO optional 3: Create a flicker-free output: Do not print each character separately, but write the output into a string, which is printed all at once
// TO DO opti onal 4: extend the program, such that the content of the cells can be edited by the user.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>


// Global 2-dim-array which contains the cells
#define randX 50
#define randY 30


int rndNumber=8;
char cells[randY][randX];
char longestCellsState[randY][randX];
char maybeLongestCellsState[randY][randX];
char stateBefore[randY][randX];
char stateBeforeBefore[randY][randX];
int countRounds=0;
int countStates=0;
int longestRound=0;
char outputString[(randX+1)*randY];


void initialize_cells()
{
    int i, j;
    for(i=0; i<randY; i++) {
        for(j=0; j<randX; j++) {
            stateBefore[i][j]=0;
            stateBeforeBefore[i][j]=0;
                        int k = rand()%rndNumber;
            if (k>0) {
                cells[i][j]= 0;
            }else{
                cells[i][j]= 1;

            }
            maybeLongestCellsState[i][j]=cells[i][j];

            
        }
    }
}

// TO DO: Write output function to show the cells
void display_cells()
{
    //system("CLS"); // Clear screen - works (at least) on windows console.
    //system("clear");
    printf("\033[2J\033[1;1H");
    
    
    for (int i=0; i<randY; i++) {
        for (int k=0; k<randX; k++) {
            if (cells[i][k]==1) {
                outputString[(i*51)+k]='#';
            }else{
               outputString[(i*51)+k]=' ';
            }
            
        }
        outputString[(i*51-1)+51]='\n';
    }
    printf("States: %d Rounds %d \n",countStates,countRounds);

    printf("%s",outputString);
}



int countAlivedCells(int x,int y){
    int count=0;
    for (int i=0; i<3; i++) {
        for (int k =0; k<3; k++) {
            if ((x-1)+i >=0) {
                if ((y-1)+k >= 0) {
                    if (cells[(x-1)+i][(y-1)+k]==1) {
                        count++;
                    }
                }else{
                    if (cells[(x-1)+i][randX-1]==1) {
                        count++;
                    }
                }
            }else{
                if ((y-1)+k >= 0) {
                    if (cells[randY-1][(y-1)+k]==1) {
                        count++;
                    }
                }else{
                    if (cells[randY-1][randX-1]==1) {
                        count++;
                    }
                }
            }
        }
    }
    if (cells[x][y]==1) {
        count--;
    }
    return count;
}
//1. Any live cell with fewer than two live neighbours dies, as if by needs caused by underpopulation.
//2. Any live cell with more than three live neighbours dies, as if by overcrowding.
//3. Any live cell with two or three live neighbours lives, unchanged, to the next generation.
//4. Any empty/dead cell with exactly three live neighbours cells will be populated with a living cell.
// TO DO: Write a function to calculate the next evolution step
void evolution_step()
{
    // TO DO: Use this array for the calculation of the next step
    char cells_helper[randY][randX];
    
    for (int k=0; k<randY; k++) {
        for (int i=0; i<randX; i++) {
            cells_helper[k][i]=0;
        }
    }
    
    for (int k=0; k<randY; k++) {
        for (int i=0; i<randX; i++) {
            if (cells[k][i]==1) {
                if (countAlivedCells(k, i)>3) {
                    cells_helper[k][i]=0;
                }else if (countAlivedCells(k, i)>=2 &&countAlivedCells(k, i)<=3 ){
                    cells_helper[k][i]=1;
                }else{
                     cells_helper[k][i]=0;
                }
            }else{
                if (countAlivedCells(k, i)==3) {
                    cells_helper[k][i]=1;
                }
            }
        }
    }
    for (int i=0; i<randY; i++) {
        for (int k=0; k<randX; k++) {
            cells[i][k] = cells_helper[i][k];
        }
    }
    
}

// TO DO: Write a function that counts the occupied cells
int count_cells()
{
    int count =0;
    for (int i=0; i<randY; i++) {
        for (int k=0; k<randX; k++) {
            if (cells[i][k]) {
                count++;
            }
        }
    }
    return count;
    
}
int checkStableSystem(){
    if (countRounds == 0) {
        for (int i=0; i<randY; i++) {
            for (int k=0; k<randX; k++) {
                stateBeforeBefore[i][k]=cells[i][k];
            }
        }
        countRounds++;
        return 0;
    }
    if (countRounds ==1) {
        for (int i=0; i<randY; i++) {
            for (int k=0; k<randX; k++) {
                stateBefore[i][k]=cells[i][k];
            }
        }
        countRounds++;
        return 0;
    }
    if (countRounds>1) {
        for (int i=0; i<randY; i++) {
            for (int k=0; k<randX; k++) {
                if (stateBeforeBefore[i][k]!=cells[i][k]) {
                    countRounds++;
                    
                    for (int j=0; j<randY; j++) {
                        for (int l=0; l<randX; l++) {
                            stateBeforeBefore[j][l]=stateBefore[j][l];
                            stateBefore[j][l]=cells[j][l];
                        }
                    }
   
                    
                    return 0;
                }
                
            }
        }
        return 1;
    }
    return 0;
}
int saveLongestRound(int round){
    if (longestRound < round) {
        for (int j=0; j<randY; j++) {
            for (int l=0; l<randX; l++) {
                longestCellsState[j][l]=maybeLongestCellsState[j][l];
            }
        }
        longestRound = round;
        printf("new longest road %d",longestRound);
    }
    if (countStates<500) {
        return 0;
    }else{
        return 1;
    }
}


// Main program
int main()
{
    //srand(time(NULL));
    while (1) {
        
        initialize_cells();
        while(1) {
                srand(time(NULL));
           
            display_cells();
          

                     // Leave loop if there are no more occupied cells
            if(count_cells()==0)
                break;
            
            
            evolution_step();
            if (checkStableSystem()) {
                countStates++;
                break;
            }
            if (countRounds > 10000){
               printf("\033[2J\033[1;1H");
                printf("System unstable..");
                printf("\n");
               
                for (int i=0; i<randY; i++) {
                    for (int k=0; k<randX; k++) {
                        if (maybeLongestCellsState[i][k]==1) {
                            outputString[(i*51)+k]='#';
                        }else{
                            outputString[(i*51)+k]=' ';
                        }
                        
                    }
                    outputString[(i*51-1)+51]='\n';
                }
                
                printf("%s",outputString);
                break;
            }

        }
        printf("Press enter");
        getchar();
        
        
        
        
        if (saveLongestRound(countRounds)) {
            printf("longestRound is %d and states: %d",longestRound,countStates);
            printf("\n");
            for (int i=0; i<randY; i++) {
                for (int k=0; k<randX; k++) {
                    printf("%d",longestCellsState[i][k]);
                }
                printf("\n");
            }
            break;
        }else{
            countRounds=0;
        }
           }
   
}
