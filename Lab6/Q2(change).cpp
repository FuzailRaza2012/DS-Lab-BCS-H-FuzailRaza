#include <iostream>
#include <string>

using namespace std;

class Node{
	public:
		int data;
		Node *next;
		
		Node(int d){
			data = d;
			next = NULL;
		}
};

class Singly{
	public:
		Node *head;
		int cap;
		int size;
		
		Singly(int c){
			head = NULL;
			head->next = NULL;
			cap = c;
			size = 0;
		}
		
		void push(Node *n){
			if (head == NULL){
				head = n;
				head->next = NULL;
				size += 1;
			}
			else if (size < cap){
				int curr = 0;
				Node *temp = head;
				while (curr != size){
					temp = temp->next;
					curr += 1;
				}
				temp->next = n;
				n->next = NULL;
				size += 1;
			}
			else{
				cout << "full!" << endl;
			}
		}
		
		void pop(){
			if (size == 0){
				cout << "nothing to pop!" << endl;
			}
			else{
				int curr = 0;
				Node *temp = head;
				while (curr != size - 1){
					temp = temp->next;
					curr += 1;
				}
				temp->next = NULL;
				size -= 1;
			}
		}
		
		void peek(){
			if (size == 0){
				cout << "nothing to show!" << endl;
			}
			else{
				int curr = 0;
				Node *temp = head;
				while (curr != size){
					temp = temp->next;
					curr += 1;
				}
				cout << "Showing top element: " << temp->data << endl;
			}
		}
		
		void displayStack(){
			if (size == 0){
				cout << "nothing to show!" << endl;
			}
			else{
				int curr = 0;
				Node *temp = head;
				while (curr != size){
					temp = temp->next;
					curr += 1;
					cout  << temp->data << " " << endl;
				}
			}
		}
};

int main(){
	Singly s = Singly(3);
	Node *n = new Node(4);
	s.push(n);
}
