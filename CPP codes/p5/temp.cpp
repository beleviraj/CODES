#include<iostream>
using namespace std;

class stack{
private :
    int size;
    int top;
    int *a;
public:
    stack(){
        top=-1;
    }
    stack(int x){
        top=-1;
        size=x;
        a = new int[size];
    }
    void push(int x){
        if(top==size-1){
            cout<<"\nstack is full";
        }
        else{
            top++;
            a[top]=x;
        }
    }

    int pop(){
        if(top==-1){
            cout<<"\nStack is empty";
            return -1;
        }
        else{
            return a[top--];
        }
    }

    void display(){
        if(top==-1){
            cout<<"\nStack is empty";
        }
        else{
            for(int i=0;i<=top;i++){
                cout<<" "<<a[i];
            }
        }
    }

    int peek(){
        if(top==-1){
            cout<<"\nStack is empty";
            return -1;
        }
        else{
            return a[top];
        }
    }

    void isempty(){
        if(top==-1){
            cout<<"\nStack is empty";
        }
        else{
            cout<<"\nStack is not empty";
        }
    }

};

int main(){
    int n;
    cout<<"\nEnter the size of stack: ";
    cin>>n;
    stack s(n);
    int choice = 0;
    while(choice!=6){
        cout<<"\n1.PUSH\n2.POP\n3.DISPLAY.\n4.PEEK\n5.IS EMPTY?\n6.EXIT\n";
        cout<<"\nEnter your choice: ";
        cin>>choice;
        switch (choice) {
            case 1: {
                int item;
                cout<<"\nEnter element to be pushed: ";
                cin>>item;
                s.push(item);
                break;
            }
            case 2: {
                int popped = s.pop();
                if (popped != -1)
                    cout<<"The popped element is: "<< popped;
                break;
            }
            case 3:
                s.display();
                break;
            case 4: {
                int peeked = s.peek();
                if (peeked != -1)
                    cout<<"The element at top is: "<<peeked;
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
