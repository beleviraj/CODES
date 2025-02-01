#include<stdio.h>

int main(){
    int n;
    printf("Enter the size of array:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of array:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int target;
    printf("Enter the target element:");
    scanf("%d",&target);
    int flag=0,loc=0;
    for(int i=0;i<n;i++){
        if(target==arr[i]){
            flag=1;
            loc=i+1;

        }
    }
    if(flag){
        printf("element is at loc %d",loc);
    }
    else
    printf("Element not found");

    return 0;
}
