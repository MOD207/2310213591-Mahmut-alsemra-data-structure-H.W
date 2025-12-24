#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Moves the element up to maintain the Min-Heap property
void minHeapify(int arr[], int i) {
    int parent = (i - 1) / 2;

    if (parent >= 0) {
        // If child is SMALLER than parent, swap them
        if (arr[i] < arr[parent]) {
            swap(&arr[i], &arr[parent]);
            minHeapify(arr, parent); // Recursively check the new parent
        }
    }
}

void insertMinHeap(int arr[], int *size, int value) {
    arr[*size] = value; // Place at the end
    *size = *size + 1;
    minHeapify(arr, *size - 1); // Bubble it up
}

int main() {
    int heap[100];
    int size = 0;

    insertMinHeap(heap, &size, 30);
    insertMinHeap(heap, &size, 10);
    insertMinHeap(heap, &size, 50);
    insertMinHeap(heap, &size, 5);

    printf("Min-Heap (Smallest is at index 0): ");
    for (int i = 0; i < size; i++) {
        printf("%d ", heap[i]);
    }
    // Output will be: 5 10 50 30 
    // (5 is the root because it's the minimum)

    return 0;
}