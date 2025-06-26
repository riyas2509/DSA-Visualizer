// stack.c
#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int stack[MAX], top = -1;

void push(int val) {
    if(top == MAX-1) {
        printf("Stack Overflow!\n");
        return;
    }
    stack[++top] = val;
    printf("Pushed: %d\n", val);
}

void pop() {
    if(top == -1) {
        printf("Stack Underflow!\n");
        return;
    }
    printf("Popped: %d\n", stack[top--]);
}

void displayStack() {
    printf("\n--- Stack ---\n");
    if(top == -1) {
        printf("|   EMPTY   |\n");
    } else {
        for(int i = top; i >= 0; i--) {
            printf("|   %3d    |\n", stack[i]);
        }
    }
    printf("-------------\n");
}

void stackMenu() {
    int choice, val;
    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Back to Main Menu\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &val);
                push(val);
                break;
            case 2:
                pop();
                break;
            case 3:
                displayStack();
                break;
            case 4:
                return;
            default:
                printf("Invalid input.\n");
        }
    }
}