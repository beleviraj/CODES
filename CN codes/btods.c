#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int decimal(int b){
    int rem,sum=0,i=0;
    while(b!=0){
        rem=b%10;
        sum+=rem*pow(2,i);
        b=b/10;
        i++;
    }
    return sum;
}
int main(){
    char a[36];
    printf("Enter the IP in binary:");
    scanf("%s",a);

   long int b[4];
    int i=0,count=0;
    while(a[i]!='\0' && count<4){
        if(a[i]=='.'){
            i++;
        }
        else{
            b[count]=atoi(&a[i]);
            count++;
            while(a[i]!='\0' && a[i]!='.'){
                i++;
            }
        }
    }
    for(int i=0;i<count;i++){
        printf("%ld ",b[i]);
    }
    int c[4];
    for(int i=0;i<4;i++){
        c[i]=(decimal(b[i]));
    }
    printf("The IP address is:\n");
    for(int i=0;i<4;i++){
        printf("%d.",c[i]);
    }
    
    return 0;

}