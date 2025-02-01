#include<stdio.h>
#include<math.h>
void firstadd(int arr[],int a[]){
    int andopr[4];
    for(int i=0;i<4;i++){
        andopr[i]=arr[i] & a[i];        
    } 
    printf("\nTHE FIRST ADDRESS IS : ");
    for(int i=0;i<4;i++){
    printf("%d ",andopr[i]);
    }
}
void Space(int n){
    int space=pow(2,32-n);
    printf("\nTHE ADDRESS SPACE IS : %d",space);
}
void lastadd(int c[],int arr[]){
    int not[4];
    for(int i=0;i<4;i++){
        not[i]=!c[i];
        not[i]=255*not[i];
    } 
    int oropr[4];
    for(int i=0;i<4;i++){
        oropr[i]=arr[i] | not[i];
    }
    printf("\nTHE LAST ADDRESS IS :");
    for(int i=0;i<4;i++){
    printf("%d ",oropr[i]);
    } 
}
int main(){
    int b[4];
    int subnetA[4]={255,0,0,0};
    int subnetB[4]={255,255,0,0};
    int subnetC[4]={255,255,255,0};

    printf("Enter the IP address:");
    for(int i=0;i<4;i++){
        scanf("%d",&b[i]);
    }
    if (b[0] >= 0 && b[0] <= 127) {
        printf("\nCLASS A");
        int n=8;
        Space(n);
        firstadd(b,subnetA);
        lastadd(subnetA,b);
           
        } else if (b[0] >= 128 && b[0] <= 191) {
        printf("\nCLASS B");
        int n=16;
        Space(n);
        firstadd(b,subnetB);
        lastadd(subnetB,b);
        } else if (b[0] >= 192 && b[0] <= 223) {
        printf("\nCLASS C");
        int n=24;
        Space(n);
        firstadd(b,subnetC);
        lastadd(subnetC,b);
        } else {
            printf("Invalid IP address class.\n");
        }
    return 0;
}
