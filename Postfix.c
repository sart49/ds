//Postfix  


#include <stdio.h> 
#include <stdlib.h> 
#include <ctype.h> 
 
#define MAX 100  

 
int stack[MAX]; 
int top = -1; 
 
 
void push(int value); 
int pop(); 
int evaluatePostfix(char *expression); 
 
int main() { 
 int result; 
    char expression[MAX]; 
 
    printf("Enter a valid postfix expression: "); 
    scanf("%s", expression); 
 
    result = evaluatePostfix(expression); 
    printf("Result: %d\n", result); 
 
    return 0; 
} 
 
 
void push(int value) { 
    if (top == MAX - 1) { 
        printf("Stack Overflow! Cannot push %d.\n", value); 
        return; 
    } 
    stack[++top] = value; 
} 
 

int pop() { 
    if (top == -1) { 
        printf("Stack Underflow! Invalid expression.\n"); 
        exit(1); 
    } 
    return stack[top--]; 
} 
 
 
int evaluatePostfix(char *expression) { 
    int i, operand1, operand2, result; 
 
    for (i = 0; expression[i] != '\0'; i++) { 
        if (isdigit(expression[i])) { 
            push(expression[i] - '0');  
        } else { 
            operand2 = pop(); 
            operand1 = pop(); 
 
            switch (expression[i]) { 
                case '+': result = operand1 + operand2; break; 
                case '-': result = operand1 - operand2; break; 
                case '*': result = operand1 * operand2; break; 
                case '/':  
                    if (operand2 == 0) { 
                        printf("Error: Division by zero!\n"); 
                        exit(1); 
                    } 
                    result = operand1 / operand2;  
                    break; 
                default: 
                    printf("Error: Invalid operator %c\n", 
expression[i]); 
                    exit(1); 
            } 
 
            push(result); 
        } 
    } 
 
    return pop(); 
} 
 
 