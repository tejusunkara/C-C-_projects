#include "srt.h"
#include <stdlib.h>
#include <string.h>

//size gives bytes
//nelem = number of elements in the array
//void srtheap(void*, size_t, size_t, int(*)(const void *, const void *));
void heapify(char *array, size_t nelem, size_t size, size_t pRoot, int (*compar)(const void *, const void *));

void srtheap(void *base, size_t nelem, size_t size, int (*compar)(const void *, const void *)) {

    char *array = malloc((size + 1) * nelem); //allocates enough memory for all elements
    memcpy(array + size, base, nelem * size);

    size_t n;

    //build max-heap: orders the array as a max heap where parents are bigger than children
    //swap largest item with item at the end of the array;consider largest item sorted
    for(n = nelem / 2; n >= 1; --n) {
        heapify(array, nelem, size, n, compar);
    }
    for (n = nelem; n > 1; --n){
        size_t i = 1;
        swap(array + size, array + 1 * size, size);
        heapify(array, n-1, size, 1, compar);

    }
    memcpy(base, array + size, nelem * size);
    free(array);
}

void heapify(char *array, size_t nelem, size_t size, size_t pRoot, int (*compar)(const void *, const void *)) {
    //heapify: making sure parent > child
    size_t largest = pRoot;
    size_t lChild = 2 * pRoot + 1;
    size_t rChild = 2 * pRoot + 2;

    //if right child is larger than root
    if(rChild < nelem &&  compar(array + rChild * size, array + lChild * size) < 0) {
        largest = rChild;
    }

    //if left child is larger than root
    if(lChild < nelem && compar(array + pRoot * size, array + lChild * size) > 0) {
        largest = lChild;
    }

    //if largest is not the parent root, swap elements
    if(largest != pRoot) {
        swap(array + pRoot * size, array + largest * size, size);
        pRoot = largest;
    }
}