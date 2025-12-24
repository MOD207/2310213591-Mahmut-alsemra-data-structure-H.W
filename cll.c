#include <stdio.h>
#include <stdlib.h>

// 1. Structure Definition
struct Node {
    int data;
    struct Node* next;
};

// 2. Traversal: Uses a do-while loop to handle the circle
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("Circular List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(Back to Head: %d)\n", head->data);
}

// 3. Insertion: Adds a node at the end
void insert(struct Node** head, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;

    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head; // Point to itself
        return;
    }

    struct Node* temp = *head;
    // Find the last node (the one pointing to head)
    while (temp->next != *head) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = *head; // Maintain the circle
}

// 4. Deletion: Handles head, middle, and end nodes
void deleteNode(struct Node** head, int key) {
    if (*head == NULL) return;

    struct Node *curr = *head, *prev = NULL;

    // CASE 1: Only one node in the list
    if (curr->data == key && curr->next == *head) {
        free(curr);
        *head = NULL;
        return;
    }

    // CASE 2: Deleting the Head node
    if (curr->data == key) {
        // Find the last node to update its next pointer
        while (curr->next != *head) {
            curr = curr->next;
        }
        curr->next = (*head)->next;
        free(*head);
        *head = curr->next;
        return;
    }

    // CASE 3: Deleting a middle or last node
    curr = *head;
    while (curr->next != *head && curr->data != key) {
        prev = curr;
        curr = curr->next;
    }

    if (curr->data == key) {
        prev->next = curr->next;
        free(curr);
    } else {
        printf("\nValue %d not found in list.\n", key);
    }
}

// 5. Main function to test all operations
int main() {
    struct Node* head = NULL;

    // Testing Insertion
    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);
    insert(&head, 40);
    
    printf("Initial List:\n");
    display(head);

    // Testing Deletion of Head
    printf("\nDeleting Head (10)...\n");
    deleteNode(&head, 10);
    display(head);

    // Testing Deletion of Middle Node
    printf("\nDeleting 30...\n");
    deleteNode(&head, 30);
    display(head);

    // Testing Deletion of Last Node
    printf("\nDeleting 40...\n");
    deleteNode(&head, 40);
    display(head);

    return 0;
}