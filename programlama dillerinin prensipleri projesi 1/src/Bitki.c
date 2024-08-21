#include "Bitki.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


char* bitkiGorunum() {
    return "B";
}


bool bitkiCanEat(CANLI* this, CANLI* other) {
    // Bitkiler Sinekleri ve Pireleri yiyebilir
    return strcmp(other->gorunum(), "S") == 0 || strcmp(other->gorunum(), "P") == 0;
}


Bitki yeniBitki(int value) {
    Bitki this = (Bitki)malloc(sizeof(BITKI));
    if (this == NULL) {
        fprintf(stderr, "Memory allocation failed for Bitki\n");
        exit(EXIT_FAILURE);
    }
    this->super.gorunum =  &bitkiGorunum;
    this->super.canEat =  &bitkiCanEat;
    this->super.sil = (void (*)(CANLI*))silBitki;  // Tür dönüşümü ile silme fonksiyonunu ata
    this->super.value = value;
    return this;
}


void silBitki(Bitki this) {
    if (this == NULL) return;
        
        silCanli((Canli) this); // canli için genel temizleme işlevini çağırır.
       
    
}