#include <iostream>
using namespace std;

template <typename T>
class Stack {
private:
    int size;
    int top;
    T* a;
public:
    Stack() {
        top = -1;
    }
    Stack(int x) {
        top = -1;
        size = x;
        a = new T[size];
    }
    void push(T x) {
        if (top == size - 1) {
            cout << "\nStack is full";
        } else {
            top++;
            a[top] = x;
        }
    }

    T pop() {
        if (top == -1) {
            cout << "\nStack is empty";
            return T(); 
        } else {
            return a[top--];
        }
    }

    void display() {
        if (top == -1) {
            cout << "\nStack is empty";
        } else {
            for (int i = 0; i <= top; i++) {
                cout << " " << a[i];
            }
            cout << endl;
        }
    }

    T peek() {
        if (top == -1) {
            cout << "\nStack is empty";
            return T(); 
        } else {
            return a[top];
        }
    }

    void isempty() {
        if (top == -1) {
            cout << "\nStack is empty";
        } else {
            cout << "\nStack is not empty";
        }
    }
};

template <typename T>
void stackOperations(Stack<T>& s) {
    int choice = 0;
    while (choice != 6) {
        cout << "\n1. PUSH\n2. POP\n3. DISPLAY\n4. PEEK\n5. IS EMPTY?\n6. EXIT\n";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                T item;
                cout << "\nEnter element to be pushed: ";
                cin >> item;
                s.push(item);
                break;
            }
            case 2: {
                cout << "The popped element is: " << s.pop() << endl;
                break;
            }
            case 3:
                s.display();
                break;
            case 4: {
                cout << "The element at top is: " << s.peek() << endl;
                break;
            }
            case 5:
                s.isempty();
                break;
            case 6:return;
                break;
            default:
                cout << "Invalid choice!\n";
        }
    }
}

int main() {
    int n;
    cout << "\nEnter the size of stack: ";
    cin >> n;

    int stackType;
    cout << "\nSelect stack type:\n1. Int\n2. Float\n3. Char\n";
    cout << "Enter your choice: ";
    cin >> stackType;

    switch (stackType) {
        case 1: {
            Stack<int> intStack(n);
            stackOperations(intStack);
            break;
        }
        case 2: {
            Stack<float> floatStack(n);
            stackOperations(floatStack);
            break;
        }
        case 3: {
            Stack<char> charStack(n);
            stackOperations(charStack);
            break;
        }
        default:
            cout << "Invalid stack type!\n";
    }

    return 0;
}
