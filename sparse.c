#include <stdio.h>

int main() {
    // 1. Your original "Sparse" Matrix
    int matrix[3][3] = {
        {5, 0, 0},
        {0, 0, 8},
        {0, 2, 0}
    };

    printf("Original Matrix:\n");
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // 2. Simple Transformation
    // We print the "Address" and "Value" for non-zero items
    printf("\nTransformed (Non-zero elements only):\n");
    printf("Location -> Value\n");
    
    for (int r = 0; r < 3; r++) {      // Loop through rows
        for (int c = 0; c < 3; c++) {  // Loop through columns
            if (matrix[r][c] != 0) {   // If it's not zero, show it
                printf("[%d][%d]   -> %d\n", r, c, matrix[r][c]);
            }
        }
    }

    return 0;
}