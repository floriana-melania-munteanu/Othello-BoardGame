//Author:Floriana Melania Munteanu
//Student Number:20349023
#include <stdio.h>

//initialise the board
struct board{
    char letter;
    int number;
    char arr[8][8];
};
//initialise the players
/*enum discColour {
    Black = 'B';
    White = 'W';
    Empty = ' ';
};*/
struct player{
    char name[20];
    int score;
    char disc;
};
/*struct player2{
    char name[20];
    int score;
    enum discColour White;
};*/


int main() {

    struct player player1, player2;
    size_t i, j;


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






    //play the game
    //determine winner
    //print out the results
    //print the result to a file


    return 0;
}
