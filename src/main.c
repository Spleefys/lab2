#include "intvector.h"

int main() {

    int incap;
    puts("Enter initial capacity :");
    scanf("%d", &incap);
    
    Intvector *vector = vector_new(incap);

    int size;
    puts("How many cells to fill ?");
    scanf("%d", &size);
    
    fillVector(vector, size);
    
    puts("* IntVector *int_vector_new(size_t initial_capacity)");
    printVector(vector->p, vector->capacity);
    vectorInfo(vector);
    

    Intvector *vec_cp = vect_copy(vector);

    puts("How many cells to fill (copy of the vector)?");
    scanf("%d", &size);

    fillVector(vec_cp, size);
    
    puts("* IntVector *int_vector_copy(const IntVector *v)");
    printVector(vec_cp->p, vec_cp->capacity);

    vectorInfo(vec_cp);

    puts("* void int_vector_free(IntVector *v)");
    clean_up(vec_cp);
    
    puts("Memory of the vec_cp is freed ");

    puts("* int int_vector_get_item(const IntVector *v, size_t index)");
    int index;
    
    do {
        puts("What item do you want to get ?");
        scanf("%d", &index);
        correctIndex(vector, index);
    } while(!(correctIndex(vector, index)));
    printf("vector->p[%d] = %d\n",index, get_item(vector, index));


    puts("* void int_vector_set_item(IntVector *v, size_t index, int item)");
    
    int item;

    do {
        puts("What item do you want to change ?");
        scanf("%d", &index);
        correctIndex(vector, index);

    } while(!(correctIndex(vector, index)));
    
    puts("What do you want to put ?");
    scanf("%d", &item);
    
    set_item(vector, index, item);
    printf("vector->p[%d] = %d\n",index, vector->p[index]);
    
    printVector(vector->p, vector->capacity);

    puts("* size_t int_vector_get_size(const IntVector *v)");
    printf("vector->size = %d\n", get_size(vector));

    puts("* size_t int_vector_get_capacity(const IntVector *v)");
    printf("vector->capacity = %d\n", get_capacity(vector));

    /*printf("* int int_vector_push_back(IntVector *v, int item)\n");
    push_back(vector, 9);
    for (int i = 0; i < 12; ++i)
        printf("%d\t", vector->p[i]);
    printf("\n");

    printf("* int int_vector_pop_back(IntVector *v)\n");
    pop_back(vector);
    for (int i = 0; i < 12; ++i)
        printf("%d\t", vector->p[i]);
    printf("\n");
    

    printf("* int int_vector_shrink_to_fit(IntVector *v)\n");
    shrink_to_fit(vector);
    for (int i = 0; i < 6; ++i)
        printf("%d\t", vector->p[i]);
    printf("\n");

    printf("* int int_vector_resize(IntVector *v, int size)\n");
    int nsize = 9;
    vector_resize(vector, nsize);
    for (int i = 0; i < nsize; ++i)
        printf("%d\t", vector->p[i]);
    printf("\n");
   
    printf("%d\n", vector->capacity);
    
    printf("* int int_vector_reserve(IntVector *v, int capacity)\n");
    int newcap = 10;
    vector_reserve(vector, newcap);
    for (int i = 0; i < 10; ++i)
        printf("%d\t", vector->p[i]);
    printf("\n");


    clean_up(vector);*/

    return 0;
}