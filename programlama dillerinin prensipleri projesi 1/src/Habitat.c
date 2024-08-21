#include "Habitat.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


Habitat yeniHabitat(int rows, int cols) {
    Habitat habitat = malloc(sizeof(*habitat));
    if (!habitat) return NULL;

    habitat->rows = rows;
    habitat->cols = cols;
    habitat->grid = malloc(rows * sizeof(Canli*));

    for (int i = 0; i < rows; i++) {
        habitat->grid[i] = malloc(cols * sizeof(Canli));
        for (int j = 0; j < cols; j++) {
            habitat->grid[i][j] = NULL;
        }
    }

    return habitat;
}

// Habitat'ı ve içindeki tüm canlıları silme fonksiyonu
void silHabitat(Habitat habitat) {
    for (int i = 0; i < habitat->rows; i++) {
        for (int j = 0; j < habitat->cols; j++) {
            if (habitat->grid[i][j] != NULL) {
                habitat->grid[i][j]->sil(habitat->grid[i][j]);
            }
        }
        free(habitat->grid[i]);
    }
    free(habitat->grid);
    free(habitat);
}


void habitatCanliEkle(Habitat habitat, Canli canli, int row, int col) {
    if (row >= 0 && row < habitat->rows && col >= 0 && col < habitat->cols) {
        habitat->grid[row][col] = canli;
    }
}


void habitatGoruntule(Habitat habitat) {
	system("cls");
    printf("\n---------------------------\n\n");
    for (int i = 0; i < habitat->rows; i++) {
        for (int j = 0; j < habitat->cols; j++) {
            if (habitat->grid[i][j] == NULL) {
                printf("X ");
            } else {
                printf("%s ", habitat->grid[i][j]->gorunum());
            }
        }
        printf("\n");
    }
}

// Habitat içindeki canlıların yeme yarışmasını yöneten fonksiyon
void yemeYarismasi(Habitat habitat) {
    Canli winner = NULL;
    int winnerRow = -1, winnerCol = -1;

    // İlk başlangıç noktasını bul
    for (int i = 0; i < habitat->rows; i++) {
        for (int j = 0; j < habitat->cols; j++) {
            if (habitat->grid[i][j] != NULL) {
                winner = habitat->grid[i][j];
                winnerRow = i;
                winnerCol = j;
                break;
            }
        }
        if (winner != NULL) break;
    }

    bool isThereAnyChange = true;
    while (isThereAnyChange) {
        isThereAnyChange = false;

        for (int i = 0; i < habitat->rows; i++) {
            for (int j = 0; j < habitat->cols; j++) {
                Canli current = habitat->grid[i][j];
                if (current == NULL || (i == winnerRow && j == winnerCol)) continue;

                if (strcmp(winner->gorunum(), current->gorunum()) == 0) {
                    if (winner->value < current->value) {
                        current->sil(habitat->grid[winnerRow][winnerCol]);
                        habitat->grid[winnerRow][winnerCol] = NULL;
                        winner = current;
                        winnerRow = i;
                        winnerCol = j;
                        isThereAnyChange = true;
						habitatGoruntule(habitat);
                    } else if (winner->value > current->value) {
                        current->sil(habitat->grid[i][j]);
                        habitat->grid[i][j] = NULL;
                        isThereAnyChange = true;
						habitatGoruntule(habitat);
                    } else { // Eğer değerler eşitse
                        int distanceToWinner = abs(i - winnerRow) + abs(j - winnerCol);
                        int distanceToCurrentWinner = abs(winnerRow - i) + abs(winnerCol - j);
                        if (distanceToWinner < distanceToCurrentWinner) {
                            current->sil(habitat->grid[winnerRow][winnerCol]);
                            habitat->grid[winnerRow][winnerCol] = NULL;
                            winner = current;
                            winnerRow = i;
                            winnerCol = j;
                            isThereAnyChange = true;
							habitatGoruntule(habitat);
                        } else {
                            current->sil(habitat->grid[i][j]);
                            habitat->grid[i][j] = NULL;
                            isThereAnyChange = true;
							habitatGoruntule(habitat);
                        }
                    }
                } else if (winner->canEat(winner, current)) {
                    current->sil(habitat->grid[i][j]);
                    habitat->grid[i][j] = NULL;
                    isThereAnyChange = true;
					habitatGoruntule(habitat);
                } else if (current->canEat(current, winner)) {
                    current->sil(habitat->grid[winnerRow][winnerCol]);
                    habitat->grid[winnerRow][winnerCol] = NULL;
                    winner = current;
                    winnerRow = i;
                    winnerCol = j;
                    isThereAnyChange = true;
					habitatGoruntule(habitat);
                }
            }
        }
      
    }

    
    if (winner != NULL) {
        printf("\nKazanan: %s : (%d, %d)\n", winner->gorunum(), winnerRow, winnerCol);
    } else {
        printf("Kazanan yok.\n");
    }
}
