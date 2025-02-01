#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head;

void display(){
    struct node *temp;
    if(head==NULL){
        printf("\nThe lis is empty");
    }
    else{
        temp=head;
        printf("\nThe list is: ");
        while(temp!=0){
            printf(" %d ",temp->data);
            temp=temp->next;
        }
    }
}
void insertbegin(){
    struct node *newnode;
    int item;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data: ");
    scanf("%d",&item);
    newnode->data=item;
    if(head==NULL)
    {
        head=newnode;
        newnode->next=NULL;
    }
else{
        newnode->next=head;
        head=newnode;
    }
    display();

}

void insertend(){
    struct node *newnode,*temp;
    int item;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data: ");
    scanf("%d",&item);
    newnode->data=item;
    if(head==NULL){
        head=newnode;
        newnode->next=NULL;
    }
    else{
        temp=head;
        while(temp->next!=0){
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->next=NULL;
    }
    display();
    }

void midinsert(){
     struct node *newnode,*temp;
     int item,loc,i=1;
     newnode=(struct node*)malloc(sizeof(struct node));
     if(head==NULL){
        head=newnode;
        newnode->next=NULL;
     }
     else{
         printf("\nEnter the location: ");
         scanf("%d",&loc);
         if(loc<-1){
            printf("\nInvalid location");
         }
         else{
            printf("\nEnter the data: ");
            scanf("%d",&item);
            newnode->data=item;
            temp=head;
            while(i<loc-1){
                temp=temp->next;
                i++;
            }
            newnode->next=temp->next;
            temp->next=newnode;
         }
     }
     display();
}

void delbeg(){
    struct node *temp;
    if(head==NULL){
        printf("\nList is Empty");
    }
    else{
        temp=head;
        temp->next=head;
        free(temp);
    }
    display();
}

void delend(){
    struct node *temp,*prevnode;
    temp=head;
    while(temp->next!=0){
        prevnode=temp;
        temp=temp->next;
    }
    if(temp==head){
        head=NULL;
    }
    else{
        prevnode->next=NULL;
    }
    free(temp);
    display();
}

void randomdel(){
    struct node *temp,*curnode;
    int loc,i=1;
    printf("\nEnter the loccation: ");
    scanf("%d",&loc);
    if(loc<0){
        printf("\nInvalid Position");
    }
    else{temp=head;
        while(i<loc-1){
            temp=temp->next;
            i++;
        }
        curnode=temp->next;
        temp->next=curnode->next;
        free(curnode);

    }
    display();
}

int main(){
    int choice;
    while(choice!=8){
        printf("\n1.Insert at beginning\n2.Insert at end\n3.Insert at location\n4.Display\n5.Delete Beginning\n6.Delete End\n7.Delete at\n8.Exit\n");
        printf("\nEnter the operation: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: insertbegin();
                break;
            case 2: insertend();
                break;
            case 3: midinsert();
                break;
            case 4: display();
                break;
            case 5: delbeg();
                break;
            case 6: delend();
                break;
            case 7: randomdel();
                break;
            case 8:exit(0);
                break;
            default: printf("Invalid choice!!");
                break;
        }
    }
    return 0;
}