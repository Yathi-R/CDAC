/*To create linked list with n elements*/

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

int main(){
    int n;

    //user input for number of elements in Linked list
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    //Initializing head node with NULL
    struct node *head = NULL;

    //calling create function with n value to create the Linked List
    head = createLinkedList(n);

    return 0;
}