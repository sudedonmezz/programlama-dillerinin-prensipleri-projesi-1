#ifndef HABITAT_H
#define HABITAT_H

#include "Canli.h"
#include <stdlib.h>

typedef struct HABITAT {
  CANLI ***grid; // Canlıların tutulduğu iki boyutlu dizi
    int rows;      
    int cols;      
    CANLI* winner;	

}HABITAT;

typedef HABITAT* Habitat;

Habitat yeniHabitat(int rows, int cols);
void silHabitat(Habitat habitat);
void habitatCanliEkle(Habitat habitat, CANLI *canli, int row, int col);
void habitatGoruntule(Habitat habitat);
void yemeYarismasi(Habitat habitat);

#endif


//iki boyutlu dinamik dizilere işaret etmek için CANLI ***grid yapısı