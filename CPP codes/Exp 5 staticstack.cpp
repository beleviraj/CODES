#include<iostream>
#include<stdlib.h>
using namespace std;
class stack
{
	private :int *stack1;
		 int top;
		 int stack_size;
		 int data;
		int size;
	
	public: 
		stack(int size);
		~stack();
		int push(int data);
		int pop();
		
};

int main()
{
	//int *stack;
	int top;
	int stack_size;
//	int *stack;
	int ch;
	int data;
	int status;

	stack s(5);

	while(1)
	{
		cout<<"1)push\n2)pop\n3)exit\n";
		cout<<"\nENTER YOUR CHOICE :";
		cin>>ch;

		switch(ch)
		{
			case 1:
			cout<<"\nENTER THE DATA TO BE PUSHED IN STACK :";
			cin>>data;
			status=s.push(data);
			if(status==1)
			{
				cout<<"\nDATA PUSHED IS_____:"<<data;
				cout<<"\nDATA PUSH SUCCESSFULLY____\n";
			}
			else
			{
				cout<<"\nDATA COULDNOT PUSHED_______.\n";
			}
			break;
			
			case 2:
			status=s.pop();
			if(status)
			{
				cout<<"\nDATA POPED IS ______:"<<status;
				cout<<"\nDATA POPED SUCCESSFULLY______.\n";	
			}
			else
			{
				cout<<"\nDATA COULDNOT POPED_______\n";
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
stack::stack(int size)
{
	stack1=((int*)malloc(size*sizeof(int)));
	top=0;
	stack_size=size;
}
stack::~stack()
{
	free(stack1);
}
int stack::push(int data)
{
	if(top<stack_size)
	{
		
		stack1[top]=data;
		top++;
		return 1;
	}
	else
	{
	  return 0;
	}
}
int stack::pop()
{
	int retdata;
	if(top!=0)
	{
		top--;
		retdata=stack1[top];
		return(retdata);
	}
	else
	{
		return 0;
	}

}

