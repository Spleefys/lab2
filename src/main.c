#include "intvector.h"

int main() {

    Intvector *vector = vector_new(6);

    for (int i = 0; i < 6; ++i, ++vector->size)
        vector->p[i] = i * i;
    printf("* IntVector *int_vector_new(size_t initial_capacity)\n");
    for (int i = 0; i < 6; ++i)
        printf("%d\t", vector->p[i]);
    printf("\n");

    printf("Size\tCapacity\n");
    printf("%d\t%d\n", vector->size, vector->capacity);

    Intvector *vec_cp = vect_copy(vector);

    for (int i = 0; i < 6; ++i, ++vec_cp->size)
        vec_cp->p[i] = i;
    printf("* IntVector *int_vector_copy(const IntVector *v)\n");
    for (int i = 0; i < 6; ++i)
        printf("%d\t", vec_cp->p[i]);
    printf("\n");

    printf("Size\tCapacity\n");
    printf("%d\t%d\n", vec_cp->size, vec_cp->capacity);

    printf("* void int_vector_free(IntVector *v)\n");
    clean_up(vec_cp);
    // printf("%d\n", vec_cp->p[2]);  Segmentation fault !

    printf("* int int_vector_get_item(const IntVector *v, size_t index)\n");
    printf("vector->p[3] = %d\n", get_item(vector, 3));

    printf("* void int_vector_set_item(IntVector *v, size_t index, int item)\n");
    set_item(vector, 2, 5);
    printf("vector->p[2] = %d\n", vector->p[2]);

    printf("* size_t int_vector_get_size(const IntVector *v)\n");
    printf("vector->size = %d\n", get_size(vector));

    printf("* size_t int_vector_get_capacity(const IntVector *v)\n");
    printf("vector->capacity = %d\n", get_capacity(vector));

    printf("* int int_vector_push_back(IntVector *v, int item)\n");
    push_back(vector, 9);
    for (int i = 0; i < 7; ++i)
        printf("%d\t", vector->p[i]);
    printf("\n");

    /*for(int i = 0;i < 6;++i)
        vector->p[i] = i*i;
    vector->size = 6;

    push_back(vector,9);

    pop_back(vector);
    set_item(vector, 2, 5);

    for(int i = 0;i < 6;++i)
        vector->p[i] = i*i;

    printf("%d\n", get_item(vector, 5));

    for(int i = 0;i < 11;++i)
        printf("%d\n", vector->p[i]);
    clean_up(vector);*/

    return 0;
}