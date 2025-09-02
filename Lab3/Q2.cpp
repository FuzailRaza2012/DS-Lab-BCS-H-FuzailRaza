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
		
		void merge(Singly *sl){
			if (head == nullptr){
				cout << "abay kuch daal tou day" << endl;
				return;
			}
			else{
				tail->nxt = sl->head;
				tail = sl->tail;
				l += sl->l;
			}
			
			sl->head = sl->tail = nullptr;
			sl->l = 0;
			
			Bubbly();
		}
		
		void Bubbly(){
		    if (head == nullptr || head->nxt == nullptr){
		    	cout << "Nothing there" << endl;
		    	return;
			}
		
		    for (int i = 0; i < l - 1; i++){
		        Node *curr = head;
		        Node *next = head->nxt;
		
		        for (int j = 0; j < l - 1 - i; j++){
		            if (curr->value > next->value){
		                int temp = curr->value;
		                curr->value = next->value;
		                next->value = temp;
		            }
		            curr = next;
		            next = next->nxt;
		        }
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

    Singly ll2;
    ll2.push(7);
    ll2.push(3);
    ll2.push(2);

    cout << "L1 before Merging: ";
    ll1.print();
    cout << "L2 before Merging: ";
    ll2.print();

    ll1.merge(&ll2);

    cout << "After Merging and Sorting: ";
    ll1.print();
}
