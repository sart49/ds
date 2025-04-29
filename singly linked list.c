singly linked list

  
#include <stdio.h> 
#include <stdlib.h> 
 

struct Node { 
    int data; 
    struct Node* next; 
}; 
void insertAtBeginning(struct Node** head, int value) { 
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
    newNode->data = value; 
    newNode->next = *head; 
    *head = newNode; 
} 
void insertAtEnd(struct Node** head, int value) { 
    struct Node* temp = *head; 
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
    newNode->data = value; 
    newNode->next = NULL; 
 
    if (*head == NULL) { 
 *head = newNode; 
 return; 
    } 
 
 
    while (temp->next != NULL) { 
        temp = temp->next; 
    } 
    temp->next = newNode; 
} 
void deleteNode(struct Node** head, int value) { 
    struct Node* temp = *head, *prev = NULL; 
 
    
    if (temp != NULL && temp->data == value) { 
        *head = temp->next; 
        free(temp); 
        return; 
    } 
 
   
    while (temp != NULL && temp->data != value) { 
        prev = temp; 
        temp = temp->next; 
    } 
 
    
    if (temp == NULL) { 
        printf("Value not found in the list.\n"); 
        return; 
    } 
 

    prev->next = temp->next; 
    free(temp); 
} 
 
void displayList(struct Node* head) { 
    struct Node* temp = head; 
    if (head == NULL) { 
        printf("List is empty.\n"); 
        return; 
    } 
 
    printf("Linked List: "); 
    while (temp != NULL) { 
        printf("%d -> ", temp->data); 
        temp = temp->next; 
    } 
    printf("NULL\n"); 
} 
 
void search(struct Node* head, int key) { 
    struct Node* temp = head; 
    int pos = 1; 
    while (temp != NULL) { 
        if (temp->data == key) { 
            printf("Element %d found at position %d\n", key, pos); 
            return; 
        } 
        temp = temp->next; 
        pos++; 
    } 
    printf("Element %d not found in the list.\n", key); 
} 
 
int main() { 
    struct Node* head = NULL; 
    int choice, value; 
 
    while (1) { 
        printf("\nMenu:\n"); 
        printf("1. Insert at Beginning\n"); 
        printf("2. Insert at End\n"); 
        printf("3. Delete a Node\n"); 
        printf("4. Display List\n"); 
        printf("5. Search for an Element\n"); 
        printf("6. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
 
        switch (choice) { 
            case 1: 
                printf("Enter value to insert at beginning: "); 
                scanf("%d", &value); 
                insertAtBeginning(&head, value); 
                break; 
            case 2: 
                printf("Enter value to insert at end: "); 
                scanf("%d", &value); 
                insertAtEnd(&head, value); 
                break; 
            case 3: 
                printf("Enter value to delete: "); 
                scanf("%d", &value); 
                deleteNode(&head, value); 
                break; 
            case 4: 
                displayList(head); 
                break; 
            case 5: 
                printf("Enter value to search: "); 
                scanf("%d", &value); 
                search(head, value); 
                break; 
            case 6: 
                exit(0); 
            default: 
                printf("Invalid choice! Please try again.\n"); 
        } 
    } 
 
    return 0; 
} 
 
 
