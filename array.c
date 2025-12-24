#include <stdio.h>

// Function to display the array
void display(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[100] = {10, 20, 30, 40, 50}; // Initial array
    int n = 5; // Current number of elements
    int pos, value;

    printf("Original Array: ");
    display(arr, n);

    // --- INSERTION ---
    printf("\n--- Insertion ---\n");
    value = 25;
    pos = 2; // Insert at index 2 (between 20 and 30)

    // Shift elements to the right to create a gap
    for (int i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
    n++; // Increase size

    printf("After inserting %d at index %d: ", value, pos);
    display(arr, n);

    // --- DELETION ---
    printf("\n--- Deletion ---\n");
    pos = 1; // Delete element at index 1 (the value 20)

    // Shift elements to the left to fill the gap
    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--; // Decrease size

    printf("After deleting element at index %d: ", pos);
    display(arr, n);

    return 0;
}