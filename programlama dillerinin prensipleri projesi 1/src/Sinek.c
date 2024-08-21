#include "Sinek.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char* sinekGorunum() {
    return "S";
}
bool sinekCanEat(CANLI* this, CANLI* other) {
    // Sinekler Böcekleri ve Pireleri yiyebilir
    return strcmp(other->gorunum(), "C") == 0 || strcmp(other->gorunum(), "P") == 0;
}

Sinek yeniSinek(int value) {
    Sinek this = (Sinek)malloc(sizeof(SINEK));
    if (this) {
        this->super.super.gorunum =  &sinekGorunum;
        this->super.super.canEat =  &sinekCanEat;
        this->super.super.sil = (void (*)(CANLI*))silSinek;  
        this->super.super.value = value;
    }
    return this;
}
void silSinek(Sinek this) {
     if (this == NULL) return; 
        
        silBocek((Bocek)this);
      
    
}

