#include <assert.h>
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <limits.h>
#include "heap.h"

void test() {
    int size = 10;
    BinHeap* arr = createEmptyHeap();
    for (int i = 0; i < size; ++i) {
       insert(arr, rand() % 20);
    }
    
    int flag =0;
    printf("Creating Heap---------------- \n");
    printHeap(arr);
    for (int i = 0; i < arr->size; ++i) {
        if (2 * i + 2 < arr->size) if (arr->data[i] < arr->data[2 * i + 2]) flag = -1;
        if (2 * i + 1 < arr->size) if (arr->data[i] < arr->data[2 * i + 1]) flag = -1;
    }
    assert(flag == 0);

    printf("Inserting---------------- \n");
    insert(arr, 1000);
    printHeap(arr);
    flag = 1;
    for (int i = 0; i < arr->size; ++i) {
        
        if (arr->data[i] == 1000) {
            flag = 0;
            break;
        }
    }

    printf("Extracting maximum---------------- \n");
    int orig = arr->data[0];
    int max = extractMax(arr);
    assert(orig == max);
    printHeap(arr);
    printf("Maximum: %d \n", max);

    printf("Deleting---------------- \n");
    int deleted = arr->data[8];
    printf("Deleted: %d \n", deleted);
    deleteElement(arr, 8);
    printHeap(arr);

    freeHeap(&arr);
}

int main() {
    test();
    return 0;
}
