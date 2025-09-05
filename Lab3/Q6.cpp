#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* child;

    Node(int val){
        data = val;
        next = nullptr;
        child = nullptr;
    }
};

class MultiList{
public:
    Node* head;

    MultiList(){
        head = nullptr;
    }

    void insertEnd(int val){
        Node* temp = new Node(val);
        if (head == nullptr){
            head = temp;
        }
        else{
            Node* p = head;
            while (p->next != nullptr){
                p = p->next;
            }
            p->next = temp;
        }
    }

    Node* flatten(Node* head){
        if (head == nullptr) return nullptr;

        Node* curr = head;
        while (curr != nullptr){
            if (curr->child != nullptr){
                Node* childHead = flatten(curr->child);

                Node* nextNode = curr->next;
                curr->next = childHead;

                Node* temp = childHead;
                while (temp->next != nullptr){
                    temp = temp->next;
                }
                temp->next = nextNode;

                curr->child = nullptr;
            }
            curr = curr->next;
        }
        return head;
    }

    void display(Node* head){
        Node* p = head;
        while (p != nullptr){
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
};

int main(){
    MultiList list;
    list.insertEnd(1);
    list.insertEnd(2);
    list.insertEnd(3);

    Node* node2 = list.head->next;
    node2->child = new Node(4);
    node2->child->next = new Node(5);

    Node* flat = list.flatten(list.head);

    cout << "Flattened list: ";
    list.display(flat);

    return 0;
}
