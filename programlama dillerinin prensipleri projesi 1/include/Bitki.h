#ifndef BITKI_H
#define BITKI_H

#include "Canli.h"


typedef struct BITKI {
    CANLI super;  
	void (*sil)(struct BITKI*);
} BITKI;

typedef BITKI* Bitki;  


Bitki yeniBitki(int value);  
void silBitki(Bitki this);  
char* bitkiGorunum();
bool bitkiCanEat(CANLI* this, CANLI* other);

#endif
