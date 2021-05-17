//Software Engineering Assignment 2 - Othello Board-Game in C
//Author:Floriana Melania Munteanu
//Student Number:20349023

#include <stdio.h>
#include <time.h> //to get the current time and date
#include "printBoard.h"
#include "game.h"
#define SIZE 8 //the size of the board

//define the board struct
struct board{
    char letter; //letter co-ordinate
    int number; //the number co-ordinate
    char arr[SIZE][SIZE]; //array representing the squares on the board
};
//define the player struct
struct player{
    char name[20]; //the name of the player
    int score; //their score
    char disc; //the disc they play with
};

int main(){

    struct player player1, player2; //variables of type player for the two players
    struct board board; //variable of tpe board for the board
    int i, j;

    //welcome message
    printf("\t*** Welcome to Othello! ***\n");

    //initialise the players' names and scores
    //player1 gets the black discs and player2 white and both scores are 2
    printf("Enter name of Player 1 (Black):");
    scanf("%20s", player1.name);
    player1.disc = 'B';
    player1.score = 2;
    printf("Enter name of Player 2 (White):");
    scanf("%20s", player2.name);
    player2.disc = 'W';
    player2.score = 2;

    //initialise the board with * which represents an empty square
    for(i = 0; i < SIZE; i++){
        for(j = 0; j < SIZE; j++){
            board.arr[i][j] = '*';
        }
    }
    //adding the 4 discs in the middle of the board
    board.arr[3][3] = 'W';
    board.arr[4][3] = 'B';
    board.arr[3][4] = 'B';
    board.arr[4][4] = 'W';

    //print out the board
    printf("\nScore: %s (Black) 2:2 %s (White)\n", player1.name, player2.name);
    printBoard(board.arr);

    //play the game
    int k; //stores the value returned by the function implementMove
    int a; //stores the number of valid moves for player1
    int b; //stores the number of valid moves for player2

    a = 4; //initially there are 4 possible moves for player1

    //while there are still empty squares on the board and possible move on the board
    while (player1.score + player2.score < 64 && (a > 0 || b > 0)){

        //validMove counts the valid moves on the board
        a = validMove(board.arr, player1.disc, player2.disc);

        //if the move is invalid function implementMove returns -1
        k = -1;

        //if there are valid moves for player 1 on the board ask the player for a move
        if(a > 0){
            while (k == -1){
                printf("\nPlayer 1 (Black):\n");
                printf("Choose a move:");
                scanf("%1s%d", &board.letter, &board.number);

                //the co-ordinates entered by the user are converted to fit the 2D array co-ordinates
                i = board.number - 1;
                j = (int) (board.letter - 97);

                //the the move is valid k is equal to the number of disc turned by the one placed on the board
                k = implementMove(board.arr, i, j, player1.disc, player2.disc);
            }
            //update the scores
            player1.score = player1.score + (k+1); //k+1 because k doesn't include the disc placed just now on the board
            player2.score = player2.score - k;

            //display the updated scores
            printf("Player 1 score %d\nPlayer 2 score %d\n", player1.score, player2.score);
        }
        //else display that there are no valid moves for this player and go to the next one
        else {
            printf("No valid moves! Next player's turn.\n");
        }

        //display the updated board
        printBoard(board.arr);

        k = -1; //assign -1 to k so that the while loop is entered

        //check if there are valid move on the board for player2
        b = validMove(board.arr, player2.disc, player1.disc);

        //if there are valid moves ask the player for a move, the same as for player1
        if(b > 0) {
            while (k == -1) {
                printf("\nPlayer 2 (White):\n");
                printf("Choose a move:");
                scanf("%1s%d", &board.letter, &board.number);
                i = board.number - 1;
                j = (int) (board.letter) - 97;
                k = implementMove(board.arr, i, j, player2.disc, player1.disc);
            }
            printf("k = %d\n", k);
            player2.score = player2.score + (k + 1);
            player1.score = player1.score - k;
            printf("Player 1 score %d\nPlayer 2 score %d\n", player1.score, player2.score);
        }
        //else display that there are no valid moves for this player and go to the next one
        else {
            printf("No valid move! Next player's turn.");
        }

        //display the updated board
        printBoard(board.arr);
    }

    //print the result to a file
    FILE *fp; //file pointer
    if((fp = fopen("othello-results.txt", "a")) == NULL){
        //display message if the file cannot be opened
        puts("The file cannot be opened!\n");
    }
    else{
        //add current time to the file
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
            fprintf(fp, "Name: %s ", player2.name);
            fprintf(fp, "score: %d\n", player2.score);
        }
        else if (player1.score == player2.score){
            printf("It's a tie. Nobody wins!\n");

            //add the result of the game to the file
            fprintf(fp, "It's a tie!\n");
        }
        fclose(fp); //close the file
    }

    //print out the final board
    printf("The final board:\n");
    printBoard(board.arr);

    return 0;
}
//for the rows co-ordinate we subtract 1
//for the columns we convert the letter char to the appropriate number char by subtracting 97
//and that number char is then converted into an int