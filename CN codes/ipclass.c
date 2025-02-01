#include<stdio.h>
#include<stdlib.h>
int main(){
char a[15];
printf("Enter the ip address:\n");
scanf("%s",a);
int j=0;
	 int b[12]={0};
	 int i=0;
	while(a[i]&&j<12)
	{
		if(a[i]=='.')
		{
			i++;
		}
		else
		{
			b[j]=atoi(&a[i]);
			j++;
			while(a[i]&&a[i]!='.')
			{
			i++;
		   }
		}
	}
	for(i=0;i<j;i++)
	{
		printf("\n Octate %d>%d",i+1,b[i]);
	}




    return 0;
}