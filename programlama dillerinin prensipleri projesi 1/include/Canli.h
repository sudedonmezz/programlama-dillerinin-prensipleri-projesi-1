#ifndef CANLI_H
#define CANLI_H

typedef enum { false, true } bool;

typedef struct CANLI {
    char* (*gorunum)();  
	bool (*canEat)(struct CANLI* this, struct CANLI* other);
	void (*sil)(struct CANLI*);  
	int value;  
}CANLI;

typedef CANLI* Canli;


bool isBitki(int deger);
bool isBocek(int deger);
bool isSinek(int deger);
bool isPire(int deger);

Canli yeniCanli(int value);
void silCanli(Canli canli);
#endif