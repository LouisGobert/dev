#ifndef HASH_MAP_H
#define HASH_MAP_H

#include "Header.h"


#define HASH_VALUE 4

typedef struct Bucket Bucket;
struct Bucket {
	int key, value;
	Bucket* next;

};


typedef struct {
	Bucket** bucket;
	int hash;

} HashMap;

HashMap* hashMapCreate();

void hashMapPut(HashMap* obj, int key);

int hashMapGet(HashMap* obj, int key);

void hashMapRemove(HashMap* obj, int key);

void hashMapFree(HashMap* obj);


#endif

