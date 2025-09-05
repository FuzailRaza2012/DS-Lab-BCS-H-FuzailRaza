#include <iostream>
using namespace std;

class SNode{
public:
    int data;
    SNode* next;
    SNode(int val){
        data = val;
        next = NULL;
    }
};

class DNode{
public:
    int data;
    DNode* next;
    DNode* prev;
    DNode(int val){
        data = val;
        next = NULL;
        prev = NULL;
    }
};

class SinglyList{
private:
    SNode* head;

public:
    SinglyList(){
        head = NULL;
    }

    void insertEnd(int val){
        SNode* temp = new SNode(val);
        if (head == NULL){
            head = temp;
        }
        else{
            SNode* p = head;
            while (p->next != NULL){
                p = p->next;
            }
            p->next = temp;
        }
    }

    DNode* toDoubly(){
        if (head == NULL) return NULL;

        SNode* p = head;
        DNode* dhead = new DNode(p->data);
        DNode* dcurr = dhead;
        p = p->next;

        while (p != NULL){
            DNode* temp = new DNode(p->data);
            dcurr->next = temp;
            temp->prev = dcurr;
            dcurr = temp;
            p = p->next;
        }
        return dhead;
    }

    SNode* toCircular(){
        if (head == NULL) return NULL;

        SNode* p = head;
        while (p->next != NULL){
            p = p->next;
        }
        p->next = head;
        return head;
    }

    void display(){
        SNode* p = head;
        while (p != NULL){
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
};

void displayDoubly(DNode* head){
    DNode* p = head;
    while (p != NULL){
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void displayCircular(SNode* head, int count){
    SNode* p = head;
    for (int i = 0; i < count; i++){
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main(){
    SinglyList list;
    list.insertEnd(10);
    list.insertEnd(20);
    list.insertEnd(30);
    list.insertEnd(40);

    cout << "Original Singly List: ";
    list.display();

    DNode* dlist = list.toDoubly();
    cout << "Converted Doubly List: ";
    displayDoubly(dlist);

    SNode* clist = list.toCircular();
    cout << "Converted Circular List: ";
    displayCircular(clist, 8);

    return 0;
}
