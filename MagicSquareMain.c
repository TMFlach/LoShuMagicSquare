#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

bool isMagic(int square[3][3]);
void printArray(int square[3][3]);
void shuffleArray(int square[3][3]);
//create main function for Lo Shu Magic Square
int main() {
    time_t t;
    srand((unsigned) time(&t));
    int square[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int counter = 0;
    while(!(isMagic(square))) {
        counter++;
        shuffleArray(square);
    }
    printArray(square);
    printf("\nFound after %d tries.\n", counter);
}
//create array shuffler function (It will be assumed that an 3x3 with values 1-9 will be created in main beforehand)
void shuffleArray(int square[3][3]) {
    
    for(int row = 0; row < 3; row++) {
        for(int col = 0; col < 3; col++) {
            int x = rand() % 3;
            int y = rand() % 3;
            int swap = square[row][col];
            square[row][col] = square[x][y];
            square[x][y] = swap;
        }
    }
}
//create function to test whether an array is a Lo Shu Magic Square
bool isMagic(int square[3][3]) {
    for(int row = 0; row < 3; row++) { //check rows to see if they add up to 15.
        if((square[row][0] + square[row][1] + square[row][2]) != 15) {
            return false;
        }
    }
    for(int col = 0; col < 3; col++) { //check columns to see if they add up to 15.
        if((square[0][col] + square[1][col] + square[2][col]) != 15) {
            return false;
        }
    }
    if( (square[0][0] + square[1][1] + square[2][2]) != 15 || //check diagonals
        (square[0][2] + square[1][1] + square[2][0]) != 15) {
            return false;
        }
    //otherwise it is a magic square.
    return true;
}

//create print array function
void printArray(int square[3][3]) {
    for(int row = 0; row < 3; row++) {
        printf("\n");
        for(int col = 0; col < 3; col++) {
            printf("%d ", square[row][col]);
        }
    }
}