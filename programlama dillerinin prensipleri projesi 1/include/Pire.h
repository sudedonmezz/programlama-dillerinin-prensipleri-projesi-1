#ifndef PIRE_H
#define PIRE_H

#include "Bocek.h"


typedef struct PIRE{
    BOCEK super;
	 void (*sil)(struct PIRE*); 
} PIRE;

typedef PIRE* Pire;


Pire yeniPire(int value);
void silPire(Pire this);
char* pireGorunum();
bool pireCanEat(CANLI* this, CANLI* other);

#endif