#include<stdio.h>
#include<stdlib.h>

int top = -1;
int n = 5;
int stack[5];

void push();
void pop();
void peek();
void display();

void push()
{

if(top==n-1)
{
    printf("\nStack is Full");
    return;
}
int item;
printf("\nEnter the element:");
scanf("%d",&item);
top++;
stack[top]=item;
display();
}

void pop()
{
if(top==-1)
{
printf("Stack is empty");
return;
}
int item;
item=stack[top];
top--;
printf("\nThe popped element is = %d",item);
display();
}

void peek()
{
if(top==-1)
{
printf("\nStack is empty");
}
else{
    printf("The top of stack is = %d",stack[top]);
}
}

void display()
{
printf("\nThe stack is:");
for(int i=0;i<=top;i++)
{
printf(" %d ",stack[i]);
}
}

int main()
{
int choice;
while(choice!=5)
{
printf("\n1.PUSH\n2.POP\n3.PEEK\n4.DISPLAY\n5.EXIT");
printf("\nEnter the operation:");
scanf("%d",&choice);
switch(choice)
{
    case 1:push();
            break;
    case 2:pop();
            break;
    case 3:peek();
            break;
    case 4:display();
            break;
    case 5:exit(0);
            break;
    default:printf("Invalid choice");                
}
}

return 0;
}