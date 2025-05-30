//link list

#include <stdio.h> 
#include <stdlib.h> 
 
 
struct Node { 
    int data; 
    struct Node* next; 
}; 
 

struct Node* top = NULL; 
 
 
int isEmpty() { 
    return top == NULL; 
} 
 

void push(int value) { 
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
    if (newNode == NULL) { 
        printf("Stack Overflow!\n"); 
        return; 
    } 
    newNode->data = value; 
    newNode->next = top; 
    top = newNode; 
    printf("%d pushed onto stack.\n", value); 
} 
 

void pop() { 
    struct Node* temp = top; 
    int poppedValue; 
    if (isEmpty()) { 
 printf("Stack Underflow!\n"); 
 return; 
    } 
 
    poppedValue = temp->data; 
    top = top->next; 
    free(temp); 
    printf("%d popped from stack.\n", poppedValue); 
} 
 
 
void peek() { 
    if (isEmpty()) { 
        printf("Stack is empty.\n"); 
        return; 
    } 
    printf("Top element: %d\n", top->data); 
} 
 
 
void display() { 
    struct Node* temp = top; 
    if (isEmpty()) { 
 printf("Stack is empty.\n"); 
 return; 
    } 
 
    printf("Stack elements: "); 
    while (temp != NULL) { 
        printf("%d ", temp->data); 
        temp = temp->next; 
    } 
    printf("\n"); 
} 
 
int main() { 
    int choice, value; 
 
    while (1) { 
        printf("\nStack Operations Menu:\n"); 
        printf("1. Push\n"); 
        printf("2. Pop\n"); 
        printf("3. Peek\n"); 
        printf("4. Display\n"); 
        printf("5. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
 
        switch (choice) { 
            case 1: 
                printf("Enter value to push: "); 
                scanf("%d", &value); 
                push(value); 
                break; 
            case 2: 
                pop(); 
                break; 
            case 3: 
                peek(); 
                break; 
            case 4: 
                display(); 
                break; 
            case 5: 
                printf("Exiting...\n"); 
                exit(0); 
            default: 
                printf("Invalid choice, please try again.\n"); 
        } 
    } 
    return 0; 
} 
 
