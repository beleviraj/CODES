#include<iostream>
#include<stdlib.h>
using namespace std;
class queue
{
	private :  int *queue1;
				int front;
				int rear;
				int queue_size;
				int data;
				
	public:
		 queue(int size);
		~queue();
		 int enqueue(int data);
		 int dequeue();
};
int main()
{
    int front;
	int rear;
	int queue_size;
	int data;
	int ch;
	int status;
	
	queue q(5);
	while(1)
	{
		cout<<"1)ENQUEUE\n2)DEQUEUE\n3)EXIT\n";
		cout<<"\nENTER YOUR CHOICE :";
		cin>>ch;

		switch(ch)
		{
			case 1:
			cout<<"\nENTER THE DATA TO BE ENQUEUE IN QUEUE :";
			cin>>data;
			status =q.enqueue(data);
			if(status==1)
			{
			   cout<<"\nDATA ENQUEUE IS ______:"<<data;
			   cout<<"\nDATA ENQUEUE SUCCESSFULLY______.\n";
			}
			else
			{
				cout<<"\nDATA COULDNOT ENQUEUE_______.\n";
			}
			break;
			
			case 2:
			status=q.dequeue();
			if(status)
			{
				cout<<"\nDATA DEQUEUED IS ______:"<<status;
				cout<<"\nDATA DEQUEUE SUCCESSFULLY______.\n";	
				
			}
			else
			{
				cout<<"\nQUEUE IS EMPTY\nDATA COULDNOT DEQUEUE_______\n";
			}
			break;

			case 3:
			exit(0);
			break;

			default:
			cout<<"\nENETR THE CORRECT CHOICE :";
			
		}
	}
	return 0;	
}
queue::queue(int size)
{
	queue1=((int*)malloc(size*sizeof(int)));
	front=-1;
	rear=-1;
	queue_size=size;
}
queue::~queue()
{
	free(queue1);
}
int queue::enqueue(int data)
{
	if(rear==queue_size-1)
	{
		return 0;
	}
	else
	{
		front=0;
		rear++;
		queue1[rear]=data;
		return 1;	
	}
}
int queue::dequeue()
{
	int retdata;
	if(front>rear)
	{
		return 0;
	}
	else
	{
		retdata=queue1[front];
		front++;
		return(retdata);
	}
}
