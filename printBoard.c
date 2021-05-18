#include "printBoard.h"
#include <stdio.h>
#define SIZE 8 //size of the board

// function definition for printing the board
void printBoard (char arr[SIZE][SIZE]){
    int i, j;
    for(i = 0; i < SIZE; i++){
        printf("%d  ", i + 1);
        for(j = 0; j < SIZE; j++){
            printf("%c ", arr[i][j]);
        }
        printf("\n");
    }
    printf("   a b c d e f g h\n");
}