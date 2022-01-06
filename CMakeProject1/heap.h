#pragma once
typedef struct BinHeap {
    int* data;
    int size;
} BinHeap;

BinHeap* createMyHeap();
BinHeap* createEmptyHeap();
void build(BinHeap* arr);
void heapify(BinHeap* arr, int i);
int extractMax(BinHeap* arr);
void insert(BinHeap* arr, int element);
void increase(BinHeap* arr, int key);
void deleteElement(BinHeap* arr, int element);
void printHeap(BinHeap* arr);
void clearHeap(BinHeap* arr);
void freeHeap(BinHeap** arr);