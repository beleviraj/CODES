#include<stdio.h>
#include<stdlib.h>

int n=5;
int queue[5];
int front=-1,rear=-1;

void dequeue();
void display();

void enqueue(int x)
{
    if(front==-1 && rear==-1){
        front=rear=0;
        queue[rear]=x;
    }
    else if(((rear+1)%n)==front){
        printf("\nQueue is full");
    }
    else{
        rear=((rear+1)%n);
        queue[rear]=x;
    }
display();
}

void dequeue()
{
    if(front==-1  && rear==-1){
        printf("\nQueue is empty");
    }
    else if(front==rear){
        printf("The dequeued element is=%d",queue[front]);
        front=rear=-1;
    }
    else{
        printf("The dequeued element is=%d",queue[front]);
        front=((front+1)%n);
    }
    display();
}
        
void display(){ 
    int i=front;
    if(front==-1&&rear==-1){
        printf("\nQueue is empty");
    }
    else{
        printf("\nThe queue is: ");
        while(i!=rear)
        {
            printf(" %d ",queue[i]);
            i=((i+1)%n);
        }
        printf(" %d ",queue[rear]);
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