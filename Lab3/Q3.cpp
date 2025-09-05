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
		int l;
		
		Singly(){
			head = nullptr;
			tail = nullptr;
			l = 0;
		}
		
		void push(int v){
			Node *newNode = new Node(v);
			if (head == nullptr && tail == nullptr){
				head = tail = newNode;
				l++;
				return;
			}
			
			tail->nxt = newNode;
			tail = newNode;
			l++;
		}
		
		void specificRev(int k){
			if (head == nullptr){
                return;
            }
            
            if (k <= 1){
                return;
            }
            
            Node *curr = head;
            Node *prevTail = nullptr;
            Node *newHead = nullptr;
            
            while (curr != nullptr){
            	
                Node *check = curr;
                int count = 0;
                while (count < k && check != nullptr){
                    check = check->nxt;
                    count++;
                }
                if (count < k) {
                    break;
                }
                
                Node *prev = nullptr;
                Node *start = curr;
                
                int i = 0;
                while (i < k) {
                    Node *next = curr->nxt;
                    curr->nxt = prev;
                    prev = curr;
                    curr = next;
                    i++;
                }
                
                if (newHead == nullptr) {
                    newHead = prev;
                }
                else {
                    prevTail->nxt = prev;
                }
                
                prevTail = start;
            }
            
            if (prevTail != nullptr) {
                prevTail->nxt = curr;
            }
            if (newHead != nullptr) {
                head = newHead;
            }
		}
		
		void print() {
	        Node *curr = head;
	        while (curr != nullptr) {
	            cout << curr->value << ", ";
	            curr = curr->nxt;
	        }
	        cout << "NULL" << endl;
	    }
};

int main(){
	Singly ll1;
    ll1.push(5);
    ll1.push(1);
    ll1.push(9);
	ll1.push(1);
	ll1.push(2);
	ll1.push(3);
	
	ll1.specificRev(3);
	
	ll1.print();
}
