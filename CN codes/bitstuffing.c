#include<stdio.h>
int main()
{
	int n,i;
	printf("Enter the no of elements in array=");
	scanf("%d",&n);
	int arr[n];
	printf("Enter the elements in array=\n");
	for( i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);		
	}
	int newarr[n*2];
	int j=0,count=0;
	for( i=0;i<n;i++)
	{
		newarr[j]=arr[i];
		if(arr[i]==1)
		{
			count++;
		}
		else{
			count=0;
		}
		if(count==5)
		{
			j++;
			newarr[j]=0;
			count=0;
		}
		j++;
    }

	for(i=0;i<j;i++)
	{
		printf("[%d]",newarr[i]);
	}
}
