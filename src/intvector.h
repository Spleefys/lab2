#ifndef INTVECTOR_H
#define INTVECTOR_H

#include <stddef.h>

#define STEP 2

typedef struct Intvector {
    int *p;
    int size;
    int capacity;
} Intvector;

int correctIndex(Intvector * v,int index);

void printVector(int *arr, int size);

void vectorInfo(const Intvector * v);

void fillVector(Intvector *v, int size);

Intvector *vectorNew(size_t capacity);

Intvector *vectCopy(const Intvector *v);

void cleanUp(Intvector *v);

int getItem(const Intvector *vect, int index);

int setItem(Intvector *vect, int index, int item);

int getSize(const Intvector *v);

int getCapacity(const Intvector *v);

int pushBack(Intvector *v, int item);

int vectorReserve(Intvector *v, size_t newcap);

void popBack(Intvector *v);

int shrinkToFit(Intvector *v);

int vectorResize(Intvector *v, size_t size);


#endif
