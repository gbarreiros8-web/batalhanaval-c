#ifndef GAME_H
#define GAME_H

#define SIZE 10
#define WATER '~'
#define SHIP 'S'
#define HIT 'X'
#define MISS 'O'

void initBoard(char board[SIZE][SIZE]);
void printBoard(char board[SIZE][SIZE], int hideShips);
void placeShips(char board[SIZE][SIZE]);
int shoot(char board[SIZE][SIZE], int row, int col);
int remainingShips(char board[SIZE][SIZE]);

#endif
