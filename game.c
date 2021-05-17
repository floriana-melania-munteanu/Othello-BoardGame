#include "game.h"
#include <stdio.h>
#define SIZE 8 //the size of the board

//function definition for counting the valid moves for a player
int validMove (char board[SIZE][SIZE], char playerDisc, char opponentDisc){
    int validMoves_count = 0; //stores the number of valid moves
    int i, j, k, l;

    //go through every square
    for(i = 0; i < SIZE; i++){
        for(j = 0; j < SIZE; j++){
            //if the square isn't empty move to the next
            if(board[i][j] != '*'){
                continue;
            }
            //check if to the right of the square there is an opponent's disc
            if (board[i][j + 1] == opponentDisc){
                //move in the same direction and search for a player's disc
                for (k = j + 2; k < SIZE; k++){
                    //if we find an empty square break, the move isn't valid
                    if(board[i][k] == '*'){
                        break;
                    }
                    //if we find a player's disc the move is valid and increase validMoves_count
                    if(board[i][k] == playerDisc){
                        validMoves_count++;
                        break;
                    }
                    /*else{
                        continue;
                    }*/
                }
            }
            //check to the left of the square, the same way we did for the previous one
            if (board[i][j - 1] == opponentDisc){
                for(k = j - 2; k >= 0; k--){
                    if(board[i][k] == '*'){
                        break;
                    }
                    if(board[i][k] == playerDisc){
                        validMoves_count++;
                        break;
                    }
                    /*else{
                        continue;
                    }*/
                }
            }
            //check above the square
            if (board[i - 1][j] == opponentDisc){
                for (k = i - 2; k >= 0; k--) {
                    if(board[k][j] == '*'){
                        break;
                    }
                    if(board[k][j] == playerDisc){
                        validMoves_count++;
                        break;
                    }
                    /*else{
                        continue;
                    }*/
                }
            }
            //check below the square
            if (board[i + 1][j] == opponentDisc){
                for(k = i + 2; k<SIZE; k++){
                    if(board[k][j] == '*'){
                        break;
                    }
                    if(board[k][j] == playerDisc){
                        validMoves_count++;
                        break;
                    }
                    /*else{
                        continue;
                    }*/
                }
            }
            //check the upper right corner
            if (board[i - 1][j + 1] == opponentDisc){
                k = i - 2;
                l = j + 2;
                while (k >= 0 && l < SIZE){
                    if(board[k][l] == '*'){
                        break;
                    }
                    if(board[k][l] == playerDisc){
                        validMoves_count++;
                        break;
                    }
                    else{
                        k--;
                        l++;
                    }
                }
            }
            //check the upper left corner
            if (board[i - 1][j - 1] == opponentDisc){
                k = i - 2;
                l = j - 2;
                while(k >= 0 && l >= 0){
                    if(board[k][l] == '*'){
                        break;
                    }
                    if(board[k][l] == playerDisc){
                        validMoves_count++;
                        break;
                    }
                    else{
                        k--;
                        l--;
                    }
                }
            }
            //check the lower right corner
            if (board[i + 1][j + 1] == opponentDisc){
                k = i + 2;
                l = j + 2;
                while(k < SIZE && l < SIZE){
                    if(board[k][l] == '*'){
                        break;
                    }
                    if(board[k][l] == playerDisc){
                        validMoves_count++;
                        break;
                    }
                    else{
                        k++;
                        l++;
                    }
                }
            }
            //check the lower left corner
            if (board[i + 1][j - 1] == opponentDisc){
                k = i + 2;
                l = j - 2;
                while(k < SIZE && l >= 0){
                    if(board[k][l] == '*'){
                        break;
                    }
                    if(board[k][l] == playerDisc){
                        validMoves_count++;
                        break;
                    }
                    else{
                        k++;
                        l--;
                    }
                }
            }
        }
    }
    //return the number of valid moves
    return validMoves_count;
}

//function definition for checking if the move entered by the player is valid and if so implementing it
int implementMove(char board[SIZE][SIZE], int i, int j, char playerDisc, char opponentDisc){
    int k, l, m, n;
    int count = 0; //stores the number of discs turned

    //if the square chosen by the player is empty
    if(board[i][j] == '*'){
        //check if to the right of the square there is an opponent's disc
        if(board[i][j + 1] == opponentDisc){
            k = j + 2;
            //search in the same direction for a player's disc
            while (k < SIZE){
                //if we encounter an empty square no possible move to the right of the square, go to the next check
                if(board[i][k] == '*'){
                    break;
                }
                //if we encounter a player's disc, there is a possible move to the right of the square
                if(board[i][k] == playerDisc){
                    //place a player's disc on the square the player chose
                    board[i][j] = playerDisc;
                    //starting with the next square until the one where we found another disc of the player's
                    for(n = j + 1; n < k; n++){
                        board[i][n] = playerDisc; //turn all the disc we encounter
                        count++; //increase the number of turned discs
                    }
                    break;
                }
                k++;
            }

        }
        //check to the left of the square, the same as the first one
        if (board[i][j - 1] == opponentDisc){
            k = j - 2;
            while(k >= 0){
                if(board[i][k] == '*'){
                    break;
                }
                if(board[i][k] == playerDisc){
                    board[i][j] = playerDisc;
                    for(n = j - 1; n > k; n--){
                        board[i][n] = playerDisc;
                        count++;
                    }
                    break;
                }
                k--;
            }
        }
        //check above the square, the same as the first one
        if (board[i - 1][j] == opponentDisc){
            k = i - 2;
            while(k >= 0){
                if(board[k][j] == '*'){
                    break;
                }
                if(board[k][j] == playerDisc){
                    board[i][j] = playerDisc;
                    for(m = i - 1; m > k; m--){
                        board[m][j] = playerDisc;
                        count++;
                    }
                    break;
                }
                k--;
            }
        }
        //check below the square, the same as the first one
        if (board[i + 1][j] == opponentDisc){
            k = i + 2;
            while(k < SIZE){
                if(board[k][j] == '*'){
                    break;
                }
                if(board[k][j] == playerDisc){
                    board[i][j] = playerDisc;
                    for(m = i + 1; m < k; m++){
                        board[m][j] = playerDisc;
                        count++;
                    }
                    break;
                }
                k++;
            }
        }
        //check the upper right corner of the square, the same as the first one
        if (board[i - 1][j + 1] == opponentDisc){
            k = i - 2;
            l = j + 2;
            while(k >= 0 && l < SIZE){
                if(board[k][l] == '*'){
                    break;
                }
                if(board[k][l] == playerDisc){
                    board[i][j] = playerDisc;
                    m = i - 1;
                    n = j + 1;
                    while (m > k && n < l){
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
        //check the upper left corner of the square, the same as the first one
        if (board[i - 1][j - 1] == opponentDisc){
            k = i - 2;
            l = j - 2;
            while(k >= 0 && l >= 0){
                if (board[k][l] == '*') {
                    break;
                }
                if(board[k][l] == playerDisc){
                    board[i][j] = playerDisc;
                    m = i - 1;
                    n = j - 1;
                    while (m > k && n > l){
                        board[m][n] = playerDisc;
                        count++;
                        m--;
                        n--;
                    }
                    break;
                }
                k--;
                l--;
            }
        }
        //check the lower right corner of the square, the same as the first one
        if (board[i + 1][j + 1] == opponentDisc){
            k = i + 2;
            l = j + 2;
            while(k < SIZE && l < SIZE){
                if(board[k][l] == '*'){
                    break;
                }
                if (board[k][l] == playerDisc){
                    board[i][j] = playerDisc;
                    m = i + 1;
                    n = j + 1;
                    while(m < k && n < l){
                        board[m][n] = playerDisc;
                        count++;
                        m++;
                        n++;
                    }
                    break;
                }
                k++;
                l++;
            }
        }
        //check the lower left corner of the square, the same as the first one
        if (board[i + 1][j - 1] == opponentDisc){
            k = i + 2;
            l = j - 2;
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
                    break;
                }
                k++;
                j--;
            }
        }
        //if the count == 0 it means the move isn't valid
        if(count == 0){
            printf("Invalid move! Enter another move:");
            return -1;
        }
    }
    //if the square isn't empty then the move isn't valid
    else {
        printf("Invalid move! Enter another move:");
        return -1;
    }
    //return the number of discs turned
    return count;
}