#include "vector.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INIT_SIZE 10

vector* create_vector(size_t element_size)
{
    vector* v = malloc(sizeof(vector));

    v->element_size = element_size;
    v->reserved_size = INIT_SIZE * element_size;
    v->buffer_size = 0;
    v->num_elements = 0;
    v->buffer = malloc(v->reserved_size);

    return v;
}

void destroy_vector(vector* v)
{
    free(v->buffer);
    free(v);
}

void push_back(vector* v, void* e)
{
    if (v->buffer_size >= v->reserved_size)    
    {
        v->reserved_size = v->buffer_size * 2;

        void* m = realloc(v->buffer, v->reserved_size);
        v->buffer = m;
    }

    memcpy((char*)v->buffer + v->buffer_size, e, v->element_size);
    v->num_elements++;
    v->buffer_size += v->element_size;
}

void erase_element(vector* v, int index)
{
    if (index != v->num_elements - 1)
        memcpy((char*)v->buffer + index * v->element_size, (char*)v->buffer + v->buffer_size - v->element_size, v->element_size);

    v->num_elements--;
    v->buffer_size -= v->element_size;
}

void shrink_to_fit(vector* v)
{
    v->buffer = realloc(v->buffer, v->buffer_size);
    v->reserved_size = v->buffer_size;
}

int is_empty(vector* v)
{
    return (v->num_elements == 0);
}