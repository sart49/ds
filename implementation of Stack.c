// implementation of Stack

#include<stdio.h> 
int stack[100],choice,n,top,x,i; 
void push(void); 
void pop(void); 
void display(void); 
int main() 
{ 
//clrscr(); 
top=-1; 
printf("\nEnter the size of STACK[MAX=100]:"); 
scanf("%d",&n); 
printf("\n\t STACK OPERATIONS USING ARRAY"); 
printf("\n\t----------"); 
printf("\n\t1.PUSH\n\t2.POP\n\t3.DISPLAY \n\t4.EXIT"); 
do 
{ 
printf("\nEnter the choice:"); 
scanf("%d",&choice); 
switch(choice) 
{ 
case 1: 
push(); 
break; 
case 2: 
pop(); 
break; 
case 3: 
display(); 
break; 
case 4: 
printf("\n\t EXIT POINT"); 
break; 
default: 
printf("\n\tPlease Enter a valid choice(1/2/3/4)"); 
} 
} 
while(choice!=4); 
return 0; 
} 
void push() 
{ 
if(top>=n-1) 
{ 
printf("\n\tStack is overflow"); 
} 
else 
{ 
printf("Enter a value to be pushed:"); 
scanf("%d",&x); 
top++; 
stack[top]=x; 
} 
} 
void pop() 
{ 
if(top<=-1) 
{ 
printf("\n\tStack is underflow"); 
} 
else 
{ 
printf("\n\t THE popped elements is %d",stack[top]); 
top--; 
} 
} 
void display() 
{ 
if(top>=0) 
{ 
printf("\n The elements in stack\n"); 
for(i=top;i>=0;i--) 
printf("\n%d",stack[i]); 
printf("\n PRESS NEXT CHOICE"); 
} 
else 
{ 
printf("\n THE STACK IS EMPTY"); 
} 
} 
