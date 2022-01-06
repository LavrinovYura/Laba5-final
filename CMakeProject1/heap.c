#include "heap.h"
#include <malloc.h>
#include <string.h>
#include <limits.h>
#include <conio.h>
#include <stdio.h>

BinHeap* createMyHeap() {
	BinHeap* tmp = NULL;
	tmp = (BinHeap*)malloc(sizeof(BinHeap));
	int N;
	printf("Input Size: ");
	scanf_s("%d", &N);
	tmp->size = N;
	int* mass;
	mass = (int*)malloc(N * sizeof(int));
	printf("Input the array elements: ");
	for (int i = 0; i < N; i++)
		scanf_s("%d", &mass[i]);
	tmp->data = mass;
	build(tmp);
	return tmp;
}

BinHeap* createEmptyHeap() {
	BinHeap* tmp = NULL;
	tmp = (BinHeap*)malloc(sizeof(BinHeap));
	tmp->data = NULL;
	tmp->size = 0;
	return tmp;
}

void build(BinHeap* arr) {
	for (int i = arr->size / 2; i >= 0; i--) {
		heapify(arr, i);
	}
}

void heapify(BinHeap* arr, int i) {
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	int largest = i;
	if (left < arr->size && arr->data[left] > arr->data[largest]) largest = left;
	if (right < arr->size && arr->data[right] > arr->data[largest]) largest = right;
	if (largest != i) {
		int v = arr->data[i];
		arr->data[i] = arr->data[largest];
		arr->data[largest] = v;
		heapify(arr, largest);
	}
}

int extractMax(BinHeap* arr) {
	int max = arr->data[0];
	arr->data[0] = arr->data[arr->size - 1];
	arr->size--;
	heapify(arr, 0);
	arr->data = (int*)realloc(arr->data, (arr->size) * sizeof(int));
	return max;
}

void insert(BinHeap* arr, int element) {
	arr->size++;
	if (arr->data == NULL) {
		arr->data = (int*)malloc(arr->size * sizeof(int));
	}
	else {
		arr->data = (int*)realloc(arr->data, (arr->size) * sizeof(int));
	}
	arr->data[arr->size - 1] = INT_MIN;
	increase(arr, element);
}

void increase(BinHeap* arr, int key) {
	int i = arr->size - 1;
	if (key < arr->data[i]) return;
	arr->data[i] = key;
	while (i > 0 && arr->data[i / 2] < arr->data[i]) {
		int v = arr->data[i / 2];
		arr->data[i / 2] = arr->data[i];
		arr->data[i] = v;
		i = i / 2;
	}
}

void deleteElement(BinHeap* arr, int element) {
	if (arr->size < element) return;
	arr->data[element] = arr->data[arr->size - 1];
	arr->size--;
	arr->data = (int*)realloc(arr->data, (arr->size) * sizeof(int));
	heapify(arr, element);
}

void printHeap(BinHeap* arr) {
	printf("BinHeap: ");
	for (int i = 0; i < arr->size; ++i) {
		printf("%d ", arr->data[i]);
	}
	printf("\n");
}

void clearHeap(BinHeap* arr) {
	free(arr->data);
	arr->data = NULL;
}

void freeHeap(BinHeap** arr) {
	clearHeap(*arr);
	free(*arr);
	arr = NULL;
}










