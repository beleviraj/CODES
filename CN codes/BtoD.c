#include<stdio.h>
#include<math.h>
int main(){
    long int b=11111111;
    int rem,sum=0,i=0;
    while(b!=0){
        rem=b%10;
        sum+=rem*pow(2,i);
        b=b/10;
        i++;
    }
    printf("Decimal is:%d",sum);

    return 0;
}