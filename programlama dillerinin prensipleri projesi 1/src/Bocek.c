#include "Bocek.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char* bocekGorunum() {
    return "C";
}

bool bocekCanEat(CANLI* this, CANLI* other) {
    // Böcekler Bitkileri ve Pireleri yiyebilir
   
	return strcmp(other->gorunum(), "B") == 0 || strcmp(other->gorunum(), "P") == 0;
	
}

Bocek yeniBocek(int value) {
    Bocek this = (Bocek)malloc(sizeof(struct BOCEK));
    if (this == NULL) {
        fprintf(stderr, "Hafıza tahsisi başarısız oldu.\n");
        exit(EXIT_FAILURE);
    }
    this->super.gorunum =  &bocekGorunum;
    this->super.canEat =  &bocekCanEat;
    this->super.sil = (void (*)(CANLI*))silBocek;
    this->super.value = value;
    return this;
}

void silBocek(Bocek this) {
 if (this == NULL) return;
       
        silCanli((Canli)this); // canli için genel temizleme işlevini çağırır.
      
    
}

