#include<stdio.h>
int main(){
    int arr[8];

    int fix[8]={0,1,1,1,1,1,1,0};
    printf("Enter the 8 bit data:");
    for(int i=0;i<8;i++)
    {
        scanf("%d",&arr[i]);
    }
    
    int new[24];

    for(int j=0;j<24;j++)
    {
        new[j]=arr[j];
        if(j<8){
            new[j]=fix[j];
        }
        else if(j>=8&&j<16){
            new[j]=arr[j-8];
        }
        else if(j>=16&&j<24){
            new[j]=fix[j-16];
        }
    }
    printf("The byte stuffed data is:");
    for(int i=0;i<24;i++){
        printf("%d ",new[i]);
    }
    return 0;
}