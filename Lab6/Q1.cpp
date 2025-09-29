#include <iostream>
#include <string>

using namespace std;

class Stack{
	public:
		int *arr;
		int top;
		int capacity;
		
		Stack(int c){
			capacity = c;
			arr = new int[capacity];
			top = -1;
		}
		
		~Stack(){
			delete[] arr;
		}
		
		void push(int x){
			if (top < capacity){
				top++;
				arr[top] = x;
				cout << "Pushed the number!" << endl;
			}
			else{
				cout << "Stack is full" << endl;
			}
		}
		
		void pop(){
			if (top == -1){
				cout << "The stack is currently empty" << endl;
			}
			else{
				top = top - 1;
				cout << "Popped element from the stack: " << arr[top] << endl;
			}
		}
		
		void peek(){
			if (top == -1){
				cout << "No elements to peek" << endl;
			}
			else{
				cout << "Top element is: " << arr[top] << endl;
			}
		}
		
		void displayStack(){
			if (top == -1){
				cout << "Stack is empty" << endl;
				return;
			}
			for (int i = 0; i < top; i++){
				cout << arr[i];
				if (i != top - 1){
					cout << ", ";
				}
				else{
					cout << endl;
				}
			}
		}
};

int main(){
	Stack s = Stack(7);
	s.pop();
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.peek();
	s.push(5);
	s.push(6);
	s.push(7);
	s.push(8);
	s.displayStack();
	s.pop();
}
