#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head, *tail;

void display() {
    struct node *temp;

    if (head == NULL) {
        printf("\nList is Empty\n");
    } else {
        temp = head;
        printf("\nThe List is: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void create() {
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("\nEnter the data: ");
    scanf("%d", &(newnode->data));

    newnode->next = NULL;
    newnode->prev = NULL;

    if (head == NULL) {
        head = tail = newnode;
    } else {
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }

    display();
}

void insertbegin() {
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("\nEnter the data: ");
    scanf("%d", &(newnode->data));

    newnode->next = head;
    newnode->prev = NULL;

    if (head != NULL) {
        head->prev = newnode;
    }

    head = newnode;

    if (tail == NULL) {
        tail = newnode;
    }

    display();
}

void insertend() {
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("\nEnter the data: ");
    scanf("%d", &(newnode->data));

    newnode->next = NULL;
    newnode->prev = tail;

    if (tail != NULL) {
        tail->next = newnode;
    }

    tail = newnode;

    if (head == NULL) {
        head = newnode;
    }

    display();
}

void insertmid() {
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("\nEnter the data: ");
    scanf("%d", &(newnode->data));

    if (head == NULL) {
        head = tail = newnode;
        newnode->next = NULL;
        newnode->prev = NULL;
    } else {
        int pos, i = 1;
        printf("\nEnter the position: ");
        scanf("%d", &pos);

        if (pos <= 0) {
            printf("\nInvalid position\n");
            return;
        }
        temp = head;
       while(i<pos-1){
        temp=temp->next;
        i++;
       }
       newnode->prev=temp;
       newnode->next=temp->next;
       temp->next=newnode;
       newnode->next->prev=newnode;
    }

    display();
}

int main() {
    int choice;

    
    while (choice != 8) {
        printf("\n1. Insert at beginning\n2. Insert at End\n3. Insert after data\n4. Display list\n5. Exit\n");
        printf("\nEnter operation to perform: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertbegin();
                break;
            case 2:
                insertend();
                break;
            case 3:
                insertmid();
                break;
            case 4:
                display();
                break;
            case 8:
                exit(0);
                break;
            default:
                printf("\nInvalid choice\n");
        }
    }

    return 0;
}
