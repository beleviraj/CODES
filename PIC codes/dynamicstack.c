#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

struct node *top=0;

void display();

void push()
{
 int item;
 struct node *newnode;
 newnode=(struct node*)malloc(sizeof(struct node));
 printf("\nEnter the data: ");
 scanf("%d",&item);
 newnode->data=item;
 newnode->link=top;
 top=newnode; 
 display();
}

void display()
{
    struct node *temp;
    temp=top;
    if(top==NULL){
        printf("\nStack is empty");
    }
    else{
        printf("\nThe stack is: ");
        while(temp!=NULL){
            printf(" %d ",temp->data);
            temp=temp->link;
        }
    }
}

void peek()
{
    if(top==NULL){
        printf("\nStack is empty");
    }
    else{
        printf("\nThe top of stack is = %d ",top->data);
    }
}

void pop(){
    struct node *temp;
    temp=top;
    if(top==NULL){
        printf("\nstack is empty");
    }
    else{
        printf("\nThe popped element is = %d",top->data);
        top=temp->link;
        free(temp);
    }
    display();
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