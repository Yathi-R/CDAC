#include <stdio.h>
#include <stdlib.h>

#define MAX 100   // Maximum size of the stack

int stack[MAX];
int top = -1;    // Initialize stack as empty

// Function to push an element into the stack
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow! Cannot insert %d\n", value);
    } 
    else {
        top++;
        stack[top] = value;
        printf("%d pushed into the stack.\n", value);
    }
}

// Function to pop an element from the stack
int pop() {
    if (top == -1) {
        printf("Stack Underflow! The stack is empty.\n");
        return -1;
    } 
    else {
        int value = stack[top];
        top--;
        printf("%d popped from the stack.\n", value);
        return value;
    }
}

// Function to display the stack elements
void printStack() {
    if (top == -1) {
        printf("Stack is empty.\n");
    } 
    else {
        printf("Stack elements (Top to Bottom): ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

// Function to display the top element without removing it
void topElement() {
    if (top == -1) {
        printf("Stack is empty. No top element.\n");
    } 
    else {
        printf("Top element is: %d\n", stack[top]);
    }
}

// Main function with menu-driven logic
int main() {
    int choice, value;
    
    do {
        printf("\n--- Stack Operations ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Print\n");
        printf("4. Top\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                printStack();
                break;
            case 4:
                topElement();
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice !=5 );

    return 0;
}
