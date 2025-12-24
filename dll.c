#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

void insertEnd(struct Node** head, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;

    // If list is empty
    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }

    // Traverse to the last node
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

void deleteNode(struct Node** head, int key) {
    struct Node* temp = *head;

    // Search for the node to be deleted
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    if (temp == NULL) return; // Value not found

    // If the node to be deleted is the head
    if (*head == temp) {
        *head = temp->next;
    }

    // Update 'next' of previous node
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }

    // Update 'prev' of next node
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    free(temp);
}

void traverse(struct Node* head) {
    struct Node* last;
    printf("Forward: ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        last = head;
        head = head->next;
    }
    printf("NULL\n");

    printf("Backward: ");
    while (last != NULL) {
        printf("%d -> ", last->data);
        last = last->prev;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);

    printf("After Insertion:\n");
    traverse(head);

    printf("\nAfter Deleting 20:\n");
    deleteNode(&head, 20);
    traverse(head);

    return 0;
}