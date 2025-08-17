#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int queue[MAX_SIZE];

int front = -1, rear = -1;

// Function to add an element to the queue
void enqueue(int x) {
    if (rear + 1 == MAX_SIZE) {
        printf("Queue is full, can't enqueue: %d\n", x);
    } else {
        if (front == -1) {
            front = 0;  // Initialize front if this is the first element
        }
        rear++;
        queue[rear] = x;
        printf("%d enqueued in the queue.\n", x);
    }
}

// Function to remove an element from the queue
void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty, nothing to dequeue.\n");
    } else {
        printf("%d dequeued from the queue.\n", queue[front]);
        front++;
        if (front > rear) {
            front = -1;
            rear = -1;
        }
    }
}

// Function to display the current size of the queue
void queue_size() {
    if (front == -1) {
        printf("Queue is empty, size is 0.\n");
    } else {
        printf("Current queue size: %d\n", rear - front + 1);
    }
}

// Function to display the front element of the queue
void queue_front() {
    if (front == -1) {
        printf("Queue is empty, no front element.\n");
    } else {
        printf("Front element is: %d\n", queue[front]);
    }
}

// Function to display all elements in the queue
void queue_display() {
    if (front == -1) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements (Front to Rear): ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main(){

    int choice, value;


    do{
        printf("\n--- Queue Operation ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Size\n");
        printf("4. Front Element:\n");
        printf("5. Display Queue\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value to enqueue:");
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
            break;
        }

    }while(choice != 6);

    return 0;
}