#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

int circularQueue[MAX_SIZE];
int front = -1, rear = -1;

// Function to add an element to the circular queue
void enqueue(int x) {
    if ((rear + 1) % MAX_SIZE == front) {
        printf("Queue is full, cannot enqueue %d\n", x);
    } 
    else {
        if (front == -1) {
            front = 0;  // Initialize front if this is the first element
        }
        rear = (rear + 1) % MAX_SIZE;
        circularQueue[rear] = x;
        printf("%d enqueued in the circular queue.\n", x);
    }
}

// Function to remove an element from the circular queue
void dequeue() {
    if (front == -1) {
        printf("Queue is empty, nothing to dequeue.\n");
    } 
    else {
        printf("%d dequeued from the circular queue.\n", circularQueue[front]);
        if (front == rear) {
            // If the queue becomes empty after the dequeue operation
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
        }
    }
}

// Function to display the current size of the circular queue
void queue_size() {
    if (front == -1) {
        printf("Queue is empty, size is 0.\n");
    } 
    else {
        int size = (rear - front + MAX_SIZE) % MAX_SIZE + 1;
        printf("Current circular queue size: %d\n", size);
    }
}

// Function to display the front element of the circular queue
void queue_front() {
    if (front == -1) {
        printf("Queue is empty, no front element.\n");
    } 
    else {
        printf("Front element is: %d\n", circularQueue[front]);
    }
}

// Function to display all elements in the circular queue
void queue_display() {
    if (front == -1) {
        printf("Queue is empty.\n");
    } 
    else {
        printf("Circular Queue elements (Front to Rear): ");
        int i = front;
        while (1) {
            printf("%d ", circularQueue[i]);
            if (i == rear)
                break;
            i = (i + 1) % MAX_SIZE;
        }
        printf("\n");
    }
}

// Main function with menu-driven logic
int main() {
    int choice, value;

    do {
        printf("\n--- Circular Queue Operation ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Size\n");
        printf("4. Front Element\n");
        printf("5. Display Queue\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                queue_size();
                break;
            case 4:
                queue_front();
                break;
            case 5:
                queue_display();
                break;
            case 6:
                printf("Exiting .....\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 6);

    return 0;
}
