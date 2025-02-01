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
    int swap=0;
    for(int pass=0;pass<n;pass++){
        for(int j=0;j<n-1-pass;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;
                    swap=1;
            }
            
        }
        if(swap!=1){
            break;
        }
    }
    printf("sorted array is:\n");
    for(int k=0;k<n;k++){
        printf("%d ",arr[k]);
    }
    return 0;
}