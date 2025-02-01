#include<stdio.h>
#include<math.h>
int main(){
    int c[11];
    printf("Enter the bits:\n");
    for(int i=0;i<11;i++){
        scanf("%d",&c[i]);
    }
    printf("The bits are:\n");
    for(int i=0;i<11;i++){
        printf("%d ",c[i]);
    }

    c[0]=c[0]^c[2]^c[4]^c[6]^c[8]^c[10];
	c[1]=c[1]^c[2]^c[5]^c[6]^c[9]^c[10];
	c[3]=c[3]^c[4]^c[5]^c[6];
	c[7]=c[7]^c[8]^c[9]^c[10];

     int a[4];
    int k=0;
    for(int i=0;i<11;i++){
        if(i==0||i==1||i==3||i==7)
		{
			a[k]=c[i];
            k++;
		}
    }
     printf("\nThe reductant bits are :\n");
    for(int i=0;i<4;i++){
        printf("%d ",a[i]);
    }

    printf("\nThe bits after finding reductant bits are:\n");
    for(int i=0;i<11;i++)
	{
		printf("%d ",c[i]);
	}

   
    int dec=0;
    for(int i=0;i<4;i++)
	{
		dec+=(pow(2,i)*a[i]);
	}
	printf("\n\nThe wrong bit is at:%d",dec-1);
	
    return 0;
}