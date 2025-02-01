import java.util.Scanner;

interface Stack {
    void push();
    void pop();
    void display();
    void peak();
    void overflow();
    void underflow();
}

class IntStack implements Stack {
    private int size;
    private int top;
    private int[] s;

    public IntStack(int size) {
        this.size = size;
        this.top = -1;
        s = new int[size];
    }

    public void push() {
        if (top == size - 1) {
            overflow();
        } else {
            System.out.println("Enter the Element:");
            Scanner sc = new Scanner(System.in);
            int value = sc.nextInt();
            top++;
            s[top] = value;
        }
    }

    public void pop() {
        if (top == -1) {
            underflow();
        } else {
            System.out.println("The popped Element is:" + s[top]);
            top--;
        }
    }

    public void peak() {
        if (top == -1) {
            underflow();
        } else {
            System.out.println("The Top Element is:" + s[top]);
        }
    }

    public void display() {
        if (top == -1) {
            underflow();
        } else {
            System.out.print("Stack elements are:");
            for (int i = 0; i <= top; i++) {
                System.out.print(s[i] + " ");
            }
            System.out.println();
        }
    }

    public void overflow() {
        System.out.println("The Stack is Full!!");
    }

    public void underflow() {
        System.out.println("The Stack is Empty!!");
    }
}

class x {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        IntStack stack = new IntStack(5);
        boolean exit = false;
        while (!exit) {
            System.out.println("\nSelect an operation:");
            System.out.println("1.Push");
            System.out.println("2.Pop");
            System.out.println("3.Peak");
            System.out.println("4.Display");
            System.out.println("5.Exit");

            int choice = sc.nextInt();
            switch (choice) {
                case 1:
                    stack.push();
                    break;
                case 2:
                    stack.pop();
                    break;
                case 3:
                    stack.peak();
                    break;
                case 4:
                    stack.display();
                    break;
                case 5:
                    exit = true;
                    break;
                default:
                    System.out.println("Invalid choice. Please try again.");
            }
        }
        sc.close();
    }
}
