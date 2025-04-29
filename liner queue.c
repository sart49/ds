 //liner queue

 
#include <stdio.h> 
#include <stdlib.h> 
 
#define MAX 5  
int queue[MAX]; 
int front = -1, rear = -1; 
 
 
void enqueue(int value); 
int dequeue(); 
int peek(); 
void display(); 
 
int main() { 
    int choice, value; 
 
    while (1) { 
        printf("\nQueue Operations:\n"); 
        printf("1. Enqueue\n"); 
        printf("2. Dequeue\n"); 
        printf("3. Peek\n"); 
        printf("4. Display\n"); 
        printf("5. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
 
        switch (choice) { 
            case 1: 
                printf("Enter value to enqueue: "); 
                scanf("%d", &value); 
                enqueue(value); 
                break; 
            case 2: 
                value = dequeue(); 
                if (value != -1) 
                    printf("Dequeued value: %d\n", value); 
                break; 
            case 3: 
                value = peek(); 
                if (value != -1) 
                    printf("Front value: %d\n", value); 
                break; 
            case 4: 
                display(); 
                break; 
            case 5: 
                exit(0); 
            default: 
                printf("Invalid choice! Try again.\n"); 
        } 
    } 
 
    return 0; 
} 
 
 
void enqueue(int value) { 
    if (rear == MAX - 1) { 
        printf("Queue Overflow! Cannot enqueue %d.\n", value); 
        return; 
    } 
    if (front == -1) // First element being inserted 
        front = 0; 
    queue[++rear] = value; 
    printf("%d enqueued into the queue.\n", value); 
} 
 

int dequeue() { 
    if (front == -1 || front > rear) { 
        printf("Queue Underflow! Nothing to dequeue.\n"); 
        return -1; 
    } 
    return queue[front++]; 
} 
 
 
int peek() { 
    if (front == -1 || front > rear) { 
        printf("Queue is empty!\n"); 
        return -1; 
    } 
    return queue[front]; 
} 
 

void display() { 
 int i; 
    if (front == -1 || front > rear) { 
        printf("Queue is empty!\n"); 
        return; 
    } 
    printf("Queue elements: "); 
    for (i = front; i <= rear; i++) 
        printf("%d ", queue[i]); 
    printf("\n"); 
} 
 
 
 
 
 
 
 
 
 
