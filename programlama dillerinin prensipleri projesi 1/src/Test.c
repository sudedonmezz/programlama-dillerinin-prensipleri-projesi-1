#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Canli.h"
#include "Bitki.h"
#include "Bocek.h"
#include "Sinek.h"
#include "Pire.h"
#include "Habitat.h"

int main() {
    FILE *dosya = fopen("Veri.txt", "r");  
    if (dosya == NULL) {
        perror("Dosya açılamadı");
        return EXIT_FAILURE;
    }

    int rows = 0, cols = 0, tempCols = 0;
    char ch;

    // Satır ve sütun sayısını hesapla
    while ((ch = fgetc(dosya)) != EOF) {
        if (ch == ' ' && rows == 0) {
            tempCols++;  
        }
        if (ch == '\n') {
            rows++;
            if (rows == 1) cols = tempCols + 1;  
        }
    }
    if (ch != '\n') { 
        rows++;
    }

    rewind(dosya);  // Dosya imlecini başa al

    // Habitat yapısını oluştur
    Habitat habitat = yeniHabitat(rows, cols);
    if (habitat == NULL) {
        perror("Habitat oluşturulamadı");
        fclose(dosya);
        return EXIT_FAILURE;
    }
 int deger, row = 0, col = 0;
    while (fscanf(dosya, "%d", &deger) == 1) {
        Canli canli = NULL;
        if (isBitki(deger)) {
            canli = (Canli)yeniBitki(deger);
        } else if (isBocek(deger)) {
            canli = (Canli)yeniBocek(deger);
        } else if (isSinek(deger)) {
            canli = (Canli)yeniSinek(deger);
        } else if (isPire(deger)) {
            canli = (Canli)yeniPire(deger);
        }

        if (canli != NULL) {
            habitatCanliEkle(habitat, canli, row, col);
        }

        col++;
        if (fgetc(dosya) == '\n') {
            row++;
            col = 0;
        }
    }

    fclose(dosya);

    habitatGoruntule(habitat);
 printf("\nHerhangi bir tusa basarak yeme islemini baslatin...\n");
    getchar();
    yemeYarismasi(habitat);

    silHabitat(habitat);

    return EXIT_SUCCESS;
}