#include "intvector.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void printVector(int *arr, int size)
{
    printf("Array: ");
    for (int i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

0void vectorInfo(const Intvector * v)
{
    printf("Size : %d \nCapacity : %d \n", v->size, v->capacity);
}

void fillVector(Intvector * v, int size)
{
    for (int i = 0; i < size; ++i, ++v->size)
        v->p[i] = i * i;
}

int correctIndex(Intvector * v,int index)
{
    return (index >= 0 && index < v->capacity) ? 1 : 0;
}

Intvector *vectorNew(size_t incap)
{
    Intvector *vec = NULL;
    if (!(vec = malloc(sizeof(Intvector)))) {
        return NULL;
    }
    if (!(vec->p = malloc(sizeof(int) * incap))) {
        free(vec);
        return NULL;
    }
    vec->size = 0;
    vec->capacity = incap;
    return vec;
}

Intvector *vectCopy(const Intvector *v)
{
    Intvector *cp = NULL;
    if (!(cp = vectorNew(v->capacity)))
        return NULL;
    memcpy(cp->p, v->p, v->capacity);
    cp->capacity = v->capacity;
    return cp;


}

void cleanUp(Intvector *v)
{
    free(v->p);
    free(v);
}

int getItem(const Intvector *vect, int index)
{
    return vect->p[index];
}

void setItem(Intvector *vect, int index, int item)
{
    vect->p[index] = item;
}

size_t getSize(const Intvector *v)
{
    return v->size;
}

size_t getCapacity(const Intvector *v)
{
    return v->capacity;
}


int pushBack(Intvector *v, int item)
{
    if (v->size == v->capacity) {
        vectorReserve(v, v->capacity*STEP);
        v->p[v->size] = item;
        v->size++;
        return 0;
    }
    else {
        v->p[v->size] = item;
        return 0;
    }
    return -1;

}

void popBack(Intvector *v)
{
    if(v->p[v->size] != 0)
        v->p[v->size] = 0;
}

int shrinkToFit(Intvector *v)
{
    if (v->size < v->capacity) {
        v->p = realloc(v->p, v->size * sizeof(int));
        v->capacity = v->size;
        return 0;
    }
    else {
        return -1;
    }
}

int vectorResize(Intvector *v, size_t nsize)
{
    if (nsize != v->size && nsize != 0) {
        if(nsize > v->size) {
            v->p = realloc(v->p, sizeof(int) * nsize);
            memset(v->p + v->capacity, 0, (nsize - v->capacity)*sizeof(int));
            v->size = v->capacity = nsize;
            return 0;
        }
        else {
            shrinkToFit(v);
            return 0;
        }
    }
    else {
        return -1;
    }
}

int vectorReserve(Intvector *v, size_t newcap) {
    if(newcap > v->capacity) {
        if(!(v->p = realloc(v->p, sizeof(int)* newcap)))
            return -1;
        memset(v->p + v->capacity, 0, (newcap - v->capacity)*sizeof(int));
        v->capacity = newcap;
    }
    return 0;
}
