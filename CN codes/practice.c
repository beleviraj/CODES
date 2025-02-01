#include<stdio.h>
#include<string.h>

int main(){
	char str[100];
	puts("Enter a string : ");
	scanf("%s",str);
	int i=0;
	int count = 0;
	while(str[i]!='\0')
	{
		count+=1;
		i++;
	}
	printf("Output is : ");
	printf("%d ",count+1);
	puts(str);
}