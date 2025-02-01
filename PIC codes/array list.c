#include<stdio.h>
#define MAX_SIZE 100

void delete_ele(int arr[],int *size,int position)
{
	if(*size=0)
	{
		printf("The List is EMPTY.");
	}
	else
	{
		int temp;
	//	arr[position]=temp;
		(*size)--;
		return (*size);
	}
}

void display(int arr[],int size)
{

int i;
for(i=0;i<size;i++)
{
	printf("%d ",arr[i]);
}
printf("\n");
}
int insert_ele(int arr[],int *size,int position,int ele)
{
	if(*size>=MAX_SIZE)
	{
		printf("List is FULL.");
	}
	else 
	{
		arr[position]=ele;
		(*size)++;
	}
	
}
int main()
{
	int arr[MAX_SIZE];
	int size=0;
	insert_ele(arr,&size,0,4);
	insert_ele(arr,&size,1,5);
	insert_ele(arr,&size,2,6);
	insert_ele(arr,&size,3,7);
	
	display(arr,size);
	
	delete_ele(arr,&size,3);
	display(arr,size);
}
