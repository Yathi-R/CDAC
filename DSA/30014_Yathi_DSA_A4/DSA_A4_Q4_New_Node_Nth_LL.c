/*To insert a new node at the end to the linked list*/

#include<stdio.h>
#include <stdlib.h>

//struct node for linked list
struct node
{
    int data;
    struct node *next;
};

//Function to create linked list with n elements
struct node *createLinkedList(int n){

    struct node *temp=NULL, *previous = NULL;
    struct node *head = NULL;

    //loop to run for n times
    for (int i = 1; i<=n; i++){
        temp = (struct node *)malloc(sizeof(struct node));
        //checking if memeory is allocated or not
        if(temp == NULL){
            printf("Memory allocation failed:\n");
            exit(1);
        }
        else{
            printf("Enter the data for node %d:", i);
            scanf("%d", &temp->data);
            temp->next = NULL;
            
            //if it's first element updating head to point first node
            if(head == NULL){
                head = temp;
            }
            //else updating previous node with current nodes address
            else{
                previous->next = temp;
            }

            //moving the previous to point to current node 
            previous = temp;

            printf("Node %d inserted\n", i);
        }
    }
    //returns the head nodes address
    return head;
}

//Function to display elements in Linked List
void display_elements(struct node* head){

    //temp node to traverse the Linked List
    struct node *temp = head;

    printf("Node Element: \n");

    //Loop to traverse until last node with NULL Address
    while(temp != NULL){
        printf("%d\n", temp->data); //printing the data in each node
        temp = temp->next;    //moving the temp node to next node
    }
    printf("NULL\n"); // to denote end of list
}

void new_node_end(struct node** head) {

    // Allocate memory for the new node and check for success
    struct node *new_node = (struct node *)malloc(sizeof(struct node));

    if (!new_node) {
        perror("Memory allocation failed");
        exit(1);
    }

    // Get data for the new node
    printf("Enter the data for the last node: ");
    scanf("%d", &new_node->data);

    // New node will always point to NULL (end of the list)
    new_node->next = NULL;

    // If the list is empty, make the new node the head
    if (*head == NULL) {
        *head = new_node;
        printf("Node inserted at the beginning as the list was empty.\n");
    } else {
        // Traverse to the end of the list
        struct node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
        printf("Node inserted at the end.\n");
    }
}

void insert_at_position(struct node **head, int position) {

    // Allocate memory for the new node
    struct node *new_node = (struct node *)malloc(sizeof(struct node));

    if (!new_node) {
        perror("Memory allocation failed");
        exit(1);
    }

    // Get the data for the new node
    printf("Enter the data for the new node: ");
    scanf("%d", &new_node->data);

    // Insert at the beginning (position 1)
    if (position == 1) {
        new_node->next = *head;
        *head = new_node;
        printf("Node inserted at position 1 (beginning).\n");
        return;
    }

    // Traverse to the (n-1)th node
    struct node *temp = *head;
    int current_position = 1;

    while (temp != NULL && current_position < position - 1) {
        temp = temp->next;
        current_position++;
    }

    // If we reached the end or the position is out of range
    if (temp == NULL) {
        printf("Position is out of range. Node not inserted.\n");
        free(new_node);  // Clean up memory since we didn't use it
        return;
    }

    // Link the new node
    new_node->next = temp->next;
    temp->next = new_node;

    printf("Node inserted at position %d.\n", position);
}

int main() {
    struct node *head = NULL;
    int choice, n, position;

    do {
        printf("\n--- Linked List Menu ---\n");
        printf("1. Create Linked List\n");
        printf("2. Insert at End\n");
        printf("3. Insert at nth Position\n");
        printf("4. Display Elements\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (head != NULL) {
                    printf("Linked List already created. Please restart to create again.\n");
                    break;
                }
                printf("Enter the number of nodes: ");
                scanf("%d", &n);
                head = createLinkedList(n);
                break;

            case 2:
                new_node_end(&head);
                break;

            case 3:
                printf("Enter the position to insert the new node: ");
                scanf("%d", &position);
                insert_at_position(&head, position);
                break;

            case 4:
                display_elements(head);
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Please select again.\n");
        }
    } while (choice != 5);

    return 0;
}