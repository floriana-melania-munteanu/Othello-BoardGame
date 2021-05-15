#include "game.h"
#include <stdbool.h>
#include <stdio.h>
#define SIZE 8

int validMove (char board[SIZE][SIZE], char playerDisc, char opponentDisc){
    bool move[SIZE][SIZE] = {false};
    int validMoves_count = 0;
    int i,j,k,l;
    for(i=0; i<SIZE; i++){
        for(j=0; j<SIZE; j++){
            if(board[i][j] != '*'){
                break;
            }
            if(i-2<0 || j-2<0 || i+2>=SIZE || j+2>=SIZE){
                continue;
            }
            if (board[i][j+1] == opponentDisc){
                for (k = j + 2; k < SIZE; k++){
                    if(board[i][k] == '*'){
                        break;
                    }
                    if(board[i][k] == playerDisc){
                        move[i][k] = true;
                        validMoves_count++;
                        break;
                    }
                }
            }
            if (board[i][j-1] == opponentDisc){
                for(k = j-1; k>=0; k--){
                    if(board[i][k] == '*'){
                        break;
                    }
                    if(board[i][k] == playerDisc){
                        move[i][k] = true;
                        validMoves_count++;
                        break;
                    }
                }
            }
            if (board[i-1][j] == opponentDisc){
                for (k = i - 2; k >= 0; k--) {
                    if(board[k][j] == '*'){
                        break;
                    }
                    if(board[k][j] == playerDisc){
                        move[k][j] = true;
                        validMoves_count++;
                        break;
                    }
                }
            }
            if (board[i+1][j] == opponentDisc){
                for(k = i+2; k<SIZE; k++){
                    if(board[k][j] == '*'){
                        break;
                    }
                    if(board[k][j] == playerDisc){
                        move[k][j] = true;
                        validMoves_count++;
                        break;
                    }
                }
            }
            if (board[i-1][j+1] == opponentDisc){
                k = i-2;
                l = j+2;
                while (k >= 0 && l < SIZE){
                    if(board[k][l] == '*'){
                        break;
                    }
                    if(board[k][l] == playerDisc){
                        move[k][l] = true;
                        validMoves_count++;
                        break;
                    }
                    k--;
                    l++;
                }
            }
            if (board[i-1][j-1] == opponentDisc){
                k = i-2;
                l = j-2;
                while(k >= 0 && l >= 0){
                    if(board[k][l] == '*'){
                        break;
                    }
                    if(board[k][l] == playerDisc){
                        move[k][l] = true;
                        validMoves_count++;
                        break;
                    }
                    k--;
                    l--;
                }
            }
            if (board[i+1][j+1] == opponentDisc){
                k = i + 2;
                l = j + 2;
                while(k < SIZE && l < SIZE){
                    if(board[k][l] == '*'){
                        break;
                    }
                    if(board[k][l] == playerDisc){
                        move[k][l] = true;
                        validMoves_count++;
                        break;
                    }
                    k++;
                    l++;
                }
            }
            if (board[i+1][j-1] == opponentDisc){
                k = i+2;
                l = j-2;
                while(k < SIZE && l >= 0){
                    if(board[k][l] == '*'){
                        break;
                    }
                    if(board[k][l] == playerDisc){
                        move[k][l] = true;
                        validMoves_count++;
                        break;
                    }
                    k++;
                    l--;
                }
            }
        }
    }
    return validMoves_count;
}

int implementMove(char board[SIZE][SIZE], int i, int j, char playerDisc, char opponentDisc){
    int k, l, m, n;
    int count = 0;
    if(board[i][j] == '*'){
        //check to the right
        if(board[i][j+1] == opponentDisc){
            k = j+2;
            while (k<SIZE){
                if(board[i][k] == '*'){
                    break;
                }
                if(board[i][k] == playerDisc){
                    board[i][j] = playerDisc;
                    for(n=j+1; n<k; n++){
                        board[i][n] = playerDisc;
                        count++;
                    }
                    break;
                }
                k++;
            }

        }
        //check to the left
        if (board[i][j-1] == opponentDisc){
            k = j-2;
            while(k>=0){
                if(board[i][k] == '*'){
                    break;
                }
                if(board[i][k] == playerDisc){
                    board[i][j] = playerDisc;
                    for(n=j-1; n>k; n--){
                        board[i][n] = playerDisc;
                        count++;
                    }
                    break;
                }
                k--;
            }
        }
        //check above
        if (board[i-1][j] == opponentDisc){
            k = i - 2;
            while(k>=0){
                if(board[k][j] == '*'){
                    break;
                }
                if(board[k][j] == playerDisc){
                    board[i][j] = playerDisc;
                    for(m=i-1; m>k; m--){
                        board[m][j] = playerDisc;
                        count++;
                    }
                    break;
                }
                k--;
            }
        }
        //check below
        if (board[i+1][j] == opponentDisc){
            k = i + 2;
            while(k<SIZE){
                if(board[k][j] == '*'){
                    break;
                }
                if(board[k][j] == playerDisc){
                    board[i][j] = playerDisc;
                    for(m=i+1; m<k; m++){
                        board[m][j] = playerDisc;
                        count++;
                    }
                    break;
                }
                k++;
            }
        }
        //check upper right
        if (board[i-1][j+1] == opponentDisc){
            k = i - 2;
            l = j + 2;
            while(k>=0 && l<SIZE){
                if(board[k][l] == '*'){
                    break;
                }
                if(board[k][l] == playerDisc){
                    board[i][j] = playerDisc;
                    m = i-1;
                    n = j+1;
                    while (m>k && n<l){
                        board[m][n] = playerDisc;
                        count++;
                        m--;
                        n++;
                    }
                    break;
                }
                k--;
                l++;
            }
        }
        //check upper left
        if (board[i-1][j-1] == opponentDisc){
            k = i-2;
            l = j-2;
            while(k >= 0 && l >= 0){
                if (board[k][l] == '*') {
                    break;
                }
                if(board[k][l] == playerDisc){
                    board[i][j] = playerDisc;
                    m = i-1;
                    n = j-1;
                    while (m > k && n > l){
                        board[m][n] = playerDisc;
                        count++;
                        m--;
                        n--;
                    }
                }
                k--;
                l--;
            }
        }
        //check lower right
        if (board[i+1][j+1] == opponentDisc){
            k = i + 2;
            l = j + 2;
            while(k < SIZE && l < SIZE){
                if(board[k][l] == '*'){
                    break;
                }
                if (board[k][l] == playerDisc){
                    board[i][j] = playerDisc;
                    m = i+1;
                    n = j+1;
                    while(m < k && n < l){
                        board[m][n] = playerDisc;
                        count++;
                        m++;
                        n++;
                    }
                }
                k++;
                l++;
            }
        }
        //check lower left
        if (board[i+1][j-1] == opponentDisc){
            k = i+2;
            l = j-2;
            while(k < SIZE && l >= 0){
                if(board[k][l] == '*'){
                    break;
                }
                if (board[k][l] == playerDisc){
                    board[i][j] = playerDisc;
                    m = i + 1;
                    n = j - 1;
                    while (m < k && n > l){
                        board[m][n] = playerDisc;
                        count++;
                        m++;
                        n--;
                    }
                }
                k++;
                j--;
            }
        }
    }
    else {
        printf("Invalid move! Enter another move:\n");
        return -1;
    }

    return count;
