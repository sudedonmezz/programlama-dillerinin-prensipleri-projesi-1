#ifndef SINEK_H
#define SINEK_H

#include "Bocek.h"


typedef struct SINEK{
    BOCEK super;
	void (*sil)(struct SINEK*); 
} SINEK;

typedef SINEK* Sinek;


Sinek yeniSinek(int value);
void silSinek(Sinek this);
char* sinekGorunum();
bool sinekCanEat(CANLI* this, CANLI* other);

#endif