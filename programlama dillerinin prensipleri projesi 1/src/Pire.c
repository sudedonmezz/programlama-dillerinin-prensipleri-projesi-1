#include "Pire.h"
#include <stdlib.h>
#include <stdio.h>


char* pireGorunum() {
    return "P";
}

bool pireCanEat(CANLI* this, CANLI* other) {
    // Pireler hiçbir canlıyı yiyemez
    return false;
}
Pire yeniPire(int value) {
    Pire this = (Pire)malloc(sizeof(PIRE));
    if (this) {
        this->super.super.gorunum =  &pireGorunum;
        this->super.super.canEat =  &pireCanEat;
        this->super.super.sil = (void (*)(CANLI*))silPire;
        this->super.super.value = value;
    }
    return this;
}
void silPire(Pire this) {
    if (this == NULL) return; 
    
    silBocek((Bocek)this);
    
}