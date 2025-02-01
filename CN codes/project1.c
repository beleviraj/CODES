#include<stdio.h>
int nob=0,nor=0,noc=0,amount=0,count=0;

void bus()
{
	nob++;
	amount+=100;
	count++;
	printf("\nBus Entered");
}

void rickshaw()
{
	nor++;
	amount+=50;
	count++;
	printf("\nRickshaw Entered");
}
void cycle()
{
	noc++;
	amount+=10;
	count++;
	printf("\nCycle Entered");
}

void data()
{
	printf("\nNumber of bus=%d",nob);
	printf("\nNumber of rickshaw=%d",nor);
	printf("\nNumber of cycle=%d",noc);
	printf("\nTotal amount=%d",amount);
	printf("\nTotal number of vehicals=%d",count);
}

void deletedata()
{
	nob=0;
	nor=0;
	noc=0;
	amount=0;
	count=0;
}
int main()
{
	int choice;
	while(choice!=6)
	{
		printf("\n\n1.Entry of Bus\n2.Entry of Rickshaw\n3.Entry of Cycle\n4.Show data\n5.Delete data\n6.Exit\n");
		printf("Enter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				bus();
				break;
				
			case 2:
				rickshaw();
				break;
				
			case 3:
				cycle();
				break;
				
			case 4:
				data();
				break;
				
			case 5:
				deletedata();
				break;
				
			case 6:
				exit(0);
				break;
				

				
		}
	}
	return 0;
}
