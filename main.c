// main.c
#include <stdio.h>
#include <stdlib.h>

// Function declarations
void stackMenu();
void queueMenu();
void treeMenu();
void sortMenu();

int main() {
    int choice;

    while (1) {
        printf("\n===== DSA VISUALIZER =====\n");
        printf("1. Stack Visualizer\n");
        printf("2. Queue Visualizer\n");
        printf("3. Binary Tree Visualizer\n");
        printf("4. Sorting Animation\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: stackMenu(); break;
            case 2: queueMenu(); break;
            case 3: treeMenu(); break;
            case 4: sortMenu(); break;
            case 5: 
                printf("Thank you for using DSA Visualizer!\n"); 
                exit(0);
            default: 
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}