#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head;

void display();
void create() {
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    int data;
    printf("\nEnter the data: ");
    scanf("%d", &data);
    newnode->data = data;
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
        newnode->next = head;
    } else {
        temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = head;
    }

    display();
}

void display() {
    struct node *temp;
    if (head == NULL) {
        printf("\nList is Empty");
    } else {
        temp = head;
        printf("\nThe list is:");
        do {
            printf(" %d ", temp->data);
            temp = temp->next;
        } while (temp != head);
    }
}

int main() {
    int choice;
    while (choice != 2) {
        printf("\n1. Create node\n2. Exit\n");
        printf("\nEnter the operation: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                create();
                break;
            case 2:
                exit(0);
                break;
            default:
                printf("\nInvalid choice\n");
        }
    }
    return 0;
}
