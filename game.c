#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game.h"

void initBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            board[i][j] = WATER;
}

void printBoard(char board[SIZE][SIZE], int hideShips) {
    printf("  ");
    for (int i = 0; i < SIZE; i++)
        printf("%d ", i);
    printf("\n");

    for (int i = 0; i < SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < SIZE; j++) {
            if (hideShips && board[i][j] == SHIP)
                printf("%c ", WATER);
            else
                printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void placeShips(char board[SIZE][SIZE]) {
    int ships = 5;
    while (ships > 0) {
        int row = rand() % SIZE;
        int col = rand() % SIZE;
        if (board[row][col] == WATER) {
            board[row][col] = SHIP;
            ships--;
        }
    }
}

int shoot(char board[SIZE][SIZE], int row, int col) {
    if (board[row][col] == SHIP) {
        board[row][col] = HIT;
        return 1;
    } else if (board[row][col] == WATER) {
        board[row][col] = MISS;
    }
    return 0;
}

int remainingShips(char board[SIZE][SIZE]) {
    int count = 0;
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (board[i][j] == SHIP)
                count++;
    return count;
}
