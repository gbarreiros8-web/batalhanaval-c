#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game.h"

int main() {
    char player1[SIZE][SIZE];
    char player2[SIZE][SIZE];
    int row, col;
    int currentPlayer = 1;

    srand(time(NULL));

    initBoard(player1);
    initBoard(player2);

    placeShips(player1);
    placeShips(player2);

    while (1) {
        printf("\n=== Jogador %d ===\n", currentPlayer);

        if (currentPlayer == 1)
            printBoard(player2, 1);
        else
            printBoard(player1, 1);

        printf("Digite linha e coluna (ex: 3 4): ");
        scanf("%d %d", &row, &col);

        if (row < 0 || row >= SIZE || col < 0 || col >= SIZE) {
            printf("Posição inválida!\n");
            continue;
        }

        int hit;
        if (currentPlayer == 1)
            hit = shoot(player2, row, col);
        else
            hit = shoot(player1, row, col);

        if (hit)
            printf("ACERTOU!\n");
        else
            printf("Errou!\n");

        if (remainingShips(player1) == 0) {
            printf("Jogador 2 venceu!\n");
            break;
        }

        if (remainingShips(player2) == 0) {
            printf("Jogador 1 venceu!\n");
            break;
        }

        currentPlayer = (currentPlayer == 1) ? 2 : 1;
    }

    return 0;
}
