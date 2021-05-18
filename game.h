#ifndef ASSIGN2_GAME_H
#define ASSIGN2_GAME_H
#define SIZE 8

//function that counts all the valid moves for a player
int validMoves (char board[SIZE][SIZE], char playerDisc, char opponentDisc);

//function that checks if a move is valid and if so implements it
int implementMove (char board[SIZE][SIZE], int i, int j, char playerDisc, char opponentDisc);
#endif //ASSIGN2_GAME_H
