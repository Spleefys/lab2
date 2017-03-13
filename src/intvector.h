#ifndef INTVECTOR_H
#define INTVECTOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

Intvector *vector_new(size_t capacity);

Intvector *vect_copy(const Intvector *v);

void clean_up(Intvector *v);

int get_item(const Intvector *vect, int index);

void set_item(Intvector *vect, int index, int item);

size_t get_size(const Intvector *v);

size_t get_capacity(const Intvector *v);

int push_back(Intvector *v, int item);

int vector_reserve(Intvector *v, size_t newcap);

void pop_back(Intvector *v);

int shrink_to_fit(Intvector *v);

int vector_resize(Intvector *v, size_t size);


#endif