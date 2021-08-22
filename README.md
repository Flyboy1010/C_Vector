# C_Vector
C version of std::vector

Examples

```c
#include "vector.h"
#include <stdlib.h>

int main()
{
    // vector of ints example

    vector* v1 = create_vector(sizeof(int));

    int ie1 = 5;
    push_back(v1, &ie1);
    int ie2 = 25;
    push_back(v1, &ie2);

    printf("vector size: %d\n", v1->num_elements);

    for (int i = 0; i < v1->num_elements; i++)
    {
        int* e_ref = &((int*)v1->buffer)[i]; // get a reference of a vector element i

        int e_copy = ((int*)v1->buffer)[i]; // get a copy of the vector element i

        printf("element(ref) %d: %d\n", i, *e_ref);
        printf("element(copy) %d: %d\n", i, e_copy);
    }

    destroy_vector(v1);

    // vector of a custom struct example

    typedef struct point
    {
        int x, y;
    } point;

    vector* v2 = create_vector(sizeof(point));

    point pe1 = {5, 10};
    push_back(v2, &pe1);
    point pe2 = {20, 30};
    push_back(v2, &pe2);

    printf("vector size: %d\n", v2->num_elements);

    for (int i = 0; i < v2->num_elements; i++)
    {
        point* e_ref = &((point*)v2->buffer)[i]; // get a reference of a vector element i

        point e_copy = ((point*)v2->buffer)[i]; // get a copy of the vector element i

        printf("element(ref) %d: %d %d\n", i, e_ref->x, e_ref->y);
        printf("element(copy) %d: %d %d\n", i, e_copy.x, e_copy.y);
    }

    destroy_vector(v2);

    // vector of pointers of a custom struct example

    vector* v3 = create_vector(sizeof(point*)); // <-- care

    point* ppe1 = malloc(sizeof(point));
    ppe1->x = 5;
    ppe1->y = 15;
    push_back(v3, &ppe1); // push_back copies the bytes of the address passed (see vector.c)
    point* ppe2 = malloc(sizeof(point));
    ppe2->x = 25;
    ppe2->y = 35;
    push_back(v3, &ppe2);

    printf("vector size: %d\n", v3->num_elements);

    for (int i = 0; i < v3->num_elements; i++)
    {
        point* e_ref = ((point**)v3->buffer)[i]; // <---- care (struct**)

        printf("element %d: %d %d\n", i, e_ref->x, e_ref->y);
    }

    // free memory

    free(ppe1);
    free(ppe2);

    destroy_vector(v3);
}
```
