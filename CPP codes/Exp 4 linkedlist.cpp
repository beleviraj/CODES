#include<iostream>
#include<stdlib.h>
using namespace std;
class node
{
	public : int data;
	         node *next;
		 	node()
		{
			data=0;
		  	next=NULL;
		}
};
class linkedlist
{
	private : node *head;
		  node *createnode();
		  void initnode(node *nnode,int data);

	public : linkedlist();
		 ~linkedlist();
		int attachbegin(int data);
		int attachend(int data);
		node *detachbegin();
		node *detachend();
		node *traverce();
};
int main()
{
	int data;
	linkedlist l;
	int ch,value;
	node *value1;
	while(1)
	{
	  cout<<"\n____________________";
	  cout<<"\n1)attach at begin \n2)attach at end \n3)detach at begin \n4)detach at end \n5)display\n6)exit";
	  cout<<"\n______________________";
          cout<<"\nENTER YOUR CHOICE :";
	  cin>>ch;

	 switch(ch)
	{
		case 1:
		cout<<"\nENTER THE DATA :";
		cin>>data;
		value=l.attachbegin(data);
		if(value==0)
		{
			cout<<"\nDATA IS NOT ATTACH.....";
		}
		else
		{
			cout<<"\nATTACHED DATA IS :"<<data;
			cout<<"\nATTACHED BEGIN SUCCESSFULLY...";
		}
		break;
//____________________________________________________________________________
		case 2:
		cout<<"\nENTER THE DATA :";
		cin>>data;
	        value=l.attachend(data);
		if(value==0)
		{
			cout<<"\nDATA IS NOT ATTACHED.....";
		}
		else
		{
			cout<<"\nATTACHED DATA IS :"<<data;
			cout<<"\nATTACHED END SUCCESSFULLY...";
		}
		break;
//______________________________________________________________________________		
		case 3:
		value1=l.detachbegin();
		if(value1==NULL)
		{	
			cout<<"\nLIST IS EMPTY.....";
		}
		else
		{
			cout<<"\nDETTACHED DATA IS :"<<value1->data;
			cout<<"\nDETTACHED DATA BEGIN SUCCESSFULY....";
		}
		break;
//______________________________________________________________________________
		case 4:
		value1=l.detachend();
		if(value1==NULL)
		{
			cout<<"\nLIST IS EMPTY.....";
		}
		else
		{
			cout<<"\nDETTACHED DATA IS :"<<value1->data;
			cout<<"\nDETTACHED DATA END SUCCESSFULY....";
		}
		break;
//______________________________________________________________________________
		case 5:
		value1=l.traverce();
		if(value1==NULL)
		{
			cout<<"\nLIST IS EMPTY.....";
		}
		else
		{
			//valude=head;
			while(value1!=NULL)
			{
			cout<<"\nNODE VALU :"<<value1->data;
			value1=value1->next;
			}

		}
		break;
//____________________________________________________________________________
		case 6:
		exit(0);
		break;

		default:
		cout<<"\n enter the correct choice .";	
	}

	}
	return 0;
}
linkedlist::linkedlist()
{
	head=NULL;
}
int linkedlist::attachbegin(int data)
{
	node *temp;
	temp=createnode();
	initnode(temp,data);

	if(temp==NULL)
	{
		return 0;
	}
	else
	{
		if(head==NULL)
		{
			head=temp;
		}	
		else
		{
			temp->next=head;
			head=temp;	
		}
		return 1;
		
	}
}
int linkedlist::attachend(int data)
{
	node *temp,*current;
	temp=createnode();
	initnode(temp,data);
	if(temp==NULL)
	{
		return 0;
	}
	else
	{
		if(head==NULL)
		{
			head=temp;
		}
		else
		{
			current=head;
			while(current->next!=NULL)
			{
				current=current->next;
			}
			current->next=temp;
		}
		return 1;
	}
	
}
node *linkedlist::detachbegin()
{
	node *temp;
	if(head==NULL)
	{
		return (head);
	}
	else
	{
		temp=head;
		head=temp->next;
		return (temp);
		delete temp;	
		
	}
}
node *linkedlist :: detachend()
{
	node *temp,*previous;
	if(head==NULL)
	{
		return (head);
		//cout<<"\nLIST IS EMPTY";
	}
	else
	{
		/*if(head->next==NULL)
		{
			previous=head;
			head=NULL;
			return previous;
			delete previous;
		//	return 1;
		}
		else
		{
			previous=NULL;
			previous=head;
		while(previous->next!=NULL)
		{
			temp=previous;
			previous=previous->next;
		}
		temp->next=NULL;
		return (previous);
			delete previous;
		//	return 1;
		}
        */	
		previous=head;
        	while(previous->next!=NULL)
        	{
            		temp=previous;
            		previous=previous->next;
       	        }
        temp->next=NULL;
		return (previous);
        delete previous;
    	}
}
node *linkedlist::createnode()
{
	node *temp;
	temp=new node();
	return (temp);
}
void linkedlist:: initnode(node *nnode,int data)
{
	nnode->data=data;
}
node *linkedlist::traverce()
{
	node *temp;
	if(head==NULL)
	{
		return (head);
		//cout<<"\nLIST IS EMPTY.";
	}
	else
	{
		temp=head;
		while(temp!=NULL)
		{
			//cout<<"\nNODE VALU :"<<temp->data;
			return (temp);
			temp=temp->next;
			
		}
		
	}
}
linkedlist::~linkedlist()
{
	node *temp,*t;
	temp=head;
	while(temp!=NULL)
	{
		t=temp;
		temp=temp->next;
		delete t;
	}
}

