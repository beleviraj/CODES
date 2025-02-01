#include<iostream>
#include<string>
using namespace std;
#define SIZE 5

template <class T>
class Stack
{
	public : 
		Stack();
		void push(T k);
		T pop();
		T topElement();
		bool isFull();
		bool isEmpty();
	private :
		int top;
		T st[SIZE];
};

template <class T>
Stack<T>::Stack()
{
	top=-1;
}

template <class T>
void Stack<T>::push(T k)
{
	if(isFull())
		cout<<"\nStack is Full!!";
	cout<<"\nInserted Element : "<<k;
	top++;
	st[top]=k;
}

template <class T>
bool Stack<T>::isEmpty()
{
	if(top==-1)
		return 1;
	else
		return 0;
}

template <class T>
bool Stack<T>::isFull()
{
	if(top==(SIZE-1))
		return 1;
	else
		return 0;
}

template <class T>
T Stack<T>::pop()
{
	T popped_element = st[top];
	top--;
	return popped_element;
}

template <class T>
T Stack<T>::topElement()
{
	T top_element = st[top];
	return top_element;
}

int main()
{
	Stack<int> int_stack;
	Stack<string> str_stack;
	
	cout<<"\n";
	int_stack.push(9);
	cout<<"\n";
	int_stack.push(81);
	cout<<"\n";
	int_stack.push(297);
	
	cout<<"\n";
	str_stack.push("Welcome");
	cout<<"\n";
	str_stack.push("to");
	cout<<"\n";
	str_stack.push("My");
	cout<<"\n";
	str_stack.push("World");
	
	cout<<"\n\nElement removed from stack : "<<int_stack.pop();
	
	cout<<"\n\nElement removed from stack : "<<str_stack.pop();
	
	cout<<"\n\nTop Element : "<<int_stack.topElement();
	
	cout<<"\n\nTop Element : "<<str_stack.topElement();
	
	return 0;
}
