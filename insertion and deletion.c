//insertion and deletion

#include<stdio.h> 
#include<conio.h> 
int i; 
//function to insert element 
//at a specific position 
void insertElement(int arr[],int n,int x,int pos) 
{ 
//shift element to the right 
//which are on the right side of pos 
for( i=n-1;i>=pos;i--) 
arr[i+1]=arr[i]; 
arr[pos]=x; 
} 
void deleteElement(int arr[],int n) 
{ 
int index; 
printf("\nEnter the index of the element to be deleted:"); 
scanf("%d",&index); 
if (index>=n+1) 
{ 
printf("\n Deletion is not possible in the array."); 
} 
else 
{ 
for(i=index;i<n-1;i++) 
arr[i]=arr[i+1]; 
printf("\n array after deleting experiment is:\n"); 
for(i=0;i<n-1;i++) 
 
printf("%d\t",arr[i]); 
} 
} 
//Drive's code 
void main() 
{ 
int arr[15]={2,4,1,8,5}; 
int n=5,x,pos; 
clrscr(); 
printf("before insertion:"); 
for (i=0;i<n;i++) 
printf("%d\t",arr[i]); 
printf("\n"); 
x=100,pos=4; 
//Function call 
insertElement(arr,n,x,pos); 
n++; 
printf("after insertion:"); 
for(i=0;i<=n;i++) 
printf("%d\t",arr[i]); 
deleteElement(arr,n); 
n--; 
/*printf("After insertion:"); 
for (int i=0;i<n;i++) 
printf("%d",arr[i]);*/ 
getch(); 
}