#include <stdio.h>
#include <malloc.h>
#include "heap.h"
#include <stdlib.h>

void read(FILE* file, BinHeap* arr) {
    fseek(file, 0, SEEK_SET);
    while (!feof(file)) {
        int value;
        if (fscanf(file, "%d", &value) == 1) {
            insert(arr, value);
        }
    }
}

int main() {
    // int argc, char** argv
    //if (argc != 3) return -1;
    FILE* fin = fopen("input.txt", "r");
    BinHeap* arr = createEmptyHeap();
    read(fin,arr);
    fclose(fin);

    printf("Sorted array from file: ");
    printHeap(arr);

    FILE* fout = fopen("output.txt", "w");
    for (int i = 0; i < arr->size; ++i) {
        fprintf(fout, "%d ", arr->data[i]);
    }
    fclose(fout);
    freeHeap(&arr);
    return 0;
}
