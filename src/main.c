#include "intvector.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {

    int incap;
    puts("Enter initial capacity :");
    scanf("%d", &incap);

    Intvector *vector = vectorNew(incap);

    int size;
    puts("How many cells to fill ?");
    scanf("%d", &size);

    fillVector(vector, size);

    puts("* IntVector *int_vector_new(size_t initial_capacity)");
    printVector(vector->p, vector->capacity);
    vectorInfo(vector);


    Intvector *vec_cp = vectCopy(vector);

    puts("How many cells to fill (copy of the vector)?");
    scanf("%d", &size);

    fillVector(vec_cp, size);

    puts("* IntVector *int_vector_copy(const IntVector *v)");
    printVector(vec_cp->p, vec_cp->capacity);

    vectorInfo(vec_cp);

    puts("* void int_vector_free(IntVector *v)");
    cleanUp(vec_cp);

    puts("Memory of the vec_cp is freed ");

    puts("* int int_vector_get_item(const IntVector *v, size_t index)");
    int index;

    do {
        puts("What item do you want to get ?");
        scanf("%d", &index);
        correctIndex(vector, index);
    } while(!(correctIndex(vector, index)));
    printf("vector->p[%d] = %d\n",index, getItem(vector, index));


    puts("* void int_vector_set_item(IntVector *v, size_t index, int item)");

    int item;

    do {
        puts("What item do you want to change ?");
        scanf("%d", &index);
        correctIndex(vector, index);

    } while(!(correctIndex(vector, index)));

    puts("What do you want to put ?");
    scanf("%d", &item);

    setItem(vector, index, item);
    printf("vector->p[%d] = %d\n",index, vector->p[index]);

    printVector(vector->p, vector->capacity);

    puts("* size_t int_vector_get_size(const IntVector *v)");
    printf("vector->size = %d\n", getSize(vector));

    puts("* size_t int_vector_get_capacity(const IntVector *v)");
    printf("vector->capacity = %d\n", getCapacity(vector));

    puts("* int int_vector_push_back(IntVector *v, int item)");
    puts("* int int_vector_reserve(IntVector *v, size_t new_capacity)");
    puts("Enter the item :");
    scanf("%d", &item);
    pushBack(vector, item);
    printVector(vector->p, vector->capacity);

    puts("* int int_vector_pop_back(IntVector *v)");
    popBack(vector);
    printVector(vector->p, vector->capacity);


    puts("* int int_vector_shrink_to_fit(IntVector *v)");
    shrinkToFit(vector);
    printVector(vector->p, vector->capacity);

    puts("* int int_vector_resize(IntVector *v, int size)");
    int nsize;
    puts("Enter a new size :");
    scanf("%d", &nsize);
    vectorResize(vector, nsize);

    printVector(vector->p, vector->capacity);

    /*puts("* int int_vector_reserve(IntVector *v, size_t new_capacity)");
    int newcap;
    puts("Enter a new capacity :");
    scanf("%d", &newcap);
    vector_reserve(vector, newcap);
    printVector(vector->p, vector->capacity);*/

    cleanUp(vector);

    return 0;
}
