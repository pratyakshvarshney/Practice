#include <stdio.h>

#define MAX 50 // Maximum size for the array and stacks

// Function to perform partitioning
int partition(int A[], int BEG, int END) {
    int LEFT = BEG, RIGHT = END;
    int LOC = BEG, TEMP;

    while (LEFT != RIGHT) {
        // Scan from right to left
        while (A[LOC] <= A[RIGHT] && LOC != RIGHT) {
            RIGHT--;
        }
        if (LOC == RIGHT) return LOC;
        if (A[LOC] > A[RIGHT]) {
            TEMP = A[LOC];
            A[LOC] = A[RIGHT];
            A[RIGHT] = TEMP;
            LOC = RIGHT;
        }

        // Scan from left to right
        while (A[LOC] >= A[LEFT] && LOC != LEFT) {
            LEFT++;
        }
        if (LOC == LEFT) return LOC;
        if (A[LOC] < A[LEFT]) {
            TEMP = A[LOC];
            A[LOC] = A[LEFT];
            A[LEFT] = TEMP;
            LOC = LEFT;
        }
    }
    return LOC;
}

// Iterative Quick Sort function
void quickSort(int A[], int N) {
    int LOWER[MAX], UPPER[MAX], TOP = -1; // Stacks for storing boundary values
    int BEG, END, LOC;

    if (N > 1) {
        // Push the initial boundaries onto the stack
        TOP++;
        LOWER[TOP] = 0;
        UPPER[TOP] = N - 1;
    }

    while (TOP != -1) {
        // Pop the sublist boundaries from the stack
        BEG = LOWER[TOP];
        END = UPPER[TOP];
        TOP--;

        // Partition the array and get the location of the pivot
        LOC = partition(A, BEG, END);

        // If there are elements on the left side of the pivot, push onto the stack
        if (BEG < LOC - 1) {
            TOP++;
            LOWER[TOP] = BEG;
            UPPER[TOP] = LOC - 1;
        }

        // If there are elements on the right side of the pivot, push onto the stack
        if (LOC + 1 < END) {
            TOP++;
            LOWER[TOP] = LOC + 1;
            UPPER[TOP] = END;
        }
    }
}

// Function to print the array
void printArray(int A[], int N) {
    for (int i = 0; i < N; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int A[MAX], N;

    // Input the array size
    printf("Enter the number of elements: ");
    scanf("%d", &N);

    // Input the array elements
    printf("Enter the elements: ");
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    // Perform Quick Sort
    quickSort(A, N);

    // Print the sorted array
    printf("Sorted array: ");
    printArray(A, N);

    return 0;
}
