//Author:Floriana Melania Munteanu
//Student Number:20349023
#include <stdio.h>
#include "printBoard.h"
#include "checkMove.h"

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
    //printBoard(player1.name, player2.name);

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

    /*for(i=0; i<8; i++){
        for(j=0; j<8; j++){
            printf("%c ", board.arr[i][j]);
        }
        printf("\n");
    }*/

    //play the game
    int k = -1, m, count;

    while (player1.score + player2.score < 64){
        printf("Player 1:\n");

        do{
            printf("Choose a move: ");
            scanf("%c%d", &board.letter, &board.number);
            i = (int)(board.letter) - 97;
            j = board.number - 1;
            k = checkMove(i,j,board.arr, player1.disc, player2.disc);
        }while(k == -1);

        board.arr[i][j] = player1.disc;
        count = 0;

        for(m = i + 1; m < k; m++){
            board.arr[m][j] = player1.disc;
            count++;
        }

        player1.score += count;
        player2.score -= count;

        printf("Player 2:\n");

        do{
            printf("Choose a move: ");
            scanf("%c%d", &board.letter, &board.number);
            i = (int)(board.letter) - 97;
            j = board.number - 1;
            k = checkMove(i,j,board.arr, player2.disc, player1.disc);
        }while(k == -1);

        board.arr[i][j] = player2.disc;
        count = 0;

        for(m = i + 1; m < k; m++){
            board.arr[m][j] = player2.disc;
            count++;
        }

        player2.score += count;
        player1.score -= count;
    }

    //determine winner
    //print out the results
    //print the result to a file


    return 0;
}
