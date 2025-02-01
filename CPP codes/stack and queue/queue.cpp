#include<iostream>
using namespace std;

class queue{
private :
    int size;
    int front;
    int rear;
    int *a;
public:
    queue(){
        front=-1;
        rear=-1;
    }
    queue(int x){
        front=-1;
        rear=-1;
        size=x;
        a = new int[size];
    }

    void enqueue(int x){
        if(rear==size-1){
            cout<<"\nQUEUE IS EMPTY!";
        }
        else if(front==-1 && rear==-1){
            front=rear=0;
            a[rear]=x;
        }
        else{
            rear++;
            a[rear]=x;
        }
    }
    
    int dequeue(){
        int x;
        if(front==-1 && rear==-1){
            cout<<"\nQUEUE IS EMPTY!";
        }
        else if(front==rear){
            x=a[front]; 
            front=rear=-1;
            return x;
        }
        else{
            x= a[front];
            front++;
            return x;
        }
    }

    int peek(){
    if(front==-1&&rear==-1){
        cout<<"\nQUEUE IS EMPTY!";
        return -1;
        }
    else{
        
        return a[front];
        }
    }

    void display(){
        if(front==-1&&rear==-1){
            cout<<"\nQUEUE IS EMPTY!";
        }
        else{
            cout<<"\nQUEUE IS: ";
        for(int i=front;i<=rear;i++){
            cout<<" "<<a[i];
        }
        }
    }

    void isempty(){
        if(front==-1 && rear==-1){
            cout<<"\nQUEUE IS EMPTY!";
        }
        else{
            cout<<"\nQUEUE IS NOT EMPTY!";
        }
    }
    
};

int main(){
    int n;
    cout<<"\nEnter the size of queue: ";
    cin>>n;
    queue s(n);
    int choice = 0;
    while(choice!=6){
        cout<<"\n1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY.\n4.PEEK\n5.IS EMPTY?\n6.EXIT\n";
        cout<<"\nEnter your choice: ";
        cin>>choice;
        switch (choice) {
            case 1: {
                int item;
                cout<<"\nEnter element to be ENQUEUED: ";
                cin>>item;
                s.enqueue(item);
                break;
            }
            case 2: {
                cout<<"The DEQUEUED element is: "<< s.dequeue();
                break;
            }
            case 3:
                s.display();
                break;
            case 4: {
                cout<<"The element at top is: "<<s.peek();
                break;
            }
            case 5:
                s.isempty();
                break;
            default:
                cout << "Invalid choice!\n";
        }
    }
    return 0;
}
