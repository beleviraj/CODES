#include<iostream>
using namespace std;

class node{
public: 
    int data;
    node* next;

    node(){
        data = 0;
        next = nullptr;
    }

    node(int data){
        this->data = data;
        next = nullptr;
    }
};

class linkedlist{
    node* head;
public:
    linkedlist(){
        head = nullptr;
    }
     
    void print(){
        node* temp = head;
        if(head == nullptr){
            cout << "\nlist is empty!!";
            return;
        }
        while(temp != nullptr){
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    void insertatend(int data){
        node* newnode = new node(data);
        if(head == nullptr){
            head = newnode;
            return;
        }
        node* temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = newnode;
    }

    void deleteNode(int index) {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        node* temp1 = head;
        node* temp2 = nullptr;
        int listLength = 0;

        while (temp1 != nullptr) {
            temp1 = temp1->next;
            listLength++;
        }

        if (index <= 0 || index > listLength) {
            cout << "Index out of range." << endl;
            return;
        }

        temp1 = head;
        if (index == 1) {
            head = head->next;
            delete temp1;
            return;
        }

        for (int i = 1; i < index; i++) {
            temp2 = temp1;
            temp1 = temp1->next;
        }

        temp2->next = temp1->next;
        delete temp1;
    }
};

int main(){
    linkedlist list;
    list.insertatend(1);
    list.insertatend(2);
    list.insertatend(3);
    list.insertatend(4);
    

    cout << "Elements of the list are: ";
    list.print();
    cout << endl;

    list.deleteNode(2);

    cout << "Elements of the list after deletion are: ";
    list.print();
    cout << endl;

    return 0;
}
