//Author:Floriana Melania Munteanu
//Student Number:20349023
#include <stdio.h>
#include <time.h>
#include "printBoard.h"
#include "game.h"
#define SIZE 8

int checkMove (int i, int j, char playerDisc, char opponentDisc);

//define the board struct
struct board{
    char letter;
    int number;
    char arr[SIZE][SIZE];
};
//define the player struct
struct player{
    char name[20];
    int score;
    char disc;
};


struct player player1, player2;
struct board board;

int main(int argc, char *argv[]) {

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

    //initialise the board
    for(i=0; i<SIZE; i++){
        for(j=0; j<SIZE; j++){
            board.arr[i][j] = '*';
        }
    }
    board.arr[3][3] = 'W';
    board.arr[4][3] = 'B';
    board.arr[3][4] = 'B';
    board.arr[4][4] = 'W';

    //print out the board
    printf("\nScore: %s (Black) 2:2 %s (White)\n", player1.name, player2.name);
    printBoard(board.arr);
    /*printf("\n\tScore: %s (Black) 2:2 %s (White)\n", player1.name, player2.name);
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
    printf("\t     a   b   c   d   e   f   g   h  \n");*/


    //play the game
    int k, a, b;

    /*while (player1.score + player2.score < 64){
        k = -1;
        while (k == -1){
            printf("\nPlayer 1 (Black):\n");
            printf("Choose a move:");
            scanf("%1s%d", &board.letter, &board.number);
            i = board.number - 1;
            j = (int)(board.letter - 97);
            k = checkMove(i,j, player1.disc, player2.disc);
            //printf("K = %d\n", k);
        }

        printBoard(board.arr);

        //printf("k = %d\n", k);
        player1.score += k;
        player2.score -= (k-1);
        printf("Player 1 score %d\nPlayer 2 score %d\n", player1.score, player2.score);

        if(player1.score + player2.score < 64){
            k = -1;
            while (k == -1){
                printf("\nPlayer 2 (White):\n");
                printf("Choose a move:");
                scanf("%1s%d", &board.letter, &board.number);
                i = board.number - 1;
                j = (int)(board.letter) - 97;
                k = checkMove(i,j, player2.disc, player1.disc);
            }

            printBoard(board.arr);

            //printf("k = %d\n", k);
            player2.score += k;
            player1.score -= (k-1);
            printf("Player 1 score %d\nPlayer 2 score %d\n", player1.score, player2.score);
        }
    }*/

    //print the result to a file
    FILE *fp;
    if(argc > 1){
        if((fp = fopen(argv[1], "w")) == NULL){
            puts("The file cannot be opened for writing\n");
            return 1;
        }
        else{
            time_t t;
            time(&t);
            fprintf(fp, "Time: %s\n", ctime(&t));
            //determine winner and print out the results
            if (player1.score > player2.score){
                printf("Player 1 (%s) wins!\n", player1.name);
                printf("The winning score is %d.\n", player1.score);
                //add the winner and its score to the file
                fprintf(fp, "%s", player1.name);
                fprintf(fp, "%d\n", player1.score);
            }
            else if (player1.score < player2.score){
                printf("Player 2 (%s) wins!\n", player2.name);
                printf("The winning score is %d.\n", player2.score);
                //add the winner and its score to a file
                fprintf(fp, "%s", player2.name);
                fprintf(fp, "%d\n", player2.score);
            }
            else if (player1.score == player2.score){
                printf("It's a tie. Nobody wins!");
                //add the result of the game to the file
                fprintf(fp, "It's a tie!\n");
            }
        }
    }

    //print out the final board
    printf("The final board:\n");
    printBoard(board.arr);

}