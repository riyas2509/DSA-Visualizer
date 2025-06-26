// queue.c
#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int val) {
    if(rear == MAX - 1) {
        printf("Queue Overflow!\n");
        return;
    }
    if(front == -1) front = 0;
    queue[++rear] = val;
    printf("Enqueued: %d\n", val);
}

void dequeue() {
    if(front == -1 || front > rear) {
        printf("Queue Underflow!\n");
        return;
    }
    printf("Dequeued: %d\n", queue[front++]);
    if (front > rear) {
        front = rear = -1; // Reset queue
    }
}

void displayQueue() {
    printf("\n--- Queue ---\n");
    if(front == -1 || front > rear) {
        printf("Queue is EMPTY\n");
        return;
    }
    printf("Front -> ");
    for(int i = front; i <= rear; i++) {
        printf("[%d] ", queue[i]);
    }
    printf("<- Rear\n");
}

void queueMenu() {
    int choice, val;
    while (1) {
        printf("\n--- Queue Menu ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Back to Main Menu\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &val);
                enqueue(val);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                displayQueue();
                break;
            case 4:
                return;
            default:
                printf("Invalid input.\n");
        }
    }
}