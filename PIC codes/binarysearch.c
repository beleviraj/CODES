#include<stdio.h>
#include<math.h>


int main(){
    int n;
    printf("Enter the size of array:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the sorted array:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int target;
    printf("Enter the target element:");
    scanf("%d",&target);
    int low=0;
    int high=n-1;
    int i=0;
    int x=pow(2,i);
    int y;
    while(low<=high){
        int mid=(low+high)/2;
        if(target==arr[mid]){
            printf("Element found at loc : %d",mid);
            return 0;
        }
        else if(target<arr[mid]){
            high=mid-1;
        }
        else if(target>arr[mid]){
            low=mid+1;
        }
        else{
            printf("Element not found!\n");
        }
    }
    
    
return 0;
}
