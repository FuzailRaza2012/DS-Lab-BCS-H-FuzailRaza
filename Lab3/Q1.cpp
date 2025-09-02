#include <iostream>
#include <string>

using namespace std;

class Node{
	public:
		Node *nxt;
		int value;	
		
		Node(int v){
			value = v;
			nxt = nullptr;
		}
		
};

class Singly{
	public:
		Node *head;
		Node *tail;
		int length;
		
		Singly(){
			head = nullptr;
			tail = nullptr;
			length = 0;
		}
		
		void pushInside(int v){
			if (head == nullptr && tail == nullptr){
				Node *newNode = new Node(v);
				head = tail = newNode;
				length++;
				return;
			}
				
			Node *newNode = new Node(v);
				
			tail->nxt = newNode;
			tail = newNode;
			
			length++;
			
		}
		
		bool isPal(){
			int *arr = new int[length];
			
			Node *curr = nullptr;
			curr = head;
			
			int a = 0;
			
			while (curr != nullptr){
				arr[a++] = curr->value;
				curr = curr->nxt;
			}
			
			int mid = length / 2;
			
			for (int i = 0; i < mid; i++){
				if (arr[i] != arr[length - i - 1]){
					delete[] arr;
					return false;
				}
			}
			
			delete[] arr;
			return true;
		}
};

int main(){
	Singly ll;
    ll.pushInside(1);
    ll.pushInside(2);
    ll.pushInside(1);

    if (ll.isPal())
        cout << "This list is a Palindrome" << endl;
    else
        cout << "This list is NOT a Palindrome" << endl;
	
	return 0;
}
