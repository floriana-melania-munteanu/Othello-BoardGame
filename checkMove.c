#include "checkMove.h"
#include <stdio.h>
int checkMove (int i, int j, char arr[8][8], char playerDisc, char opponentDisc){
    int k;
    if (arr[i][j] == '*'){
        if(arr[i+1][j] == opponentDisc){
            for (k = i+2; k < 8; k++){
                if(arr[k][j] == playerDisc){
                    printf("Valid move!\n");
                    return k;
                }
                else{
                    printf("Invalid move!\n");
                    k = -1;
                    return k;
                }
            }
        }
        else{
            printf("Invalid move!\n");
            k = -1;
            return k;
        }
    }
    else{
        printf("Invalid move!\n");
        k = -1;
        return k;
    }
}