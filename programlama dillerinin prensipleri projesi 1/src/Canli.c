#include "Canli.h"
#include <stdlib.h>

bool isBitki(int deger) {
    return deger >= 1 && deger <= 9;
}

bool isBocek(int deger) {
    return deger >= 10 && deger <= 20;
}

bool isSinek(int deger) {
    return deger >= 21 && deger <= 50;
}

bool isPire(int deger) {
    return deger >= 51 && deger <= 99;
}

Canli yeniCanli(int value) {
    Canli canli = (Canli)malloc(sizeof(CANLI));
    if (canli != NULL) {
        canli->gorunum = NULL;  
        canli->canEat = NULL;   
        canli->sil = NULL;     
        canli->value = value;
    }
    return canli;
}

void silCanli(Canli canli) {
    if (canli == NULL) return; 
        free(canli); 
    
}