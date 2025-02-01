#include<stdio.h>
#include<string.h>
int main(){
    char str[100];
    puts("Enter the string: ");
    scanf("%s",str);
    int i=0,count=0;
    while(str[i]!='\0'){
        count+=1;
        i++;
    }
    puts("output is: ");
    printf("%d ",count+1);
    puts(str);
}