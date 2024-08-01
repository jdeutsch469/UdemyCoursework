/*
 * Node.h
 *
 *  Created on: Jul 30, 2024
 *      Author: jdeutsch
 */

#ifndef NODE_H_
#define NODE_H_
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the priority linked list
typedef struct Node {
    //int data; // Data stored in the node
    //int priority; // Priority of the node
    TCB_t taskControlBlock;
	struct Node* next; // Pointer to the next node
} Node;

// Function to create a new node with given data and priority
Node* createNode(TCB_t data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->taskControlBlock = data;
    //newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node into the priority linked list
void insertNode(Node** head, TCB_t data) {
    Node* newNode = createNode(data);
    // If the list is empty or the new node has higher priority than the head
    if (*head == NULL || (*head)->taskControlBlock.task_priority > newNode->taskControlBlock.task_priority) {
        newNode->next = *head;
        *head = newNode;
    } else {
        // Traverse the list to find the correct position for the new node
    	//Travesrse tail?
        Node* current = *head;
        while (current->next != NULL && current->next->taskControlBlock.task_priority <= newNode->taskControlBlock.task_priority) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Function to print the priority linked list
void printList(Node* head) {
    while (head != NULL) {
        printf("Priority: %d\n", head->taskControlBlock.task_priority);
        head = head->next;
    }
}

// Function to free the memory allocated for the linked list
void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

Node* removeHighestPriorityNode(Node** head) {
    if (*head == NULL) {
        return NULL;
    }
    Node* temp = *head;
    *head = (*head)->next;
    temp->next = NULL;
    return temp;
}
/*
int main() {
    Node* head = NULL;

    insert(&head, 10, 2);
    insert(&head, 20, 1);
    insert(&head, 30, 3);

    printf("Priority Linked List:\n");
    printList(head);

    // Free allocated memory
    freeList(head);

    return 0;
}
*/


#endif /* NODE_H_ */
