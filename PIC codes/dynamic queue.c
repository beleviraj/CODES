#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *front=0;
struct node *rear=0;


void display();

void enqueue(int x)
{
    struct node*newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=0;
    if(front==0 && rear==0){
        front=rear=newnode;
    }
    else{
        rear->next=newnode;
        rear=newnode;
    }
    display();
}

void display(){
    struct node *temp;
    if(front==0 && rear==0){
        printf("\nQueue is empty");
    }
    else{
        temp=front;
        while(temp!=0){
            printf(" %d ",temp->data);
            temp=temp->next;
        }
    }
}

void dequeue()
{
    struct node *temp;
    if(front==0 && rear==0){
        printf("\nQueue is empty");
    }
    else if(front==rear){
        printf("\nThe dequeued element is: %d",front->data);
        front=rear=0;
    }
    else{
        printf("\nThe dequeued element is: %d",front->data);
        temp=front;
        front=temp->next;
        free(temp);
    }
}

  int main(){
    int choice,item;
    while(choice!=4){
        printf("\n1.Add element in queue\n2.Delete element from queue\n3.Display\n4.Exit\n");
        printf("\nEnter the operation : ");
        scanf("%d",&choice);
        switch(choice){
            case 1:printf("\nEnter the element : ");
                    scanf("%d",&item);
                    enqueue(item);
                    break;
            case 2:dequeue();
                    break;
            case 3:display();
                     break;
            case 4:exit(0);
                    break;

        }
    }
    return 0;
}