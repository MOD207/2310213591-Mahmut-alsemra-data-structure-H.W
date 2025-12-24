#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// To maintain Max-Heap property during insertion
void heapify(int arr[], int size, int i) {
    int parent = (i - 1) / 2;

    if (parent >= 0) {
        // For Max-Heap: if child is greater than parent, swap
        if (arr[i] > arr[parent]) {
            swap(&arr[i], &arr[parent]);
            // Recursively heapify the parent
            heapify(arr, size, parent);
        }
    }
}

void insert(int arr[], int *size, int value) {
    *size = *size + 1;
    arr[*size - 1] = value; // Put new element at the end
    heapify(arr, *size, *size - 1); // Move it up to the right spot
}

void printHeap(int arr[], int size) {
    for (int i = 0; i < size; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int heap[100];
    int size = 0;

    insert(heap, &size, 10);
    insert(heap, &size, 20);
    insert(heap, &size, 5);
    insert(heap, &size, 30);
    insert(heap, &size, 15);

    printf("Max-Heap array: ");
    printHeap(heap, size);

    return 0;
}