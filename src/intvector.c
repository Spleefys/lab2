#include "intvector.h"


void printVector(int *arr, int size)
{
    printf("Array: ");
    for (int i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void vectorInfo(const Intvector * v)
{
    printf("Size : %d \nCapacity : %d \n",v->size, v->capacity);
}

void fillVector(Intvector * v, int size)
{
    for (int i = 0; i < size; ++i, ++v->size)
        v->p[i] = i * i;
}

int correctIndex(Intvector * v,int index)
{
    return (index > 0 && index < v->capacity) ? 1 : 0;
}

Intvector *vector_new(size_t incap) 
{
    Intvector *vec = NULL;
    if (!(vec = malloc(sizeof(Intvector)))) {
        return NULL;
    }
    if (!(vec->p = malloc(sizeof(int) * incap))) {
        free(vec);
        return NULL;
    }    
    memset(vec->p, 0, incap*sizeof(int));
    vec->size = 0;
    vec->capacity = incap;
    return vec;
}

Intvector *vect_copy(const Intvector *v) 
{
    Intvector *cp = NULL;
    if (!(cp = vector_new(v->capacity)))
        return NULL;
    memcpy(cp->p, v->p, v->capacity);
    cp->capacity = v->capacity;
    return cp;


}

void clean_up(Intvector *v) 
{
    free(v->p);
    free(v);
}

int get_item(const Intvector *vect, int index) 
{ 
    return vect->p[index]; 
}

void set_item(Intvector *vect, int index, int item) 
{ 
    vect->p[index] = item; 
}

size_t get_size(const Intvector *v) 
{
    return v->size; 
}

size_t get_capacity(const Intvector *v) 
{
    return v->capacity;
}





/*int push_back(Intvector *v, int item) 
{
    if (v->size == v->capacity) {
        v->p = realloc(v->p, sizeof(int) * (v->capacity) * STEP);
        v->p[v->capacity] = item;
        v->capacity *= STEP;
        if (v->size < v->capacity) {
            v->p[(v->capacity) - 1] = item;
            return 0;
        }
        return 0;
    }
    else {
        return -1;
    }
}

void pop_back(Intvector *v) 
{
    if(v->p[v->capacity-1] != 0)
        v->p[v->capacity-1] = 0;

}

int shrink_to_fit(Intvector *v)
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

int vector_resize(Intvector *v, int nsize)
{
    if (nsize > v->size || nsize < v->size) {
        if(nsize > v->size) {
            v->p = realloc(v->p, sizeof(int) * nsize);
            for(int i = v->size; i < nsize + 1 ; i++)
                v->p[v->size] = 0;
            return 0;
        }
        else {
            shrink_to_fit(v);
            return 0;
        }
    }
    else {
        return -1;
    }
}

int vector_reserve(Intvector *v, int newcap) {
    if(newcap > v->capacity) {
        v->p = realloc(v->p, sizeof(int)* newcap);
        return 0;
    }
    else {
        return -1;
    }
}*/