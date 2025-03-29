#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *next;
};
int main() {
    // Creating nodes
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));

// Initialize nodes

    head->data = 1;
    head->next = second;
    second->data = 2;
    second->next = third;
    third->data = 3;
    third->next = NULL;
    struct Node *temp = head;	 // Traversing the list
    while (temp != NULL) {
        printf("Data: %d\n", temp->data); // Output: Data: 1, Data: 2, Data: 3
        temp = temp->next;
    }
    free(third); 		 // Free allocated memory
    free(second);
    free(head);
    return 0;
}
