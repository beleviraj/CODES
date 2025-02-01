#include<stdio.h>
#include<math.h>
// void decimal(int x[]){
//     int sum=0,j=7;
//     int ssub[4],p=0;
//     for(int i=0;i<32;i++)
// 	{
// 		sum+=(pow(2,j)*x[i]);
//         j--;
//         if(j<0){
//             ssub[p]=sum;
//             p++;
//             sum=0;
//         }
// 	}
//     printf("\nThe subnet mask is:\n");
//     for(int i=0;i<4;i++){
//         printf("%d ",ssub[i]);
//     }
	
// }
void bsub(int sub){
    int subnet[32];
    for(int i=0;i<32;i++){
    if(i<sub){
        subnet[i]=1;
    }
    else{
    subnet[i]=0;
    }
    for(int i=0;i<32;i++){
        printf("%d",subnet[i]);
    }
    BintoDec(subnet);
} 
}

void BintoDec (int *arr)
{
  int octet[4], sum = 0, p = 7, i = 0;

  for (int j = 0; j < 32; j++)
    {
      sum = sum + pow (2, p) * arr[j];
      p--;
      if (p < 0)
	{
	  octet[i] = sum;
	  p = 7;
	  i++;
	  sum = 0;
	}
    }
  for (int i = 0; i < 4; i++)
    {
      printf ("%d", octet[i]);
      if (i < 3)
	printf (".");
    }

}
int main()
{
    int n;
    printf("Enter the subnetworks:\n");
    scanf("%d",&n);
    int sub;
    sub=16+log2(n);
    printf("%d",sub);
    printf("The binary subnet mask is:\n");
    bsub(sub);
    
return 0;
}
