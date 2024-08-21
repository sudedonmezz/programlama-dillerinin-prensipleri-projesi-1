#ifndef BOCEK_H
#define BOCEK_H

#include "Canli.h"


typedef struct BOCEK {
    CANLI super;
	void (*sil)(struct BOCEK*); 
} BOCEK;

typedef BOCEK* Bocek;


Bocek yeniBocek(int value);
void silBocek(Bocek this);
char* bocekGorunum();
bool bocekCanEat(CANLI* this, CANLI* other);

#endif