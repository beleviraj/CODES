#include <stdio.h>


void stop();

int top = -1;
int n = 5;
int stack[5];

void push() {
  int x;
  printf("Enter the data to insert:");
  scanf("%d", &x);
  if (top == n - 1) {
    printf("\nStack is full!\n");
    return;
  }
  top++;
  stack[top] = x;
  printf("\nStack is:\n");
  for (int i = 0; i <= top; i++) {
    printf(" %d ", stack[i]);
  }
  stop();
}

void pop() {
  int item;
  if (top == -1) {
    printf("\nStack is empty!\n");
    return;
  }
  item = stack[top];
  top--;
  printf("\nPopped element is: %d\n", item);
  printf("\nStack is:\n");
  for (int i = 0; i <= top; i++) {
    printf(" %d ", stack[i]);
  }
  stop();
}

void peek() {
  if (top == -1) {
    printf("\nStack is empty!\n");
    return;
  }
  printf("\nThe topmost element is: %d\n", stack[top]);
  stop();
}

void display() {
  if (top == -1) {
    printf("\nStack is empty!\n");
    return;
  }
  printf("Stack is:\n");
  for(int i = 0; i <= top; i++) {
    printf(" %d ", stack[i]);
  }
  printf("\n");
  stop();
}

void stop() {
  int choice;
  do {
    printf("\nSelect the operation:\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Peek\n");
    printf("4. Display\n");
    printf("Enter your choice:\n");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        push();
        break;
      case 2:
        pop();
        break;
      case 3:
        peek();
        break;
      case 4:
        display();
        break;
      default:
        printf("Invalid choice!\n");
    }
  } while (choice != 5);
}

int main() {
  stop();
  return 0;
}
