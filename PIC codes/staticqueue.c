#include<stdio.h>
#include<stdlib.h>

int n=5;
int queue[5];
int front=-1,rear=-1;

void dequeue();
void display();
void peek();

void enqueue(int x){
    if(rear==n-1){
        printf("\nQueue is Full");
    }
    else if(front==-1 && rear==-1){
        front=rear=0;
        queue[rear]=x;
    }
    else{
        rear++;
        queue[rear]=x;
    }
    display();
}

void dequeue(){
    if(front==-1 && rear==-1){
        printf("\nQueue is Empty");
    }
    else if(front==rear){
        printf("\nThe dequeued element is=%d",queue[front]);
        front=rear=-1;
    }
    else{
        printf("\nThe dequeued element is=%d\n",queue[front]);
        front++;
    }
    display();
}

void display(){
    if(front==-1&&rear==-1){
        printf("\nQueue is empty");
    }
    else{
        printf("The Queue is :");
        for(int i=front;i<rear+1;i++){
            printf(" %d ",queue[i]);
        }
    }
}

void peek(){
    if(front==-1&&rear==-1){
        printf("Queue is empty");
    }
    else{
        printf("Peek element is: %d",queue[front]);
    }
}
int main(){
    int choice,item;
    while(choice!=5){
        printf("\n1.Add element in queue\n2.Delete element from queue\n3.PEEk\n4.Display\n5.Exit\n");
        printf("\nEnter the operation : ");
        scanf("%d",&choice);
        switch(choice){
            case 1:printf("\nEnter the element : ");
                    scanf("%d",&item);
                    enqueue(item);
                    break;
            case 2:dequeue();
                    break;
            case 3:peek();
                    break;
            case 4:display();
                    break;
            case 5:exit(0);
                    break;

        }
    }
    return 0;
}