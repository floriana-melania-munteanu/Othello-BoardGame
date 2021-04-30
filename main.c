//Author:Floriana Melania Munteanu
//Student Number:20349023
#include <stdio.h>
#include "printBoard.h"
#include "checkMove.h"
int checkMove (int i, int j, char playerDisc, char opponentDisc);
//initialise the board
struct board{
    char letter;
    int number;
    char arr[8][8];
};
//initialise the players
struct player{
    char name[20];
    int score;
    char disc;
};

struct player player1, player2;
struct board board;

int main() {

    int i, j;

    printf("\t*** Welcome to Othello! ***\n");

    //initialise the players names and scores
    printf("Enter name of Player 1 (Black):");
    scanf("%20s", player1.name);
    player1.disc = 'B';
    player1.score = 2;
    printf("Enter name of Player 2 (White):");
    scanf("%20s", player2.name);
    player2.disc = 'W';
    player2.score = 2;

    //print out the board
    printf("\n\tScore: %s (Black) 2:2 %s (White)\n", player1.name, player2.name);
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

    //initialise the board
    for(i=0; i<8; i++){
        for(j=0; j<8; j++){
            board.arr[i][j] = '*';
        }
    }
    board.arr[3][3] = 'W';
    board.arr[4][3] = 'B';
    board.arr[3][4] = 'B';
    board.arr[4][4] = 'W';


    //play the game
    int k;

    while (player1.score + player2.score < 64){
        k = -1;
        while (k == -1){
            printf("Player 1:\n");
            printf("Choose a move:");
            scanf("%1s%d", &board.letter, &board.number);
            i = board.number - 1;
            j = (int)(board.letter - 97);
            k = checkMove(i,j, player1.disc, player2.disc);
            //printf("K = %d\n", k);
        }

        printBoard(board.arr);

        printf("k = %d\n", k);
        player1.score += k;
        player2.score -= (k-1);
        printf("Player 1 score %d\nPlayer 2 score %d\n", player1.score, player2.score);

        if(player1.score + player2.score < 64){
            k = -1;
            while (k == -1){
                printf("Player 2:\n");
                printf("Choose a move:");
                scanf("%1s%d", &board.letter, &board.number);
                i = board.number - 1;
                j = (int)(board.letter) - 97;
                k = checkMove(i,j, player2.disc, player1.disc);
            }

            printBoard(board.arr);

            printf("k = %d\n", k);
            player2.score += k;
            player1.score -= (k-1);
            printf("Player 1 score %d\nPlayer 2 score %d\n", player1.score, player2.score);
        }
    }

    //determine winner and print out the results
    if (player1.score > player2.score){
        printf("Player 1 (%s) wins!\n", player1.name);
        printf("The winning score is %d.\n", player1.score);
    }
    else if (player1.score < player2.score){
        printf("Player 2 (%s) wins!\n", player2.name);
        printf("The winning score is %d.\n", player2.score);
    }
    else if (player1.score == player2.score){
        printf("It's a tie. Nobody wins!");
    }
    //print out the final board
    //print the result to a file

}

int checkMove (int i, int j, char playerDisc, char opponentDisc) {
    int k, l, m, n;
    int count;
    if (board.arr[i][j] == '*') {
        //check to the right
        if (board.arr[i][j+1] == opponentDisc) {
            k = j + 2;
            while (board.arr[i][k] != playerDisc && k < 8) {
                k++;
            }
            if (board.arr[i][k] == playerDisc) {
                board.arr[i][j] = playerDisc;
                count = 0;
                count++;
                for(m = j + 1; m < k; m++){
                    board.arr[i][m] = playerDisc;
                    count++;
                }
                return count;
            }
        }
        //check to the left
        else if (board.arr[i][j-1] == opponentDisc){
            k = j-2;
            while (board.arr[i][k] != playerDisc && k >= 0) {
                k--;
            }
            if(board.arr[i][k] == playerDisc){
                board.arr[i][j] = playerDisc;
                count = 0;
                count++;
                for(m = j - 1; m >= k; m--){
                    board.arr[i][m] = playerDisc;
                    count++;
                }
                return count;
            }
        }
        //check above
        else if (board.arr[i-1][j] == opponentDisc){
            k = i-2;
            while (board.arr[k][j] != playerDisc && k >= 0){
                k--;
            }
            if(board.arr[k][j] == playerDisc){
                board.arr[i][j] = playerDisc;
                count = 0;
                count++;
                for(m = i - 1; m < k; m--){
                    board.arr[m][j] = playerDisc;
                    count++;
                }
                return count;
            }
        }
        //check below
        else if (board.arr[i+1][j] == opponentDisc){
            k = i+2;
            while(board.arr[k][j] != playerDisc && k < 8){
                k++;
            }
            if(board.arr[k][j] == playerDisc){
                board.arr[i][j] = playerDisc;
                count = 0;
                count++;
                for(m = i+1; m < k; m++){
                    board.arr[m][j] = playerDisc;
                    count++;
                }
                return count;
            }
        }
        //check upper right corner
        else if (board.arr[i-1][j+1] == opponentDisc){
            k = i-2;
            l = j+2;
            while (board.arr[k][l] != playerDisc && k >= 0 && l<8){
                k--;
                l++;
            }
            if(board.arr[k][l] == playerDisc){
                board.arr[i][j] = playerDisc;
                count = 0;
                count++;
                m = i - 1;
                n = j + 1;
                while(m < k && n < l){
                    board.arr[m][n] = playerDisc;
                    count++;
                    m--;
                    n++;
                }
                return count;
            }
        }
        //check upper left
        else if (board.arr[i-1][j-1] == opponentDisc){
            k = i-2;
            l = j-2;
            while(board.arr[k][l] != playerDisc && k >= 0 && l >= 8){
                k--;
                l--;
            }
            if (board.arr[k][l] == playerDisc){
                board.arr[i][j] = playerDisc;
                count = 0;
                count++;
                m = i-1;
                n = j-1;
                while (m < k && n < l){
                    board.arr[m][n] = playerDisc;
                    count++;
                    m--;
                    n--;
                }
                return count;
            }
        }
        //check lower right
        else if (board.arr[i+1][j+1] == opponentDisc){
            k = i + 2;
            l = j + 2;
            while(board.arr[k][l] != playerDisc && k < 8 && l < 8){
                k++;
                l++;
            }
            if (board.arr[k][l] == playerDisc){
                board.arr[i][j] = playerDisc;
                count = 0;
                count++;
                m = i+1;
                n = j+1;
                while(m < k && n < l){
                    board.arr[m][n] = playerDisc;
                    count++;
                    m++;
                    n++;
                }
                return count;
            }
        }
        //check lower left
        else if (board.arr[i+1][j-1] == opponentDisc){
            k = i+2;
            l = j-2;
            while(board.arr[k][l] != playerDisc && k < 8 && l >= 0){
                k++;
                j--;
            }
            if (board.arr[k][l] == playerDisc){
                board.arr[i][j] = playerDisc;
                count = 0;
                count++;
                m = i + 1;
                n = j - 1;
                while (m < k && n < l){
                    board.arr[m][n] = playerDisc;
                    count++;
                    m++;
                    n--;
                }
                return count;
            }
        }
        else{
            printf("Invalid move!");
            return -1;
        }
    }
}