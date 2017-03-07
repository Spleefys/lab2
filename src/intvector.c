#include "intvector.h"

Intvector *vector_new(int cap) 
{
    Intvector *vec = NULL;
    if (!(vec = malloc(sizeof(Intvector))))
        exit(NOT_ALLOCATED);
    if (!(vec->p = malloc(sizeof(int) * cap)))
        exit(NOT_ALLOCATED);
    vec->size = 0;
    vec->capacity = cap;
    return vec;
}

Intvector *vect_copy(const Intvector *v) 
{
    Intvector *cp = NULL;
    if ((cp = vector_new(v->capacity)))
        return cp;
    else
        return NULL;
}

int get_item(const Intvector *vect, int index) 
{ 
    return vect->p[index]; 
}

void set_item(Intvector *vect, int index, int item) 
{ 
    vect->p[index] = item; 
}

int push_back(Intvector *v, int item) 
{
    if (v->size == v->capacity) {
        v->p = realloc(v->p, sizeof(int) * (v->capacity) * STEP);
        v->p[v->capacity] = item;
        v->capacity *= STEP;
        return 0;
    } 
    else {
        v->p[(v->capacity) - 1] = item;
        return 0;
    }
    if ((v->p[v->capacity] = item) || (v->p[(v->capacity) - 1] = item))
        return -1;
}

void pop_back(Intvector *v) 
{
    v->p = (int *)realloc(v->p, (v->capacity) - 1);
    v->capacity -= 1;
}

void clean_up(Intvector *v) 
{ 
    free(v); 
}

int get_size(const Intvector *v) 
{
    return v->size; 
}

int get_capacity(const Intvector *v) 
{ 
	return v->capacity; 
}
