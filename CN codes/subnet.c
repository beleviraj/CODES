#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    char a[15];
    printf("Enter the ip address:\n");
    scanf("%s",a);
    int j=0;
    int b[12]= {0};
    int i=0;
    while(a[i]&&j<12) {
        if(a[i]=='.') {
            i++;
        } else {
            b[j]=atoi(&a[i]);
            j++;
            while(a[i]&&a[i]!='.') {
                i++;
            }
        }
    }
    
    for(int i=0; i<j; i++) {
        printf("\n Octate %d:%d",i+1,b[i]);
    }
    if(b[0]>=0 && b[0]<=127) {
        printf("\nClass A");
        int n=8;
        int find_add=pow(2,32-n);
        printf("\nThe address space=%d\n",find_add);
        int dsubnetmaskA[4]= {255,0,0,0};
        int andopr[4];
        for(int i=0; i<4; i++) {
            andopr[i]=b[i] & dsubnetmaskA[i];
        }
        printf("The first address:");
        for(int i=0; i<4; i++) {
            printf("%d ",andopr[i]);
        }
        printf("\n");
        int newnot[4];
        for(int i=0; i<4; i++) {
            newnot[i]=!dsubnetmaskA[i];
        }
        int mul[4];
        for(i=0; i<4; i++) {
            mul[i]=255*newnot[i];
        }
        int oropr[4];
        for(int i=0; i<4; i++) {
            oropr[i]=b[i] | mul[i];
        }
        printf("The Last address:");
        for(int i=0; i<4; i++) {
            printf("%d ",oropr[i]);
        }
    } else if(b[0]>=128 && b[0]<=191) {
        printf("\nClass B");
        int n=16;
        int find_add=pow(2,32-n);
        printf("\nThe address space=%d\n",find_add);
        int dsubnetmaskB[4]= {255,255,0,0};
        int andopr[4];
        for(int i=0; i<4; i++) {
            andopr[i]=b[i] & dsubnetmaskB[i];
        }
        printf("The first address:");
        for(int i=0; i<4; i++) {
            printf("%d ",andopr[i]);
        }
        printf("\n");
        int newnot[4];
        for(int i=0; i<4; i++) {
            newnot[i]=!dsubnetmaskB[i];
        }
        int mul[4];
        for(i=0; i<4; i++) {
            mul[i]=255*newnot[i];
        }
        int oropr[4];
        for(int i=0; i<4; i++) {
            oropr[i]=b[i] | mul[i];
        }
        printf("The Last address:");
        for(int i=0; i<4; i++) {
            printf("%d ",oropr[i]);
        }
    } else if(b[0]>=192 && b[0]<=223) {
        printf("\nClass C");
        int n=24;
        int find_add=pow(2,32-n);
        printf("\nThe address space=%d\n",find_add);
        int dsubnetmaskC[4]= {255,255,255,0};
        int andopr[4];
        for(int i=0; i<4; i++) {
            andopr[i]=b[i] & dsubnetmaskC[i];
        }
        printf("The first address:");
        for(int i=0; i<4; i++) {
            printf("%d ",andopr[i]);
        }
        printf("\n");
        int newnot[4];
        for(int i=0; i<4; i++) {
            newnot[i]=!dsubnetmaskC[i];
        }
        int mul[4];
        for(i=0; i<4; i++) {
            mul[i]=255*newnot[i];
        }
        int oropr[4];
        for(int i=0; i<4; i++) {
            oropr[i]=b[i] | mul[i];
        }
        printf("The Last address:");
        for(int i=0; i<4; i++) {
            printf("%d ",oropr[i]);
        }
    }
    return 0;
}
