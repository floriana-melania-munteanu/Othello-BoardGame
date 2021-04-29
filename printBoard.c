#include "printBoard.h"
#include <stdio.h>
void printBoard (char name1[20], char name2[20]){
    int i, j;
    printf("\n\tScore: %s (Black) 2:2 %s (White)\n", name1, name2);
    for(i = 0; i < 1; i++){
        for(j = 0; j < 3; j++){
            printf("\t    --- --- --- --- --- --- --- ---\n");
            printf("\t%d  |   |   |   |   |   |   |   |   |\n", j+1);
        }
        printf("\t    --- --- --- --- --- --- --- ---\n");
        printf("\t%d  |   |   |   | W | B |   |   |   |\n", j+1);
        printf("\t    --- --- --- --- --- --- --- ---\n");
        printf("\t%d  |   |   |   | B | W |   |   |   |\n", j+2);
    }
    for(j = 0; j < 3; j++){
        printf("\t    --- --- --- --- --- --- --- ---\n");
        printf("\t%d  |   |   |   |   |   |   |   |   |\n", j+6);
    }
    printf("\t    --- --- --- --- --- --- --- ---\n");
    printf("\t     a   b   c   d   e   f   g   h  \n");
}