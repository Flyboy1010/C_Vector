#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <stddef.h>

typedef struct vector
{
    void* buffer;
    size_t element_size;
    size_t buffer_size;
    size_t reserved_size;
    int num_elements;
} vector;

vector* create_vector(size_t element_size);
void destroy_vector(vector* v);

void push_back(vector* v, void* e);
void erase_element(vector* v, int index);
void shrink_to_fit(vector* v);
int is_empty(vector* v);

#endif // _VECTOR_H_