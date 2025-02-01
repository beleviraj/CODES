#include <stdio.h>

int xor(int num1, int num2) {
    return num1 ^ num2;
}

int main() {
    int num1;
    int num2;
    printf("Enter the first number:");
    scanf("%d",&num1);
    printf("\nEnter the second number:");
    scanf("%d",&num2);
    int result = xor(num1,num2);
    printf("Result of XORing :%d", result);
    return 0;
}

