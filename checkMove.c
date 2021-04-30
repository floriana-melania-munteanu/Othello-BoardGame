#include "checkMove.h"
#include <stdio.h>
/*int checkMove (int i, int j, char arr[8][8], char playerDisc, char opponentDisc){
    int k, l, m, n, o, p, q, r;
    if (arr[i][j] == '*'){
        if(arr[i+1][j] == opponentDisc){
            k = i+2;
            while (arr[k][j] != playerDisc && k < 8) {
                k++;
            }
            if(arr[k][j] == playerDisc){
                printf("Valid move!\n");
                return k;
            }
            /*else{
                printf("Invalid move!\n");
                k = -1;
                return k;
            }*/
        /*}
        else if (arr[i-1][j] == opponentDisc){
            l = i-2;
            while (arr[l][j] != playerDisc && l >= 0) {
                l--;
            }
            if(arr[l][j] == playerDisc){
                printf("Valid move!\n");
                return l;
            }
            /*else{
                printf("Invalid move!\n");
                k = -1;
                return k;
            }*/
        /*}
        else if (arr[i][j-1] == opponentDisc){
            m = j-2;
            while (arr[i][m] != playerDisc && m >= 0){
                m--;
            }
            if(arr[i][m] == playerDisc){
                printf("Valid move!\n");
                return m;
            }
        }
        else if (arr[i][j+1] == opponentDisc){
            n = j+2;
            while (arr[i][n] != playerDisc && n < 8){
                n++;
            }
            if(arr[i][n] == playerDisc){
                printf("Valid move!\n");
                return n;
            }
        }
        else if (arr[i+1][j-1] == opponentDisc){
            o = j-2;
            while (arr[i][m] != playerDisc && j >= 0){
                m--;
            }
            if(arr[i][m] == playerDisc){
                printf("Valid move!\n");
                return m;
            }
        }
    }
    else{
        printf("Invalid move!\n");
        k = -1;
        return k;
    }
}*/