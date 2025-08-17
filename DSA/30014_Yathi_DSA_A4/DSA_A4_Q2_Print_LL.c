/*To print the elements in linked list*/

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

int main(){
    int n;

    //user input for number of elements in Linked list
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    //Initializing head node with NULL
    struct node *head = NULL;

    //calling create function with n value to create the Linked List
    head = createLinkedList(n);

    printf("Printing the elements in Linked List: \n");
    display_elements(head);

    return 0;
}