#ifndef INTVECTOR_H
#define INTVECTOR_H

#include <stdio.h>
#include <stdlib.h>
#define NOT_ALLOCATED 3
#define STEP 2

typedef struct Intvector {
    int * p;
    int size;
    int capacity;
} Intvector;

Intvector * vector_new(int cap);

Intvector * vect_copy(const Intvector * v);

int get_item(const Intvector * vect ,int index);

void set_item(Intvector * vect, int index, int item);

int push_back(Intvector * v, int item);

void pop_back(Intvector * v);

void clean_up(Intvector * v);

int get_size(const Intvector * v);

int get_capacity(const Intvector * v);


#endif