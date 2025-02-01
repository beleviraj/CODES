#include<stdio.h>
#include<math.h>
int main(){
    int a[7];
    printf("\nEnter the 7 bit bit dataword: ");
    for(int i=0;i<7;i++){
        scanf("%d",&a[i]);
    }
    printf("\nThe Dataword is: ");
      for(int i=0;i<7;i++){
        printf("%d",a[i]);
    }
    int b[11];
    int j=0;
    for(int i=0;i<11;i++){
        if(i==0||i==1||i==3||i==7){
            b[i]=0;
        }
        else{
            b[i]=a[j];
            j++;
        }
    }
    printf("\nThe Codeword with reductant bits as 0 is: ");
    for(int i=0;i<11;i++){
        printf("%d",b[i]);
    }

    b[0]=b[0]^b[2]^b[4]^b[6]^b[8]^b[10];
    b[1]=b[1]^b[2]^b[5]^b[6]^b[9]^b[10];
    b[3]=b[3]^b[4]^b[5]^b[6];
    b[7]=b[7]^b[8]^b[9]^b[10];

    printf("\nThe Codeword with reductant bits is: ");
    for(int i=0;i<11;i++){
        printf("%d",b[i]);
    }
    int c[4]={b[0],b[1],b[3],b[7]};
    printf("\nThe Reductant bits are: ");
    for(int i=0;i<4;i++){
        printf("%d",c[i]);
    }
    int dec=0;
    for(int i=0;i<4;i++){
        dec+=(pow(2,i)*c[i]);
    }

    if(dec>11){
        printf("\nThere is no ERROR");
    }
    else{
    printf("\nThe error is at : %d position",dec);
    }
    
    for(int i=0;i<11;i++){
        if(i==dec){
            if(b[i]==1){
                b[i]=0;
            }
            else{
                b[i]=1;
            }
        }
    }
    printf("\nThe correct code word is: ");
     for(int i=0;i<11;i++){
        printf("%d",b[i]);
    }
    return 0;
}