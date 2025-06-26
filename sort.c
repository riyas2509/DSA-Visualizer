// sort.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // for sleep()
#define SIZE 10

int arr[SIZE];

// Function to draw array as bars
void drawBars(int arr[], int size, int highlight1, int highlight2) {
    printf("\nStep:\n");
    for (int i = 0; i < size; i++) {
        if (i == highlight1 || i == highlight2)
            printf(">");
        else
            printf(" ");
        for (int j = 0; j < arr[i]; j++) {
            printf("#");
        }
        printf(" (%d)\n", arr[i]);
    }
    printf("\n");
}

// Bubble Sort with step-by-step visual
void bubbleSortAnimation(int arr[], int size) {
    int i, j, temp;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            system("clear"); // For Linux/macOS
            // system("cls"); // Use this on Windows instead
            drawBars(arr, size, j, j+1);
            sleep(1); // Pause for 1 second
            if (arr[j] > arr[j + 1]) {
                // Swap
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Final display
    system("clear");
    drawBars(arr, size, -1, -1);
    printf("Sorted!\n");
}

// Sort Menu
void sortMenu() {
    printf("\n--- Sorting Animation (Bubble Sort) ---\n");
    printf("Enter %d elements (1-20 recommended):\n", SIZE);
    for (int i = 0; i < SIZE; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    bubbleSortAnimation(arr, SIZE);
}